#include "Engine/Vfx/Common/Io/Printer.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

void Printer::func_004152C0(u8 arg0) {
    unk_04 = arg0;
}

void Printer::func_004152D0(u8 arg0) {
    unk_05 = arg0;
}

void Printer::func_004152E0(u8 level) {
    if (level > 100) {
        level = 100;
    }
    levels[levelIndex] = level;
}

u8 Printer::func_00415300() {
    return levels[levelIndex];
}

bool Printer::func_00415310() {
    s32 index = levelIndex + 1;
    if (index < 16) {
        levelIndex = index;
        levels[index] = 100;
        return true;
    }
    return false;
}

void Printer::func_00415330() {
    if (levelIndex > 0) {
        levelIndex--;
    }
}

s32 Printer::func_00415340() {
    return rings[4].count;
}

s32 Printer::func_00415350(u8 ring) {
    if (ring >= 5) {
        ring = 4;
    }
    return rings[ring].count;
}

const char* Printer::func_00415370(s32 index) {
    if (rings[4].count <= index) {
        return 0;
    }
    return rings[4].text + (rings[4].head + index) % rings[4].capacity * lineSize;
}

const char* Printer::func_004153A0(u8 ring, s32 index) {
    if (ring >= 5) {
        ring = 4;
    }
    Ring& selected = rings[ring];
    if (selected.count <= index) {
        return 0;
    }
    return selected.text + (selected.head + index) % selected.capacity * lineSize;
}

void Printer::func_004153E0() {
    if (indent < 15) {
        indent++;
    }
}

void Printer::func_00415400() {
    if (indent > 0) {
        indent--;
    }
}

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

