#ifndef ENGINE_COMMON_I_SCENE_OBJECT_I_EFFECT_LISTENER_H
#define ENGINE_COMMON_I_SCENE_OBJECT_I_EFFECT_LISTENER_H

#include "Engine/Common/ISceneObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {

class ISceneObject::IEffectListener {
public:
    virtual void func_00A165A0(u32 arg0) = 0;
    virtual void func_00776340(u32 arg0);
    virtual void func_00A165B0(u32 arg0) = 0;
    virtual void func_00A165D0(u32 arg0) = 0;
    virtual u32 func_00908D10(u32 arg0, u32 arg1);
    virtual ~IEffectListener();
};

} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
