#ifndef ENGINE_CUT_PLUGINS_I_CUT_EFFECT_LISTENER_H
#define ENGINE_CUT_PLUGINS_I_CUT_EFFECT_LISTENER_H

#include "Engine/Common/ISceneObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {

namespace Scheduler {
class ClipBase;
class IScheduleActor;
} // namespace Scheduler

namespace Plugins {

class ICutEffectListener {
public:
    virtual Engine::Common::ISceneObject::IEffect* func_00A06500(u32 arg0, u32 arg1, u32 arg2, u32 arg3) = 0;
    virtual void func_00A06520(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual void func_00A06560(u32 arg0, u32 arg1, u32 arg2, u32 arg3) = 0;
    virtual void func_00A06580(u32 arg0, u32 arg1, u32 arg2, u32 arg3) = 0;
    virtual void func_00A065A0(u32 arg0, u32 arg1, u32 arg2, u32 arg3) = 0;
    virtual void func_00A065C0(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual void func_00A065D0(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual void func_00A065E0(u32 arg0, u32 arg1, u32 arg2, bool arg3) = 0;
    virtual void func_00A06650(
        Scheduler::ClipBase* clip,
        Scheduler::IScheduleActor* actor,
        Engine::Common::ISceneObject::IEffect* effect
    ) = 0;
    virtual void func_00A06670(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) = 0;
    virtual void* func_00A06780(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual ~ICutEffectListener();
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
