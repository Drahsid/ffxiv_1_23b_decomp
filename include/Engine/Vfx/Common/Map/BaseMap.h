#ifndef ENGINE_VFX_COMMON_MAP_BASE_MAP_H
#define ENGINE_VFX_COMMON_MAP_BASE_MAP_H

#include "Engine/Vfx/Common/Object.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Map {

extern "C" u32 func_00416E90(u32 capacity, u32 key_size, u32 value_size, u32 arg3, u32 header_size);

class BaseMap : public Object {
public:
    BaseMap();
    BaseMap(u32 capacity, u8 key_size, u8 value_size, u8 arg3, u32 object_size, bool embedded);
    virtual ~BaseMap();
    virtual bool Has_Storage();
    virtual void Clear();
    virtual void func_004169C0();
    virtual bool Realloc(u32 capacity);
    virtual u32 Get_Allocation_Size();
    virtual bool Is_Full();
    virtual s32 func_00416CC0(const void* key, bool* found);
    virtual s32 CompareKey_(const void* arg0, const void* arg1);
    virtual bool func_00416E60(const void* arg0, const void* arg1);
    virtual void func_00416E80(void* arg0);
    virtual void func_00416DF0();

    bool Realloc_(u32 capacity);
    s32 Insert(const void* key, const void* value, void** entry);
    bool Remove(const void* key);
    bool Remove_At(u32 index);
    u32 Remove_Value(const void* value);
    void* Find_Entry(const void* key);
    void* Get_Entry(u32 index);
    bool Set_Value(const void* key, const void* value);
    bool Contains_Value(const void* value);

    void* Find_Entry_By_Value(const void* value);

protected:
    u8* records;
    u32 capacity;
    u32 count;
    u16 objectSize;
    u8 unk_12;
    u8 unk_13;
    u8 keySize;
    u8 valueSize;
    u8 unk_16;
};

} // namespace Map
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
