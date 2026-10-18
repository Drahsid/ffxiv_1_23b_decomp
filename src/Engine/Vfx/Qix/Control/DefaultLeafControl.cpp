#include "Engine/Vfx/Qix/Control/DefaultLeafControl.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "Engine/Common/Log.h"
#include "asm.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Control {

extern "C" const s32 D_010C70C0[3];

DefaultLeafControl::~DefaultLeafControl() {
    func_004162C0(unk_10);
}

extern "C" s32 func_00BD1C90(s32 arg0) {
    if (arg0 >= 0) {
        return -1;
    }
    
    s32 index = ~arg0;
    if (index >= 3) {
        return -1;
    }
    return D_010C70C0[index];
}

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Control/DefaultLeafControl/00BD1CB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Control/DefaultLeafControl/00BD1D70.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Control/DefaultLeafControl/00BD1E20.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Control/DefaultLeafControl/00BD1EB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Control/DefaultLeafControl/00BD1FF0.s");


} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
