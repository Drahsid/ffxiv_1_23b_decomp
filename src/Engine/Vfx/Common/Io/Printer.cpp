#include "Engine/Vfx/Common/Io/Printer.h"
#include "Engine/Vfx/Common/Io/File.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include <stdarg.h>
#include <string.h>
#include "Engine/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

static const char* sIndents[16] = {
    "",
    "  ",
    "    ",
    "      ",
    "        ",
    "          ",
    "            ",
    "              ",
    "                ",
    "                  ",
    "                    ",
    "                      ",
    "                        ",
    "                          ",
    "                            ",
    "                              ",
};

static const s32 sRingRatios[5] = {1, 2, 3, 4, 6};

static Printer* sInstance;

void Printer::func_00415440(s32 type, u8 ring, const char* text) {
    s32 length = strlen(text);
    if (length > 0) {
        Ring& selected = rings[ring];
        s32 index = selected.head;
        if (selected.count < selected.capacity) {
            index += selected.count;
            selected.count++;
        }
        else {
            selected.head = (index + 1) % selected.capacity;
        }

        char* line = selected.text + lineSize * index;
        if (lineSize - 2 <= length) {
            length = lineSize - 2;
        }

        memcpy(line, text, length);

        if (line[length - 1] != '\n') {
            line[length] = '\n';
            line[length + 1] = 0;
        }
        else {
            line[length] = 0;
        }

        Entry& entry = selected.entries[index];
        entry.type = type;
        entry.unk_04 = ring;
    }
}

void Printer::func_004154F0(char* buffer, s32 size, s32 type, s32 level, const char* text, bool newline) {
    switch (type) {
    case 0:
        _snprintf_s(buffer, size, size - 1, "%s[vfx] %s", sIndents[indent], text);
        break;
    case 1:
        _snprintf_s(buffer, size, size - 1, "%s[vfx.w%d] %s", sIndents[indent], level, text);
        break;
    case 2:
        _snprintf_s(buffer, size, size - 1, "%s[vfx.assert] %s", sIndents[indent], text);
        break;
    default:
        _snprintf_s(buffer, size, size - 1, "%s[vfx] %s", sIndents[indent], text);
        break;
    }

    if ((type <= 0 || type > 2) && newline) {
        s32 length = strlen(buffer);
        if (size - 2 <= length) {
            length = size - 2;
        }
        if (buffer[length - 1] != '\n') {
            buffer[length] = '\n';
            buffer[length + 1] = 0;
        }
    }
}

void Printer::func_00415620(u8 level, const char* text) {
    if (file && fileLevel >= level) {
        file->func_004165E0(text, 1);
    }
}

void Printer::func_00415650(s32 type, u8 level, const char* text) {
    char line[1024];
    if (unk_05 && levels[levelIndex] >= level) {
        func_004154F0(line, sizeof(line), type, level, text, false);
        if (level >= 5) {
            level = 4;
        }

        for (s32 index = level; index < 5; index++) {
            func_00415440(type, index, line);
        }
    }
}

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

#include "Engine/Common/Assert.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

void Printer::func_00415790() {
    File* current = file;
    if (current) {
        current->func_00416650();
        func_004162C0(current);
        file = 0;
    }
}

void Printer::func_004157C0(const char* text, bool newline) {
    char line[1024];
    const char* output = text;
    if (newline) {
        s32 length = strlen(text);
        if (length >= 1022) {
            length = 1022;
        }

        if (text[length - 1] != '\n') {
            memcpy(line, text, length);
            line[length] = '\n';
            line[length + 1] = 0;
            output = line;
        }
    }

    LOG_PRINT(output);
}

void Printer::func_00415860() {
    if (text) {
        func_004162C0(text);
        func_004162C0(entries);
        text = 0;
    }
    entries = 0;
    func_00415790();
}

bool Printer::SetLimit(s32 line_size, s32 line_count) {
    if (!line_size || !line_count) {
        return false;
    }

    s32 unit = line_count / 16;
    if (!unit) {
        return false;
    }

    func_00415860();
    lineSize = line_size;
    s32 size = line_size * line_count;
    text = static_cast<char*>(func_00416480(size, 9, 16, __FUNCTION__, ".\\Io\\Printer.cpp", 192));
    memset(text, 0, size);
    entries = static_cast<Entry*>(func_00416480(line_count * sizeof(Entry), 9, 16, __FUNCTION__, ".\\Io\\Printer.cpp", 195));
    s32 offset = 0;
    for (s32 index = 0; index < 5; index++) {
        Ring& ring = rings[index];
        ring.head = 0;
        ring.count = 0;
        ring.capacity = unit * sRingRatios[index];
        ring.text = text + offset * unit * line_size;
        ring.entries = entries + offset * unit;
        offset += sRingRatios[index];
    }
    return true;
}

