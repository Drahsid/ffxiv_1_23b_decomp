#ifndef ENGINE_CUT_PLUGINS_EFFECT_CLIP_H
#define ENGINE_CUT_PLUGINS_EFFECT_CLIP_H

#include "Engine/Cut/Scheduler/BaseClipImpl.h"
#include "Engine/Common/ISceneObject/IEffectListener.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

struct EFFECT_CLIP_DATA : Scheduler::ClipData {
    u8 unk_10[0x20];
};

class EffectClip : public Scheduler::BaseClipImpl<EFFECT_CLIP_DATA>, private Engine::Common::ISceneObject::IEffectListener {
public:
    Engine::Common::ISceneObject::IEffect* Get_Effect() {
        return unk_40;
    }

private:
    u32 unk_3C;
    Engine::Common::ISceneObject::IEffect* unk_40;
    u8 unk_44[0x34];
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
