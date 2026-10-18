#ifndef ENGINE_COMMON_ISCENEOBJECT_H
#define ENGINE_COMMON_ISCENEOBJECT_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {
namespace ISceneObject {

class IActorListener;
class IEffect;
class IEffectListener;
class IScheduleDataTransfer;
class IScheduleRegister;

class IClip {
public:
    virtual ~IClip();
};

} // namespace ISceneObject
} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
