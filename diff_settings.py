import json
from pathlib import Path

from splat.util.coff import CoffObject


def apply(config, args):
    config.update(
        arch="i686",
        baseimg="versions/1.23b/ffxivgame.exe",
        myimg="build/ffxivgame.exe",
        mapfile="build/ffxivgame.map",
        objdump_executable="objdump",
        make_command=["ninja"],
        source_directories=["src", "include"],
    )
    if args.diff_obj:
        if not args.file:
            matches = []
            for unit in json.loads(Path("objdiff.json").read_text())["units"]:
                coff = CoffObject.parse(Path(unit["target_path"]).read_bytes())
                if any(symbol.name == args.start and symbol.section > 0 for symbol in coff.symbols.values()):
                    matches.append(unit["base_path"])
            if len(matches) > 1:
                raise ValueError("Function exists in multiple objects; use -f")
            if matches:
                args.file = matches[0]
        if args.file and not args.ref_file:
            args.ref_file = str(Path("build/expected") / Path(args.file).relative_to("build"))
    else:
        config["objdump_flags"] = ["--adjust-vma=0x400000"]
        for line in Path(config["mapfile"]).read_text().splitlines():
            fields = line.split()
            if len(fields) == 2 and fields[1] in (args.start, args.start.removeprefix("_")):
                args.start = fields[0]
                break
