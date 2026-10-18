#include "Engine/Vfx/Common/Memory/MemoryMap.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Memory {

MemoryMap::MemoryMap(u32 capacity, u32 arg1, bool embedded)
    : UsIntMap(capacity, 4, 4, 0, sizeof(MemoryMap), embedded) {
    unk_C18 = arg1;
    for (u32 index = 0; index < 256; index++) {
        Category_Statistics* statistics = &categories[index];
        statistics->count = 0;
        statistics->insertionCount = 0;
    }
}

MemoryMap::~MemoryMap() {
}

void MemoryMap::Clear() {
    count = 0;
}

s32 MemoryMap::func_004166E0(void* memory, u32 category, u32 arg2, u32 arg3) {
    if (count == capacity) {
        return 1;
    }

    u32 total = unk_C18 + arg2;
    Entry_Value value;
    value.packedValue = total & 0xFFFFFF;
    value.category = category;
    s32 result = BaseMap::Insert(&memory, &value, 0);
    if (!result) {
        Category_Statistics* entry = &categories[category];
        entry->count++;
        entry->insertionCount++;
        entry->unk_08 += total;
    }
    return result;
}

bool MemoryMap::func_00416750(void* memory) {
    Entry* entry = static_cast<Entry*>(BaseMap::Find_Entry(&memory));
    if (!entry) {
        return false;
    }

    u32 category = entry->value.category;
    u32 packed_value = entry->value.packedValue;

    bool removed = BaseMap::Remove(&memory);
    if (removed) {
        Category_Statistics* statistics = &categories[category];
        statistics->count--;
        statistics->unk_08 -= packed_value & 0xFFFFFF;
    }
    
    return removed;
}

void* MemoryMap::func_004167A0(void* memory) {
    return BaseMap::Find_Entry(&memory);
}

void* MemoryMap::func_004167B0(u32 index) {
    return BaseMap::Get_Entry(index);
}

u32 MemoryMap::Get_Allocation_Size() {
    return Map::func_00416E90(UsIntMap::Get_Capacity(), 4, 4, 0, sizeof(MemoryMap)) + sizeof(MemoryMap);
}

} // namespace Memory
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
