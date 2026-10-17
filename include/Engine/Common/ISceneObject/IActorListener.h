#ifndef ENGINE_COMMON_I_SCENE_OBJECT_I_ACTOR_LISTENER_H
#define ENGINE_COMMON_I_SCENE_OBJECT_I_ACTOR_LISTENER_H

#include "Engine/Cut/Scheduler/ClipBase.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {

class ISceneObject::IActorListener {
public:
    virtual void func_00A206B0(void* arg0) = 0;
    virtual ~IActorListener();
};

} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
