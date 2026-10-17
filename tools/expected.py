import json
import subprocess
from pathlib import Path

from splat.segtypes.linker_entry import path_to_object_path, write_file_if_different
from splat.segtypes.win32.cpp import assembly_includes
from splat.util.coff import CoffObject


def write_diff_config(entries):
    units = []
    for entry in entries:
        compiled = entry.object_path.with_suffix(".obj")
        expected = Path("build/expected") / compiled.relative_to("build")
        units.append({
            "name": (entry.segment.dir / entry.segment.name).as_posix(),
            "target_path": expected.as_posix(),
            "base_path": compiled.as_posix(),
            "metadata": {"source_path": entry.src_paths[0].as_posix()},
        })

    config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "min_version": "3.8.2",
        "custom_make": "ninja",
        "watch_patterns": ["src/**", "include/**"],
        "units": units,
    }
    write_file_if_different(Path("objdiff.json"), json.dumps(config, indent=2) + "\n")


def write_expected(entries):
    for entry in entries:
        compiled = CoffObject.parse(entry.object_path.with_suffix(".obj").read_bytes())
        target = Path("build/expected") / entry.object_path.relative_to("build").with_suffix(".obj")
        sections = {}
        for section in CoffObject.parse(entry.object_path.read_bytes()).sections:
            if section.size and section.name.startswith(".n"):
                name = compiled.sections[section.index - 1].name
                sections.setdefault(name, []).append(f'"{entry.object_path.as_posix()}"({section.name})')

        for assembly in assembly_includes(entry.src_paths[0]):
            path = path_to_object_path(assembly)
            for section in CoffObject.parse(path.read_bytes()).sections:
                if section.size and section.code:
                    sections.setdefault(".text", []).append(f'"{path.as_posix()}"({section.name})')

        script = "SECTIONS {\n"
        for name, contributions in sections.items():
            fill = " =0xCCCCCCCC" if name.startswith(".text") else ""
            script += f'"{name}" : {{ {" ".join(contributions)} }}{fill}\n'
        script += "/DISCARD/ : { *(*) }\n}\n"
        script_path = target.with_suffix(".ld")
        write_file_if_different(script_path, script)
        subprocess.run(
            ["ld", "-m", "i386pe", "-r", "--oformat", "pe-i386", "-T", script_path, "-o", target],
            check=True,
        )
