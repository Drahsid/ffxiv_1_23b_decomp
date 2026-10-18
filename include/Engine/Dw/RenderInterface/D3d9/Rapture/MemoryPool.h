#ifndef ENGINE_DW_RENDER_INTERFACE_D3D9_RAPTURE_MEMORY_POOL_H
#define ENGINE_DW_RENDER_INTERFACE_D3D9_RAPTURE_MEMORY_POOL_H

#include "Engine/Common/cdev_vector.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {
namespace D3d9 {
namespace Rapture {

class MemoryPool {
public:
    struct Pool {
        u8* memory;
        u32 size;
    };

    static u32 Get_Alignment_Padding(u32 value, u32 shift) {
        u32 negated = ~value + 1;
        return ((negated >> shift) << shift) ^ negated;
    }

    bool Has_Pools();
    void Reset();
    u32 Get_Used_Size();

    void Initialize(u32 size);
    void ChangeUsePool();
    void* Allocate_And_Copy(const void* source, u32 size);
    void* Allocate(u32 size);
    void* Allocate_Aligned_And_Copy(const void* source, u32 size, u32 alignment_shift);
    void* Allocate_Aligned(u32 size, u32 alignment_shift);

    MemoryPool();
    ~MemoryPool();

private:
    cdev_vector<Pool> memoryPools_;
    u32 unk_10;
    Pool* pUsedPool_;
    u32 usedSize;
};

} // namespace Rapture
} // namespace D3d9
} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
