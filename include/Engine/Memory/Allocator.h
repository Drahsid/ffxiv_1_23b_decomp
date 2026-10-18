#ifndef ENGINE_MEMORY_ALLOCATOR_H
#define ENGINE_MEMORY_ALLOCATOR_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

struct AllocationInfo {
    AllocationInfo(u32 alignment, const char* category);
    AllocationInfo(const u32& alignment, const char* category, const char* function, const char* file, s32 line);

    u32 alignment;
    const char* category;
};

class Allocator {
public:
    void* Allocate(u32 size, const AllocationInfo& information);
    void Free(void* memory);
};

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX

extern "C" SQEX::CDev::Engine::Memory::Allocator* func_0040E500();

#endif
