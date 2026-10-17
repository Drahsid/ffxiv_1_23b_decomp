#ifndef ENGINE_CUT_SCHEDULER_PROXY_ACTOR_H
#define ENGINE_CUT_SCHEDULER_PROXY_ACTOR_H

#include "Engine/Cut/Scheduler/BaseActorImpl.h"
#include "Engine/Cut/Scheduler/IProxyActor.h"
#include "Engine/Common/ISceneObject/IActorListener.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

struct PROXY_ACTOR_DATA;

class ProxyActor : public BaseActorImpl<PROXY_ACTOR_DATA>, private IProxyActor, private Engine::Common::ISceneObject::IActorListener {
public:
    virtual ~ProxyActor();
    virtual void* func_00AB7340();
    virtual IScheduleActor* func_00A206A0();
    virtual void func_00A205D0(void* arg0);
    virtual void Bind(IScheduleActor* pActor);
    virtual void func_00A20640(void* arg0);
    virtual void func_00A205F0(IScheduleActor* arg0);
    virtual u32 func_00A20800();
    virtual u32 func_00A20810();
    virtual const void* func_00A20850();
    virtual s32 func_00A20880();
    virtual u32 func_00A20820();
    virtual u32 func_00A20830();
    virtual const void* func_00A20840();
    virtual s32 func_00A20860();
    virtual const void* func_00A208A0();
    virtual void func_00A206B0(void* arg0);
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
