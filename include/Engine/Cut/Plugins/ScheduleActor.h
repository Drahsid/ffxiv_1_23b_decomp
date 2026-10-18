#ifndef ENGINE_CUT_PLUGINS_SCHEDULE_ACTOR_H
#define ENGINE_CUT_PLUGINS_SCHEDULE_ACTOR_H

#include "Engine/Cut/CutScenePlayer/CutSceneObject.h"
#include "Engine/Cut/Scheduler/BaseActorImpl.h"
#include "types.h"
#include <memory>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {

namespace Scheduler {
class ClipBase;
class ClipParameter;
} // namespace Scheduler

namespace Plugins {

class IClipListenerHolder;

struct SCHEDULE_ACTOR_DATA : Scheduler::ActorData {
    s32 resourceIndex;
    u8 unk_24;
    u8 unk_25[1];
};

class ScheduleActor : public Scheduler::BaseActorImpl<SCHEDULE_ACTOR_DATA> {
public:
    void func_00DE73E0(u32 arg0);
    u32 func_00DE73F0();
    u32 func_00DE7400();
    ScheduleActor(const Scheduler::ActorData* data, void* arg1, void* arg2);
    virtual ~ScheduleActor();
    void func_00DE75C0(Scheduler::ClipParameter* arg0);
    void func_00DE75F0(Scheduler::ClipParameter* arg0);
    void OnEnter(Scheduler::ClipBase* clip, IClipListenerHolder* listeners, Scheduler::ClipParameter* parameter);

private:
    u32 unk_60;
    u32 unk_64;
    std::auto_ptr<Scheduler::Scheduler> scheduler;
    Scheduler::Scheduler* unk_6C;
    CutScenePlayer::CutSceneObject unk_70;
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
