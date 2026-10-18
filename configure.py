#!/usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
import urllib.request
import zipfile
from pathlib import Path

import ninja_syntax
from splat.platforms import win32
from splat.scripts import split
from splat.segtypes.linker_entry import path_to_object_path, write_file_if_different
from splat.segtypes.win32.cpp import assembly_includes
from splat.util import conf
from splat.util.coff import CoffObject, LNK_REMOVE

from tools.expected import write_diff_config, write_expected

ROOT = Path(__file__).resolve().parent
YAML = Path("versions/1.23b/ffxivgame.yaml")
TARGET = YAML.with_suffix(".exe")
LIBRARY_DIR = Path("build/third_party")
OPENSSL_DIR = Path("third_party/openssl")
COMPILER_INPUTS = [
    path.relative_to(ROOT).as_posix() for path in sorted((ROOT / "tools/msvc8.0sp1/bin").rglob("*")) if path.is_file()
]

TU_FLAGS = {
    "Engine": "/GS-",
    "Engine/Dw/RenderInterface": "/Gy /GS /GF-",
    "Engine/Dw/Renderer": "/Gy /GS",
    "Engine/Vfx/Qix/Data/UnitInstance_Data": "/Gy /GS-",
    "Engine/Vfx/Qix/Graph": "/Gy /GS-",
    "Engine/Vfx/Qix/Graph/BaseGenesisBuffer": "/GS- /EHc-",
    "Sqex/Socket": "/GS /GF-",
}

TU_FLAGS_DEFAULT = "/GS"

PCH = {
    flags: Path("build/pch") / ("new" + flags.replace("/", "_").replace(" ", "") + ".pch")
    for flags in sorted(set(TU_FLAGS.values()) | {"/GS"})
}


def setup():
    with tempfile.TemporaryDirectory() as temporary:
        temporary = Path(temporary)
        installer = temporary / "kb971090.exe"
        urllib.request.urlretrieve("https://download.microsoft.com/download/d/2/3/d23f9f62-3dee-4ec0-b3b9-d64e9f573d1f/VS80sp1-KB971090-X86-INTL.exe", installer)
        libraries = {
            name: f"FL_{name.replace('.', '_')}_____X86.3643236F_FC70_11D3_A536_0090278A1BB8"
            for name in ("libcmt.lib", "libcpmt.lib")
        }

        patch = temporary / "VS80sp1-KB971090-X86-INTL.msp"
        cabinet = temporary / "PCW_CAB_VS_10837"

        for archive, members in ((installer, [patch.name]), (patch, [cabinet.name]), (cabinet, list(libraries.values()))):
            subprocess.run(["7z", "e", "-y", f"-o{temporary}", archive, *members], check=True, stdout=subprocess.DEVNULL)

        crt = Path("third_party/crt")
        crt.mkdir(exist_ok=True)

        for name, member in libraries.items():
            shutil.copy2(temporary / member, crt / name)

        package = temporary / "dxsdk.nupkg"
        urllib.request.urlretrieve("https://www.nuget.org/api/v2/package/DXSDK_March09_x86/9.26.1590", package)
        dxsdk = Path("third_party/dxsdk")
        dxsdk.mkdir(exist_ok=True)
        with zipfile.ZipFile(package) as archive:
            for name in archive.namelist():
                if name.lower().endswith((".h", ".inl", ".lib")):
                    (dxsdk / Path(name).name).write_bytes(archive.read(name))


def clean(full):
    for directory in ("asm", "assets", "build"):
        if Path(directory).exists():
            shutil.rmtree(directory)

    Path(".splache").unlink(missing_ok=True)

    if full:
        for name in ("build.ninja", "objdiff.json", ".ninja_log", ".ninja_deps"):
            Path(name).unlink(missing_ok=True)


