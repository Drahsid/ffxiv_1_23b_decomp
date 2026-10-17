#ifndef ENGINE_VFX_COMMON_IO_FILE_H
#define ENGINE_VFX_COMMON_IO_FILE_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

class File {
public:
    File();

    u8 func_004165B0(const char* path, s32 arg1);
    u8 func_004165C0();
    u8 func_004165D0(u32 arg0, u32 arg1);
    u8 func_004165E0(const char* text, s32 arg1);
    void func_00416650();

private:
    u32 unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07[0x101];
};

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
