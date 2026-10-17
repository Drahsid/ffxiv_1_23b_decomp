#include "asm.h"
#include "Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool.h"
#include "Engine/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {
namespace D3d9 {
namespace Rapture {

bool MemoryPool::func_00417680() {
    return memoryPools_.size() != 0;
}

void MemoryPool::func_004176B0() {
    pUsedPool_ = &memoryPools_[0];
    usedSize = 0;
}

u32 MemoryPool::func_004176E0() {
    u32 total = 0;
    u32 count = memoryPools_.size();
    for (u32 index = 0; index < count; index++) {
        if (&memoryPools_[index] == pUsedPool_) {
            total += usedSize;
            break;
        }
        total += memoryPools_[index].size;
    }
    return total;
}

} // namespace Rapture
} // namespace D3d9
} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417760.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417820.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/004178A0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/004178C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417970.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417A70.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417AB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417AE0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417B50.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417BB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417E20.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417F30.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool/00417FC0.s");
