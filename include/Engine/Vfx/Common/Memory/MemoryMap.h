#ifndef ENGINE_VFX_COMMON_MEMORY_MEMORY_MAP_H
#define ENGINE_VFX_COMMON_MEMORY_MEMORY_MAP_H

#include "Engine/Vfx/Common/Map/UsIntMap.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Memory {

class MemoryMap : public Map::UsIntMap {
public:
    MemoryMap(u32 capacity, u32 arg1, bool embedded);
    virtual ~MemoryMap();
    virtual void Clear();
    virtual u32 Get_Allocation_Size();

    s32 func_004166E0(void* memory, u32 category, u32 arg2, u32 arg3);
    bool func_00416750(void* memory);
    void* func_004167A0(void* memory);
    void* func_004167B0(u32 index);

private:
    struct Category_Statistics {
        u32 count;
        u32 insertionCount;
        u32 unk_08;
    };

    union Entry_Value {
        u32 packedValue;
        u8 category;
    };

    struct Entry {
        void* memory;
        Entry_Value value;
    };

    Category_Statistics categories[256];
    u32 unk_C18;
};

} // namespace Memory
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
