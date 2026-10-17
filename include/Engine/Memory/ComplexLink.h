#ifndef ENGINE_MEMORY_COMPLEX_LINK_H
#define ENGINE_MEMORY_COMPLEX_LINK_H

#include "Engine/Memory/IModule.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

class ComplexLink : public IModule {
public:
    ComplexLink(AllocationParameters* parameters);

    virtual void* Allocate(AllocationParameters* parameters, u32 size, const u32* alignment, u32 arg3);
    virtual void Free(AllocationParameters* parameters, void* memory);
    virtual void* Realloc(AllocationParameters* parameters, void* memory, u32 size);
    virtual u32 Get_Allocation_Size(AllocationParameters* parameters, void* memory);

    virtual IModule* func_004105B0() {
        return this;
    }

    virtual u32 func_00AB7340() {
        return 1;
    }

    virtual u32 Get_Payload_Size(void* memory) {
        return (static_cast<Block*>(memory) - 1)->size;
    }

    virtual u32 func_0040EE80(void* memory) {
        return (static_cast<Block*>(memory) - 1)->unk_08;
    }

    virtual bool Has_Allocations() {
        return false;
    }

    virtual void CheckConsistency(AllocationParameters* parameters);

private:
    struct Block {
        Block() {
            next = previous = this;
            used = false;
            previousSize = 0;
            size = 0;
        }

        u32 size;
        u32 previousSize : 31;
        u32 used : 1;
        union {
            Block* next;
            u32 unk_08;
        };
        union {
            Block* previous;
            AllocationParameters* owner;
        };

        bool Is_Used() {
            return used;
        }

        Block* Get_Next() {
            return reinterpret_cast<Block*>(reinterpret_cast<u8*>(this + 1) + size);
        }

        Block* Get_Previous() {
            return reinterpret_cast<Block*>(reinterpret_cast<u8*>(this) - previousSize) - 1;
        }

        void Insert_After(Block* node) {
            next->previous = node;
            node->next = next;
            node->previous = this;
            next = node;
        }

        void Unlink() {
            previous->next = next;
            next->previous = previous;
        }
    };

    enum {
        BIN_COUNT = 33
    };

    static u32 Get_Bin_Index(u32 size);

    Block bins[BIN_COUNT];
};

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
