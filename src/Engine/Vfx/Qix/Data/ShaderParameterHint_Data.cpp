#include "Engine/Vfx/Qix/Data/ShaderParameterHint.h"
#include "Engine/Vfx/Common/Log.h"
#include "asm.h"

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

struct ShaderParameterHintSourcePrefix {
    u8 unk_00[0x100];
    u16 unk_100;
};

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Data/ShaderParameterHint_Data/00BE7E90.s");

ShaderParameterHint::ShaderParameterHint(const ShaderParameterHintSourcePrefix* arg0) {
    VFX_ASSERT_AT(".\\Data\\ShaderParameterHint_Data.cpp", 28, (reinterpret_cast<u32>(this) & 15) == 0);
    unk_02 = arg0->unk_100;
    unk_04 = 6;
    unk_00 = unk_02 * 2 + unk_04;
    RebuildTable_Static_(arg0, reinterpret_cast<u16*>(this + 1));
}

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
