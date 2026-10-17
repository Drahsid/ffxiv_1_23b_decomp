#include "Engine/Vfx/Common/Map/BaseMap.h"
#include "Engine/Vfx/Common/Io/Printer.h"
#include "Engine/Vfx/Common/Memory/Memory.h"

#include <string.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Map {

static void Copy_Words(void* destination, const void* source, u32 words) {
    const u32* source_words = static_cast<const u32*>(source);
    u32* destination_words = static_cast<u32*>(destination);

    switch (words) {
    case 1:
        destination_words[0] = source_words[0];
        return;
    case 2:
        destination_words[0] = source_words[0];
        destination_words[1] = source_words[1];
        return;
    case 3:
        destination_words[0] = source_words[0];
        destination_words[1] = source_words[1];
        destination_words[2] = source_words[2];
        return;
    case 4:
        destination_words[0] = source_words[0];
        destination_words[1] = source_words[1];
        destination_words[2] = source_words[2];
        destination_words[3] = source_words[3];
        return;
    }
    for (u32 index = 0; index < words; index++) {
        destination_words[index] = source_words[index];
    }
}

static bool Equal_Bytes(const void* first, const void* second, u32 size) {
    bool equal = false;
    if (size % 4 == 0) {
        const u32* first_words = static_cast<const u32*>(first);
        const u32* second_words = static_cast<const u32*>(second);
        u32 words = size >> 2;
        switch (words) {
        case 1:
            if (first_words[0] == second_words[0]) {
                equal = true;
            }
            break;
        case 2:
            if (first_words[0] == second_words[0] && first_words[1] == second_words[1]) {
                equal = true;
            }
            break;
        case 3:
            if (first_words[0] == second_words[0] && first_words[1] == second_words[1] && first_words[2] == second_words[2]) {
                equal = true;
            }
            break;
        case 4:
            if (first_words[0] == second_words[0] && first_words[1] == second_words[1] && first_words[2] == second_words[2] &&
                first_words[3] == second_words[3]) {
                equal = true;
            }
            break;
        default:
            equal = true;
            for (u32 index = 0; index < words; index++) {
                if (first_words[index] != second_words[index]) {
                    equal = false;
                    break;
                }
            }
            break;
        }
    }
    else {
        const u8* first_bytes = static_cast<const u8*>(first);
        const u8* second_bytes = static_cast<const u8*>(second);
        equal = true;
        for (u32 index = 0; index < size; index++) {
            if (first_bytes[index] != second_bytes[index]) {
                equal = false;
                break;
            }
        }
    }
    return equal;
}

BaseMap::BaseMap() {
}

BaseMap::~BaseMap() {
    if (!(unk_12 & 1) && records) {
        func_004162C0(records);
    }
}

void BaseMap::Clear() {
    count = 0;
}

void BaseMap::func_004169C0() {
    if (unk_12 & 1) {
        return;
    }

    count = 0;
    capacity = 0;

    if (records) {
        func_004162C0(records);
        records = 0;
    }
}

bool BaseMap::Is_Full() {
    return capacity == count;
}

s32 BaseMap::Insert(const void* key, const void* value, void** entry) {
    if (count == capacity) {
        return 1;
    }

    u8* record;
    if (!count) {
        record = records;
    }
    else {
        bool found = false;
        s32 index = func_00416CC0(key, &found);
        if (found) {
            return 2;
        }

        s32 remaining = count - index;
        if (remaining >= 1) {
            record = records + (keySize + valueSize + unk_16) * index;
            memmove(record + (keySize + valueSize + unk_16), record, (keySize + valueSize + unk_16) * remaining);
        }
        record = records + (keySize + valueSize + unk_16) * index;
    }

    if (entry) {
        *entry = record;
    }

    Copy_Words(record, key, keySize >> 2);
    Copy_Words(record + keySize, value, valueSize >> 2);
    count++;
    return 0;
}

void* BaseMap::Find_Entry(const void* key) {
    bool found = false;
    s32 index = func_00416CC0(key, &found);
    if (!found) {
        return 0;
    }
    return records + (keySize + valueSize + unk_16) * index;
}

void* BaseMap::Get_Entry(u32 index) {
    if (count < index) {
        return 0;
    }
    return records + (keySize + valueSize + unk_16) * index;
}

} // namespace Map
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#include "Engine/Vfx/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Map {

void* BaseMap::Find_Entry_By_Value(const void* value) {
    if (!count) {
        return 0;
    }

    for (u32 index = 0; index < count; index++) {
        u8* record = records + (keySize + valueSize + unk_16) * index;
        const u8* entry_value = record + keySize;
        if (func_00416E60(value, entry_value)) {
            return record;
        }
    }
    return 0;
}

bool BaseMap::Set_Value(const void* key, const void* value) {
    bool found = false;
    s32 index = func_00416CC0(key, &found);
    if (!found) {
        return false;
    }
    u8* record = records + (keySize + valueSize + unk_16) * index;
    Copy_Words(record + keySize, value, valueSize >> 2);
    return true;
}

bool BaseMap::Contains_Value(const void* value) {
    u8* record = records;
    for (u32 index = 0; index < count; index++) {
        const u8* entry_value = record + keySize;
        if (func_00416E60(value, entry_value)) {
            return true;
        }
        record += keySize + valueSize + unk_16;
    }
    return false;
}

bool BaseMap::Has_Storage() {
    return records != 0;
}