void Printer::func_00415A00(u8 level) {
    char message[1024];
    _snprintf_s(
        message,
        sizeof(message),
        sizeof(message) - 1,
        "[vfx] print all level(0 - %d) start. --------------------------------\n",
        level
    );

    func_004157C0(message, true);

    if (level >= 5) {
        level = 4;
    }

    Ring& ring = rings[level];
    s32 head = ring.head;
    for (s32 index = 0; index < ring.count; index++) {
        func_004157C0(ring.text + (index + head) % ring.capacity * lineSize, true);
    }

    LOG_PRINT("[vfx] print all end. -------------------------------------------------\n");
}

void Printer::func_00415AD0(const char* directory, const char* name, u8 level) {
    char path[512];
    func_00415790();
    _snprintf_s(path, sizeof(path), sizeof(path) - 1, "%s/%s", directory, name);
    file = new (0x48, 16, 0, 0, 0) File;
    file->func_004165B0(path, 6);
    fileLevel = level;
}

void Printer::func_00415BB0(const char* format, ...) {
    char message[1024];
    va_list args;
    va_start(args, format);
    _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
    func_004157C0(message, true);
}

Printer::Printer(s32 line_size, s32 line_count) {
    unk_04 = true;
    unk_05 = true;
    text = 0;
    entries = 0;
    lineSize = 0;
    levelIndex = 0;
    levels[0] = 0;
    file = 0;
    fileLevel = 0;
    indent = 0;
    SetLimit(line_size, line_count);
}

Printer::~Printer() {
    func_00415860();
    sInstance = 0;
}

Printer* Printer::func_00415C90() {
    static u8 storage[sizeof(Printer)];
    if (!sInstance) {
        sInstance = new (storage) Printer(128, 512);
    }
    return sInstance;
}

void Printer::func_00415CE0() {
    if (sInstance) {
        sInstance->func_00415860();
    }
}

void Printer::func_00415CF0() {
    func_00415A00(101);
}

void Printer::Run_(s32 type, u8 level, const char* text, bool newline) {
    char message[1024];
    if (type == 1 && levels[levelIndex] < level) {
        return;
    }

    func_004154F0(message, sizeof(message), type, level, text, newline);
    
    switch (type) {
    case 0:
        LOG_PRINT(message);
        break;
    case 1:
        LOG_ERROR(message);
        func_00415620(level, message);
        break;
    case 2:
        LOG_ERROR(message);
        if (file) {
            file->func_004165E0(message, 1);
        }
        LOG_ASSERTION_AT(".\\Io\\Printer.cpp", 535, false, "");
        break;
    default:
        LOG_ASSERTION_AT(".\\Io\\Printer.cpp", 538, false, "");
        break;
    }
}

void func_00415EC0(Printer* printer, const char* format, ...) {
    char message[1024];
    char line[1024];
    if (printer->unk_04) {
        va_list args;
        va_start(args, format);
        _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
        printer->func_004154F0(line, sizeof(line), 0, 0, message, false);
        LOG_PRINT(line);
    }
}

void func_00415F70(Printer* printer, const char* format, ...) {
    char message[1024];
    char line[1024];
    if (printer->unk_04) {
        va_list args;
        va_start(args, format);
        _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
        printer->func_004154F0(line, sizeof(line), 0, 0, message, true);
        LOG_PRINT(line);
    }
}

void func_00416060(Printer* printer, const char* format, ...) {
    char message[1024];
    if (printer->unk_04 && printer->levels[printer->levelIndex] >= 100) {
        va_list args;
        va_start(args, format);
        _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
        printer->func_00415650(1, 100, message);
        printer->Run_(1, 100, message, true);
    }
}

void func_004160E0(Printer* printer, u8 level, const char* format, ...) {
    char message[1024];
    if (printer->unk_04 && printer->levels[printer->levelIndex] >= level) {
        va_list args;
        va_start(args, format);
        _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
        printer->func_00415650(1, level, message);
        printer->Run_(1, level, message, true);
    }
}

void func_00416160(Printer* printer, const char* format, ...) {
    char message[1024];
    char text[1032];
    va_list args;
    va_start(args, format);
    _vsnprintf_s(message, sizeof(message), sizeof(message) - 1, format, args);
    // BUG: Prints uninitialized text instead of the formatted message
    printer->func_00415650(2, 0, text);
    printer->Run_(2, 0, text, true);
}

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
