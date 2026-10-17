#ifndef ENGINE_VFX_COMMON_IO_PRINTER_H
#define ENGINE_VFX_COMMON_IO_PRINTER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

class File;

class Printer {
public:
    struct Entry {
        s32 type;
        u8 unk_04;
    };

    struct Ring {
        char* text;
        Entry* entries;
        s32 head;
        s32 count;
        s32 capacity;
    };

    Printer(s32 line_size, s32 line_count);
    virtual ~Printer();

    void func_004152C0(u8 arg0);
    void func_004152D0(u8 arg0);
    void func_004152E0(u8 level);
    u8 func_00415300();
    bool func_00415310();
    void func_00415330();
    s32 func_00415340();
    s32 func_00415350(u8 ring);
    const char* func_00415370(s32 index);
    const char* func_004153A0(u8 ring, s32 index);
    void func_004153E0();
    void func_00415400();

    void func_00415440(s32 type, u8 ring, const char* text);
    void func_004154F0(char* buffer, s32 size, s32 type, s32 level, const char* text, bool newline);
    void func_00415620(u8 level, const char* text);
    void func_00415650(s32 type, u8 level, const char* text);
    void func_00415790();
    static void func_004157C0(const char* text, bool newline);
    void func_00415860();
    bool SetLimit(s32 line_size, s32 line_count);
    void func_00415A00(u8 level);
    void func_00415AD0(const char* directory, const char* name, u8 level);
    static void func_00415BB0(const char* format, ...);
    static Printer* func_00415C90();
    static void func_00415CE0();
    void func_00415CF0();
    void Run_(s32 type, u8 level, const char* text, bool newline);

    u8 unk_04;
    u8 unk_05;
    char* text;
    Entry* entries;
    s32 lineSize;
    Ring rings[5];
    s32 levelIndex;
    File* file;
    u8 indent;
    u8 levels[16];
    u8 fileLevel;
};

void func_00415EC0(Printer* printer, const char* format, ...);
void func_00415F70(Printer* printer, const char* format, ...);
void func_00416060(Printer* printer, const char* format, ...);
void func_004160E0(Printer* printer, u8 level, const char* format, ...);
void func_00416160(Printer* printer, const char* format, ...);

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
