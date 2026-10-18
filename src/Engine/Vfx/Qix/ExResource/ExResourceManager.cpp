#include "Engine/Vfx/Qix/ExResource/ExResourceManager.h"
#include "Engine/Common/Log.h"
#include "asm.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace ExResource {

void ExResourceManager::func_00BD6750() {
    unk_9C |= 6;
}

void ExResourceManager::func_00BD6760(u64 arg0) {
    unk_9C = (unk_9C & ~0x10) | 8;
    unk_08 = arg0;
}

void ExResourceManager::func_00BD6790(IVfxObject::ResourceUpdateCallback arg0) {
    unk_9C = (unk_9C & ~8) | 0x10;
    unk_7C = arg0;
}

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD67B0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD67C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6850.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6880.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD68C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6940.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD69F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6A30.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6AB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6B60.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6D00.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6E80.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD6F80.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7080.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7150.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7250.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD72E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD72F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7310.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7330.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7350.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD73D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7470.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7550.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7650.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7690.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD76D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD76E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD76F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7720.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7730.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7750.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD77D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7810.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7840.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7870.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7880.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7890.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD78A0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD78B0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD78C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7920.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD79D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7A30.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7A50.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7AD0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7B40.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7BC0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7C40.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7C50.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7C60.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7C80.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7C90.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7CA0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7CB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7CC0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7CD0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7CE0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D00.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D10.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D20.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D30.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D40.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7D50.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7DF0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD7E20.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8140.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8290.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8300.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8340.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8380.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD83F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8410.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8440.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8450.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8490.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8560.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8570.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD85D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD85F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8610.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8670.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8810.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD88C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8970.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8A20.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8AD0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8B80.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8D00.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8D90.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD8ED0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9050.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD90E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD92E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9300.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9320.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9350.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9440.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9480.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9530.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD95A0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9600.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9670.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD96C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9790.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9830.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9850.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9870.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9880.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9890.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9910.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD99B0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/ExResource/ExResourceManager/00BD9A90.s");

} // namespace ExResource
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
