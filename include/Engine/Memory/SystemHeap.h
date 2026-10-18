#ifndef ENGINE_MEMORY_SYSTEM_HEAP_H
#define ENGINE_MEMORY_SYSTEM_HEAP_H

#include "Engine/Memory/IModule.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

class SystemHeap : public IModule {
public:
    typedef void* (*AllocateCallback)(u32 size, u32 alignment);
    typedef void (*FreeCallback)(void* memory);
    typedef void* (*ReallocateCallback)(void* memory, u32 size, u32 alignment);

    SystemHeap(void* arg0);

    virtual void* Allocate(AllocationParameters* parameters, u32 size, const u32* alignment, u32 arg3);
    virtual void Free(AllocationParameters* parameters, void* memory);
    virtual void* Realloc(AllocationParameters* parameters, void* memory, u32 size);
    virtual u32 Get_Allocation_Size(AllocationParameters* parameters, void* memory);
    virtual IModule* func_004105B0();
    virtual u32 func_00AB7340();

    virtual u32 Get_Payload_Size(void* memory) {
        return (static_cast<AllocationHeader*>(memory) - 1)->payloadSize;
    }

    virtual u32 func_0040EE80(void* memory) {
        return (static_cast<AllocationHeader*>(memory) - 1)->Get_Footer()->unk_0C;
    }

    virtual bool Has_Allocations();

    u32 Get_Used_Bytes();
    static u32 Get_Available_Physical_Memory();
    void Set_Callbacks(AllocateCallback allocate, FreeCallback free, ReallocateCallback reallocate);

private:
    struct AllocationFooter;

    struct AllocationHeader {
        AllocationHeader() {
            next = previous = this;
            payloadSize = 0;
            owner = 0;
        }

        AllocationHeader* next;
        AllocationHeader* previous;
        u32 payloadSize;
        AllocationParameters* owner;

        void Insert_After(AllocationHeader* node) {
            next->previous = node;
            node->next = next;
            node->previous = this;
            next = node;
        }

        void Unlink() {
            previous->next = next;
            next->previous = previous;
        }

        AllocationFooter* Get_Footer() {
            return reinterpret_cast<AllocationFooter*>(reinterpret_cast<u8*>(this + 1) + payloadSize);
        }
    };

    struct AllocationFooter {
        void* allocation;
        u32 allocationSize;
        u32 alignment;
        u32 unk_0C;
    };

    AllocationHeader allocations;
    u32 usedBytes;
    AllocateCallback allocateCallback;
    FreeCallback freeCallback;
    ReallocateCallback reallocateCallback;
};

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
