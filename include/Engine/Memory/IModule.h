#ifndef ENGINE_MEMORY_I_MODULE_H
#define ENGINE_MEMORY_I_MODULE_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

class IModule;

struct AllocationParameters {
    IModule* module;
    u32 unk_04;
    u32 allocationLimit;
    u8 unk_0C;
    u32 unk_10;
    u8 unk_14;
};

class IModule {
public:
    IModule() {
    }

    virtual ~IModule() {
    }

    virtual void* Allocate(AllocationParameters* parameters, u32 size, const u32* alignment, u32 arg3) = 0;
    virtual void Free(AllocationParameters* parameters, void* memory) = 0;
    virtual void* Realloc(AllocationParameters* parameters, void* memory, u32 size) = 0;
    virtual u32 Get_Allocation_Size(AllocationParameters* parameters, void* memory) = 0;
    virtual IModule* func_004105B0() = 0;
    virtual u32 func_00AB7340() = 0;
    virtual u32 Get_Payload_Size(void* memory) = 0;
    virtual u32 func_0040EE80(void* memory) = 0;
    virtual bool Has_Allocations() = 0;
    virtual void CheckConsistency(AllocationParameters* parameters);

    static void operator delete(void* memory) {
    }
};

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
