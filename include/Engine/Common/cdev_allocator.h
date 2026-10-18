#ifndef ENGINE_COMMON_CDEV_ALLOCATOR_H
#define ENGINE_COMMON_CDEV_ALLOCATOR_H

#include "Engine/Memory/Allocator.h"
#include <memory>

extern "C" SQEX::CDev::Engine::Memory::Allocator* D_01327FC0;

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

inline void* Allocate_Bytes(u32 size, const AllocationInfo& information) {
    Allocator* allocator = D_01327FC0;
    if (!allocator) {
        allocator = func_0040E500();
    }
    return allocator->Allocate(size, information);
}

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX

template<class T>
class CDev_Allocator : public std::allocator<T> {
public:
    CDev_Allocator() {
    }

    template<class Other>
    CDev_Allocator(const CDev_Allocator<Other>& arg0) {
    }

    T* allocate(size_t count) {
        using SQEX::CDev::Engine::Memory::Allocate_Bytes;
        using SQEX::CDev::Engine::Memory::AllocationInfo;
        return static_cast<T*>(Allocate_Bytes(count * sizeof(T), AllocationInfo(16, "CDev.Engine.Allocator")));
    }

    void deallocate(T* memory, size_t count) {
        if (memory) {
            reinterpret_cast<SQEX::CDev::Engine::Memory::Allocator**>(memory)[-1]->Free(memory);
        }
    }

    template<class Other>
    struct rebind {
        typedef CDev_Allocator<Other> other;
    };
};

#endif
