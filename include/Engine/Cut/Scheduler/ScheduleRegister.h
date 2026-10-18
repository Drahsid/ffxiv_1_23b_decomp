#ifndef ENGINE_CUT_SCHEDULER_SCHEDULE_REGISTER_H
#define ENGINE_CUT_SCHEDULER_SCHEDULE_REGISTER_H

#include "Engine/Common/ISceneObject/IScheduleRegister.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

class ScheduleRegister : public Engine::Common::ISceneObject::IScheduleRegister {
public:
    ScheduleRegister();
    virtual ~ScheduleRegister();
    virtual s32 Get_Number_Register0();
    virtual void Set_Number_Register0(s32 value);
    virtual s32 Get_Number_Register1();
    virtual void Set_Number_Register1(s32 value);
    virtual s32 Get_Number_Register2();
    virtual void Set_Number_Register2(s32 value);
    virtual s32 Get_Number_Register3();
    virtual void Set_Number_Register3(s32 value);
    virtual s32 Get_Number_Register4();
    virtual void Set_Number_Register4(s32 value);
    virtual s32 Get_Number_Register5();
    virtual void Set_Number_Register5(s32 value);
    virtual s32 Get_Number_Register6();
    virtual void Set_Number_Register6(s32 value);
    virtual s32 Get_Number_Register7();
    virtual void Set_Number_Register7(s32 value);
    virtual s32 Get_Number_Register(s32 index);
    virtual void Set_Number_Register(s32 index, s32 value);
    virtual char* Get_String_Register0();
    virtual void Set_String_Register0(const char* value);
    virtual char* Get_String_Register1();
    virtual void Set_String_Register1(const char* value);
    virtual char* Get_String_Register2();
    virtual void Set_String_Register2(const char* value);
    virtual char* Get_String_Register3();
    virtual void Set_String_Register3(const char* value);
    virtual char* Get_String_Register4();
    virtual void Set_String_Register4(const char* value);
    virtual char* Get_String_Register(s32 index);
    virtual void Set_String_Register(s32 index, const char* value);

private:
    s32 numberRegisters[8];
    char stringRegisters[5][32];
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
