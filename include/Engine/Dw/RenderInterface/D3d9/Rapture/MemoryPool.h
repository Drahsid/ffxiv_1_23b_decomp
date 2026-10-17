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

    static u32 func_00417640(u32 value, u32 shift);

    bool func_00417680();
    void func_004176B0();
    u32 func_004176E0();

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
