#ifndef ENGINE_COMMON_I_SCENE_OBJECT_I_SCHEDULE_REGISTER_H
#define ENGINE_COMMON_I_SCENE_OBJECT_I_SCHEDULE_REGISTER_H

#include "Engine/Common/ISceneObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {
namespace ISceneObject {

class IScheduleRegister {
public:
    virtual ~IScheduleRegister();
    virtual s32 Get_Number_Register0() = 0;
    virtual void Set_Number_Register0(s32 value) = 0;
    virtual s32 Get_Number_Register1() = 0;
    virtual void Set_Number_Register1(s32 value) = 0;
    virtual s32 Get_Number_Register2() = 0;
    virtual void Set_Number_Register2(s32 value) = 0;
    virtual s32 Get_Number_Register3() = 0;
    virtual void Set_Number_Register3(s32 value) = 0;
    virtual s32 Get_Number_Register4() = 0;
    virtual void Set_Number_Register4(s32 value) = 0;
    virtual s32 Get_Number_Register5() = 0;
    virtual void Set_Number_Register5(s32 value) = 0;
    virtual s32 Get_Number_Register6() = 0;
    virtual void Set_Number_Register6(s32 value) = 0;
    virtual s32 Get_Number_Register7() = 0;
    virtual void Set_Number_Register7(s32 value) = 0;
    virtual s32 Get_Number_Register(s32 index) = 0;
    virtual void Set_Number_Register(s32 index, s32 value) = 0;
    virtual char* Get_String_Register0() = 0;
    virtual void Set_String_Register0(const char* value) = 0;
    virtual char* Get_String_Register1() = 0;
    virtual void Set_String_Register1(const char* value) = 0;
    virtual char* Get_String_Register2() = 0;
    virtual void Set_String_Register2(const char* value) = 0;
    virtual char* Get_String_Register3() = 0;
    virtual void Set_String_Register3(const char* value) = 0;
    virtual char* Get_String_Register4() = 0;
    virtual void Set_String_Register4(const char* value) = 0;
    virtual char* Get_String_Register(s32 index) = 0;
    virtual void Set_String_Register(s32 index, const char* value) = 0;
};

} // namespace ISceneObject
} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
