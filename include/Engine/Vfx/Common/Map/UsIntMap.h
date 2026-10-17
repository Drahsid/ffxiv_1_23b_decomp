#ifndef ENGINE_VFX_COMMON_MAP_US_INT_MAP_H
#define ENGINE_VFX_COMMON_MAP_US_INT_MAP_H

#include "Engine/Vfx/Common/Map/BaseMap.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Map {

class UsIntMap : public BaseMap {
public:
    UsIntMap(u32 capacity, bool embedded);
    UsIntMap(u32 capacity, u8 key_size, u8 value_size, u8 arg3, u32 object_size, bool embedded);
    virtual ~UsIntMap();
    virtual void Clear();
    virtual u32 Get_Allocation_Size();
    virtual s32 CompareKey_(const void* arg0, const void* arg1);
    virtual void func_00416DF0();
    virtual u32 Get_Count();
    virtual u32 Get_Capacity() {
        return capacity;
    }

    s32 Insert(u32 key, u32 value);
    bool Remove(u32 key);
    bool Remove_At(u32 index);
    u32 Remove_Value(u32 value);
    void* Find_Entry(u32 key);
    void* Get_Entry(u32 index);
    bool Set_Value(u32 key, u32 value);
    bool Contains_Value(u32 value);
};

} // namespace Map
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