def configure_openssl():
    include = LIBRARY_DIR / "openssl/include"
    subprocess.run(["perl", "Configure", "VC-WIN32"], cwd=OPENSSL_DIR, check=True, stdout=subprocess.DEVNULL)
    (OPENSSL_DIR / "crypto/buildinf.h").unlink()
    info = subprocess.check_output(["perl", "util/mkfiles.pl"], cwd=OPENSSL_DIR, text=True)
    directories = {}
    for block in info.split("RELATIVE_DIRECTORY=")[1:]:
        directory, variables = block.split("\n", 1)
        directories[directory] = dict(line.split("=", 1) for line in variables.splitlines())

    sources = []
    for directory in [".", "crypto"] + [f"crypto/{name}" for name in directories["."]["SDIRS"].split()]:
        variables = directories[directory]
        source_dir = OPENSSL_DIR / directory
        for key, destination in (("EXHEADER", include / "openssl"), ("HEADER", include)):
            for name in variables.get(key, "").split():
                data = b"" if name == "buildinf.h" else (source_dir / name).read_bytes()
                write_file_if_different(destination / name, data)

        for name in variables.get("LIBOBJ", "").split():
            stem = name.removesuffix(".o")
            candidates = (source_dir / f"{stem}.c", source_dir / f"asm/{stem}.pl", source_dir / f"{stem}.pl")
            sources.append(next(path for path in candidates if path.is_file()))

    return sources


def write_library(ninja, library, sources, flags, entries):
    members = {entry.segment.object for entry in entries if entry.segment.type == "lib" and entry.segment.library == library}
    objects = []
    for source in sources:
        member = source.with_suffix(".obj").name
        if member not in members:
            continue

        target = source if source.suffix == ".obj" else library.parent / member
        if source.suffix == ".pl":
            helpers = set((OPENSSL_DIR / "crypto/perlasm").glob("*.pl")) | set(source.parent.rglob("*.pl"))
            assembly = target.with_suffix(".asm").as_posix()
            ninja.build(assembly, "perlasm", source.as_posix(), implicit=[helper.as_posix() for helper in sorted(helpers - {source})])
            ninja.build(target.as_posix(), "ml", assembly, implicit=COMPILER_INPUTS)
        elif source.suffix == ".c":
            variables = {"flags": flags, "source": source.as_posix()}
            if source.is_relative_to(OPENSSL_DIR):
                # Preserve OpenSSL's __FILE__ strings
                variables.update(directory=OPENSSL_DIR.as_posix(), source=".\\" + str(source.relative_to(OPENSSL_DIR)))
            ninja.build(target.as_posix(), "cc", source.as_posix(), implicit=COMPILER_INPUTS, variables=variables)
        objects.append(target.as_posix())
    ninja.build(library.as_posix(), "lib", objects, implicit=COMPILER_INPUTS)


def get_tu_flags(unit):
    for path in (unit, *unit.parents):
        if path.as_posix() in TU_FLAGS:
            return TU_FLAGS[path.as_posix()]
    return TU_FLAGS_DEFAULT


def write_objects(ninja, entries):
    objects = [entry.object_path.as_posix() for entry in entries]
    compile_targets = set()
    for entry in entries:
        path = entry.object_path
        source = entry.src_paths[0]
        segment = entry.segment
        if source.suffix in (".s", ".bin"):
            ninja.build(path.as_posix(), "as" if source.suffix == ".s" else "bin", source.as_posix())
        elif segment.type == "lib":
            if segment.library.is_relative_to(LIBRARY_DIR):
                compile_targets.add(segment.library.as_posix())
        else:
            compiled = path.with_suffix(".obj")
            flags = get_tu_flags(segment.dir / segment.name)

            ninja.build(
                compiled.as_posix(), "cc", source.as_posix(), implicit=COMPILER_INPUTS + [PCH[flags].as_posix()],
                variables={"flags": f"$game_flags {flags} /Yunew /FInew /Fp{PCH[flags]}", "source": source.as_posix()},
            )

            for assembly in assembly_includes(source):
                output = path_to_object_path(assembly).as_posix()
                ninja.build(output, "as", assembly.as_posix())
                objects.append(output)
            compile_targets.add(compiled.as_posix())
    return objects, sorted(compile_targets)


