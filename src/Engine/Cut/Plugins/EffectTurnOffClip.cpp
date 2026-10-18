#include "Engine/Cut/Plugins/EffectClip.h"
#include "Engine/Cut/Plugins/IClipListenerHolder.h"
#include "Engine/Cut/Plugins/ICutEffectListener.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "Engine/Cut/Scheduler/Scheduler.h"
#include "Engine/Common/Log.h"
#include <string.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

struct EFFECT_TURNOFF_CLIP_DATA : Scheduler::ClipData {
    s16 targetCount;
    bool unk_12 : 1;
    u8 unk_13;
    s16 targetIndices[1];
};

static const char* sEffectClipName = "EffectClip";

class EffectTurnOffClip : public Scheduler::BaseClipImpl<EFFECT_TURNOFF_CLIP_DATA> {
public:
    EffectTurnOffClip(const Scheduler::ClipData* data, void* arg1);
    virtual ~EffectTurnOffClip();

    virtual const void* GetData() {
        const EFFECT_TURNOFF_CLIP_DATA* data = Get_Clip_Data();
        u32 size = sizeof(EFFECT_TURNOFF_CLIP_DATA) + (data->targetCount - 1) * sizeof(s16);
        return reinterpret_cast<const u8*>(data) + ((size + 3) & ~3);
    }

    virtual bool func_005C5C80() {
        return Get_Clip_Data()->unk_12;
    }

    virtual const void* func_00AB7340() {
        const EFFECT_TURNOFF_CLIP_DATA* data = Get_Clip_Data();
        u32 address = reinterpret_cast<u32>(data->targetIndices + data->targetCount);
        if (address & 3) {
            address = (address & ~3) + 4;
        }
        return reinterpret_cast<const void*>(address);
    }

    virtual void OnEnter(Scheduler::ClipParameter* parameter) {
        Scheduler::ClipBase::OnEnter(parameter);
        const EFFECT_TURNOFF_CLIP_DATA* data = Get_Clip_Data();
        Scheduler::IScheduleActor* actor = parameter->func_00A1FFA0(data->actorIndex);
        ICutEffectListener* listener = unk_24->func_00A29AA0();
        if (listener) {
            for (s32 index = 0; index < data->targetCount; index++) {
                Scheduler::ClipBase* clip = parameter->Get_Clip(data->targetIndices[index]);
                if (clip && clip->func_00A210E0() == 2 && !clip->Is_Killed()) {
                    if (strncmp(parameter->func_00A20070()->func_00A1B700(clip->func_00A21030()), sEffectClipName, 15) == 0) {
                        Engine::Common::ISceneObject::IEffect* effect = static_cast<EffectClip*>(clip)->Get_Effect();
                        if (effect) {
                            listener->func_00A06650(this, actor, effect);
                        }
                    }
                }
                else {
                    // "[ERROR][%s:%d] The clip targeted by EffectTurnOff (index:%d) does not exist."
                    LOG_ERROR("[ERROR][%s:%d] EffectTurnOffの対象となるクリップ(index:%d)が存在しません。", ".\\EffectTurnOffClip.cpp", 76, index);
                }
            }
        }
    }
};

EffectTurnOffClip::EffectTurnOffClip(const Scheduler::ClipData* data, void* arg1) : BaseClipImpl<EFFECT_TURNOFF_CLIP_DATA>(data, arg1) {
}

EffectTurnOffClip::~EffectTurnOffClip() {
}

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX
