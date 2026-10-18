#include "Engine/Vfx/Common/Map/UsIntMap.h"
#include "Engine/Vfx/Common/Io/Printer.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Map {

UsIntMap::UsIntMap(u32 capacity, bool embedded)
    : BaseMap(capacity, 4, 4, 0, sizeof(UsIntMap), embedded) {
}

UsIntMap::UsIntMap(u32 capacity, u8 key_size, u8 value_size, u8 arg3, u32 object_size, bool embedded)
    : BaseMap(capacity, key_size, value_size, arg3, object_size, embedded) {
}

UsIntMap::~UsIntMap() {
}

void UsIntMap::Clear() {
    count = 0;
}

s32 UsIntMap::Insert(u32 key, u32 value) {
    if (count == capacity) {
        return 1;
    }
    return BaseMap::Insert(&key, &value, 0);
}

bool UsIntMap::Remove(u32 key) {
    return BaseMap::Remove(&key);
}

bool UsIntMap::Remove_At(u32 index) {
    return BaseMap::Remove_At(index);
}

u32 UsIntMap::Remove_Value(u32 value) {
    return BaseMap::Remove_Value(&value);
}

void* UsIntMap::Find_Entry(u32 key) {
    return BaseMap::Find_Entry(&key);
}

void* UsIntMap::Get_Entry(u32 index) {
    return BaseMap::Get_Entry(index);
}

bool UsIntMap::Set_Value(u32 key, u32 value) {
    return BaseMap::Set_Value(&key, &value);
}

bool UsIntMap::Contains_Value(u32 value) {
    return BaseMap::Contains_Value(&value);
}

u32 UsIntMap::Get_Allocation_Size() {
    return func_00416E90(capacity, keySize, valueSize, unk_16, sizeof(UsIntMap));
}

s32 UsIntMap::CompareKey_(const void* arg0, const void* arg1) {
    u32 key = *static_cast<const u32*>(arg0);
    u32 entry_key = *static_cast<const u32*>(arg1);
    if (entry_key > key) {
        return 1;
    }
    return entry_key < key ? -1 : 0;
}

void UsIntMap::func_00416DF0() {
    Io::func_00415F70(
        Io::Printer::func_00415C90(),
        "[UsIntMap] debug print start.  (%d / %d) ---------",
        static_cast<s32>(count),
        static_cast<s32>(capacity)
    );
    u32* record = reinterpret_cast<u32*>(records);
    if (record) {
        for (u32 index = 0; index < count; index++) {
            Io::func_00415F70(Io::Printer::func_00415C90(), "\tx%04x\tx%08x, x%08x", index, record[0], record[1]);
            record += 2;
        }
        Io::func_00415F70(Io::Printer::func_00415C90(), "[UsIntMap] debug print end.   --------------------");
    }
}

} // namespace Map
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