def write_build_script(entries):
    with Path("build.ninja").open("w", encoding="utf-8") as script:
        ninja = ninja_syntax.Writer(script, width=120)
        ninja.variable("root", ROOT.as_posix())
        ninja.include("rules.ninja")
        for flags, pch in PCH.items():
            ninja.build(
                pch.with_suffix(".obj").as_posix(), "cc", "src/pch.cpp", implicit=COMPILER_INPUTS,
                implicit_outputs=[pch.as_posix()],
                variables={"source": "src/pch.cpp", "flags": f"$game_flags {flags} /Ycnew /Fp{pch}"},
            )

        objects, compile_targets = write_objects(ninja, entries)
        zlib = Path("third_party/zlib")
        zlib_sources = sorted(zlib.glob("*.c")) + [
            zlib / "contrib/masmx86/gvmat32c.c",
            zlib / "contrib/masmx86/gvmat32.obj",
            zlib / "contrib/masmx86/inffas32.obj",
        ]
        write_library(ninja, LIBRARY_DIR / "zlib/zlibstat.lib", zlib_sources, "$zlib_flags", entries)
        write_library(ninja, LIBRARY_DIR / "lua/lua.lib", sorted(Path("third_party/lua/src").glob("*.c")), "$lua_flags", entries)
        write_library(ninja, LIBRARY_DIR / "openssl/libeay32.lib", configure_openssl(), "$openssl_flags", entries)

        ninja.build(
            "build/ffxivgame.pe", "ld", implicit=["build/ffxivgame.ld"] + objects,
            implicit_outputs=["build/ffxivgame.map"],
        )
        ninja.default("build/ffxivgame.pe")
    return compile_targets


def configure():
    config = conf.load([YAML], modes=[])
    split.initialize_platform(TARGET.read_bytes())
    segments = split.initialize_segments(config["segments"])
    entries = [entry for segment in segments for entry in segment.get_linker_entries()]
    if any(entry.segment.type in ("c", "cpp") and not entry.src_paths[0].exists() for entry in entries):
        split.main([YAML], modes=["all"], verbose=False, use_cache=False)
        entries = split.linker_writer.entries
    entries = [entry for entry in entries if entry.object_path is not None and not entry.segment.type.startswith(".")]
    compile_targets = write_build_script(entries)
    units = [entry for entry in entries if entry.segment.type in ("c", "cpp")]
    write_diff_config(units)
    return units, compile_targets


def report_progress():
    matched = 0
    objects = {Path(line[5:]) for line in Path("build/ffxivgame.map").read_text().splitlines() if line.startswith("LOAD ")}
    for path in objects:
        if path.is_relative_to("build/src") or path.is_relative_to("build/lib"):
            coff = CoffObject.parse(path.read_bytes())
            matched += sum(section.size for section in coff.sections if section.code and not section.flags & LNK_REMOVE)
    total = sum(section.virtual_size for section in win32.info.sections if section.is_code)
    print(f"Text: {matched:,} / {total:,} bytes ({100 * matched / total:.4f}%)")


if __name__ == "__main__":
    os.chdir(ROOT)
    parser = argparse.ArgumentParser(description="Configure the build")
    parser.add_argument("-c", "--clean", action="store_true")
    parser.add_argument("-f", "--fullclean", action="store_true")
    parser.add_argument("-i", "--setup", action="store_true")
    parser.add_argument("-s", "--split", action="store_true")
    parser.add_argument("-b", "--build", action="store_true")
    args = parser.parse_args()

    if args.clean or args.fullclean:
        clean(args.fullclean)
    if args.setup:
        setup()
    if args.split or args.build or not any(vars(args).values()):
        units, compile_targets = configure()
    if args.split or args.build:
        if compile_targets:
            subprocess.run(["ninja", *compile_targets], check=True)
        split.main([YAML], modes=["all"], verbose=False, use_cache=False)
    if args.build:
        subprocess.run(["ninja"], check=True)
        image = (
            Path("assets/header.bin").read_bytes()
            + Path("build/ffxivgame.pe").read_bytes()[0x1000:]
            + Path("assets/certificate.bin").read_bytes()
        )
        Path("build/ffxivgame.exe").write_bytes(image)
        if image != TARGET.read_bytes():
            sys.exit("build/ffxivgame.exe: FAILED")
        print("build/ffxivgame.exe: OK", flush=True)
        report_progress()
        write_expected(units)
