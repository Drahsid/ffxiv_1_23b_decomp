# FINAL FANTASY XIV 1.23b

An experimental matching decompilation of the FINAL FANTASY XIV 1.23b game client, version `2012.09.19.0001`.

## Building
This build uses Windows and [MSYS2](https://www.msys2.org/).

### Windows Dependencies
Install Python 3.12+, Git, [Ninja](https://ninja-build.org/), [7z](https://www.7-zip.org/), and [MSYS2](https://www.msys2.org/):

```powershell
winget install -e --id Python.Python.3
winget install -e --id Git.Git --source winget
winget install -e --id Ninja-build.Ninja
winget install -e --id 7zip.7zip
winget install -e --id MSYS2.MSYS2
```

In MSYS2, update and install GNU binutils and Perl:
```sh
pacman -Syu
pacman -S --needed binutils perl
```

When working on this project, add MSYS2 to your user PATH (for example: `C:\msys64\usr\bin`.)

### Clone the repository
Clone `https://github.com/Drahsid/ffxiv_1_23b_decomp.git` in whatever directory you wish.

```
git clone --recurse-submodules https://github.com/Drahsid/ffxiv_1_23b_decomp.git
```

For an existing checkout, synchronize and initialize the submodules before building:
```
git submodule sync --recursive
git submodule update --init --recursive
```

### Install Python requirements
Create and activate the project venv, then install its requirements:

```bat
py -m venv .venv
.\.venv\Scripts\activate.bat
python -m pip install --upgrade pip
python -m pip install -r requirements.txt
```

Run `configure.py` through this venv Python.

### Prepare the binary
Copy `ffxivgame.exe` from the 1.23b client into `versions/1.23b/`. Its SHA1 must match `04fd1c65eb0ab2e5d37d814dac1298ae2940e86a`.

Download the CRT and directx libraries, then build with the included Visual C++ 2005 compiler:
```
python configure.py --setup
```

To extract, disassemble, generate the build script, and build the executable:
```
python configure.py --split --build
```

## Build the executable
Run `python configure.py --build`. This builds native objects and libraries, runs splat, then assembles, links, and checks `build/ffxivgame.exe` against the original. A matching build prints:
```
build/ffxivgame.exe: OK
```

## Other configure options
Use the venv Python for configure commands:
```
python configure.py --clean
python configure.py --fullclean
python configure.py --split
```

## Diffing
A successful build generates `objdiff.json` and reference objects for objdiff and asm-differ (`diff_settings.py`).

## Contributing
If you would like to contribute, open a PR with your changes (ideally at the scale of individual TUs, or related TUs).

### Formatting
Minorly modified Stroustrup style:

Indent with 4 spaces. Braces stay on the same line. `else` and `else if` go on a new line.

Pointers bind left: `u8* data`.

If you use vscode, the included `.vscode` folder supplies an IntelliSense profile.

### Nonmatching Code
Wrap any nonmatching code in `NON_MATCHING` blocks:

```cpp
#ifdef NON_MATCHING
// I tried X/Y/Z
void function() {
    // nonmatching function body...
}
#else
INCLUDE_ASM("asm/nonmatchings/path/function.s");
#endif
```

## Compiler and libraries

Compiler and library flags are in `rules.ninja`, TU overrides are in `configure.py`.

| Library | Source/version |
| --- | --- |
| Game compiler | Visual C++ 2005 SP1, `14.00.50727.762` |
| zlib | 1.2.3, `abf180a` |
| OpenSSL | 1.0.0, `91bad2b` |
| Lua | 5.1.4, `0a6d2ee` |
| CRT | VC2005 SP1 KB971090, `8.0.50727.4053` |
| DirectX | March 2009 SDK, `9.26.1590` |

