#ifndef ENGINE_CUT_SCHEDULER_BASE_ACTOR_IMPL_H
#define ENGINE_CUT_SCHEDULER_BASE_ACTOR_IMPL_H

#include "Engine/Cut/Scheduler/ActorBase.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

template<class T>
class BaseActorImpl : public ActorBase {
public:
    BaseActorImpl(const ActorData* data, void* arg1, void* arg2) : ActorBase(data, arg1, arg2) {
    }

    virtual ~BaseActorImpl() {
    }
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