s32 BaseMap::func_00416CC0(const void* key, bool* found) {
    *found = false;
    s32 remaining = count;
    if (!remaining) {
        return 0;
    }

    s32 index = 0;
    while (remaining >= 2) {
        index += remaining / 2;
        s32 remainder = remaining % 2;
        const u8* record = records + (keySize + valueSize + unk_16) * index;
        s32 result = CompareKey_(key, record);
        if (!result) {
            *found = true;
            return index;
        }

        if (result > 0) {
            remaining /= 2;
            index -= remaining;
        }
        else {
            remaining = remainder ? remaining / 2 + 1 : remaining / 2;
        }
    }

    const u8* record = records + (keySize + valueSize + unk_16) * index;
    s32 result = CompareKey_(key, record);
    if (result > 0) {
        return index;
    }

    if (result < 0) {
        return index + 1;
    }

    *found = true;
    return index;
}

bool BaseMap::Remove_At(u32 index) {
    if (count <= index) {
        return false;
    }

    u8* record = records + (keySize + valueSize + unk_16) * index;
    func_00416E80(record);
    u32 remaining = count - index - 1;
    if (remaining) {
        memmove(record, record + keySize + valueSize + unk_16, (keySize + valueSize + unk_16) * remaining);
    }

    count--;
    return true;
}

void BaseMap::func_00416DF0() {
    Io::func_00415F70(Io::Printer::func_00415C90(), "[BaseMap] debug print start.  (%d / %d) ---------", static_cast<s32>(count), static_cast<s32>(capacity));
    u32* record = reinterpret_cast<u32*>(records);
    if (record) {
        for (u32 index = 0; index < count; index++) {
            const u8* entry_value = reinterpret_cast<u8*>(record) + keySize;
            Io::func_00415F70(Io::Printer::func_00415C90(), "\tx%04x\tx%08x, x%08x", index, reinterpret_cast<u32>(record), reinterpret_cast<u32>(entry_value));
            record++;
        }
        Io::func_00415F70(Io::Printer::func_00415C90(), "[BaseMap] debug print end.   --------------------");
    }
}

bool BaseMap::func_00416E60(const void* arg0, const void* arg1) {
    return Equal_Bytes(arg0, arg1, valueSize);
}

void BaseMap::func_00416E80(void* arg0) {
}

extern "C" u32 func_00416E90(u32 capacity, u32 key_size, u32 value_size, u32 arg3, u32 header_size) {
    if (!capacity) {
        return 0;
    }
    return capacity * (key_size + value_size + arg3) + ((header_size + 3) & ~3);
}

u32 BaseMap::Get_Allocation_Size() {
    if (!capacity) {
        return 0;
    }
    return capacity * (keySize + valueSize + unk_16) + sizeof(BaseMap);
}

bool BaseMap::Remove(const void* key) {
    bool found = false;
    s32 index = func_00416CC0(key, &found);
    if (!found) {
        return false;
    }
    Remove_At(index);
    return true;
}

u32 BaseMap::Remove_Value(const void* value) {
    if (!count) {
        return 0;
    }

    u32 removed = 0;
    for (s32 index = count - 1; index >= 0; index--) {
        u8* record = records + (keySize + valueSize + unk_16) * index;
        const u8* entry_value = record + keySize;
        if (func_00416E60(value, entry_value)) {
            Remove_At(index);
            removed++;
        }
    }

    return removed;
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

BaseMap::BaseMap(u32 capacity, u8 key_size, u8 value_size, u8 arg3, u32 object_size, bool embedded) {
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 161, capacity < 0x7FFFFFFF);
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 162, key_size % 4 == 0);
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 163, value_size % 4 == 0);
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 164, object_size != 0);
    unk_12 = 0;
    unk_13 = 0xFF;
    this->capacity = capacity;
    count = 0;
    objectSize = object_size;
    keySize = key_size;
    valueSize = value_size;
    unk_16 = arg3;
    records = 0;
    if (embedded) {
        unk_12 = 1;
        records = reinterpret_cast<u8*>((reinterpret_cast<u32>(this) + object_size + 3) & ~3);
    }
    else if (capacity) {
        u32 size = (keySize + valueSize + unk_16) * capacity + sizeof(BaseMap);
        records = static_cast<u8*>(func_00416480(size, 9, 16, __FUNCTION__, ".\\Map\\BaseMap.cpp", 187));
    }
}

bool BaseMap::Realloc(u32 capacity) {
    Io::func_004160E0(Io::Printer::func_00415C90(), 0, "non impl");
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 236, false);
    return false;
}

bool BaseMap::Realloc_(u32 capacity) {
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 415, this->capacity < capacity);
    u32 size = (keySize + valueSize + unk_16) * capacity;
    u8* storage = static_cast<u8*>(func_00416480(size, unk_13, 16, 0, 0, 0));
    if (!storage) {
        return false;
    }

    if (records) {
        memcpy(storage, records, size); // BUG: Growth can read past the old allocation
        func_004162C0(records);
    }
    
    records = storage;
    this->capacity = capacity;
    return true;
}

s32 BaseMap::CompareKey_(const void* arg0, const void* arg1) {
    Io::func_004160E0(Io::Printer::func_00415C90(), 0, "[BaseMap] compare");
    VFX_ASSERT_AT(".\\Map\\BaseMap.cpp", 539, false);
    return 0;
}

} // namespace Map
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
