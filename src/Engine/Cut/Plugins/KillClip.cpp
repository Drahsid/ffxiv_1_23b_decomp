#include "Engine/Cut/Scheduler/BaseClipImpl.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "types.h"
#include "Engine/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

struct KILL_CLIP_DATA : Scheduler::ClipData {
    s16 targetCount;
    u16 unk_12;
    s16 targetIndices[1];
};

class KillClip : public Scheduler::BaseClipImpl<KILL_CLIP_DATA> {
public:
    KillClip(const Scheduler::ClipData* data, void* arg1);
    virtual ~KillClip();

    virtual const void* GetData() {
        const KILL_CLIP_DATA* data = static_cast<const KILL_CLIP_DATA*>(mClipData);
        u32 size = sizeof(KILL_CLIP_DATA) + (data->targetCount - 1) * sizeof(s16);
        return reinterpret_cast<const u8*>(data) + ((size + 3) & ~3);
    }

    virtual void OnEnter(Scheduler::ClipParameter* parameter) {
        Scheduler::ClipBase::OnEnter(parameter);
        const KILL_CLIP_DATA* data = static_cast<const KILL_CLIP_DATA*>(mClipData);
        for (s32 index = 0; index < data->targetCount; index++) {
            Scheduler::ClipBase* clip = parameter->Get_Clip(data->targetIndices[index]);
            if (clip) {
                clip->Set_Killed(true);
            }
            else {
                // "The clip targeted by Kill (index:%d) does not exist."
                LOG_ERROR_AT(".\\KillClip.cpp", 54, "Killの対象となるクリップ(index:%d)が存在しません。\n", index);
            }
        }
    }
};

KillClip::KillClip(const Scheduler::ClipData* data, void* arg1)
    : BaseClipImpl<KILL_CLIP_DATA>(data, arg1) {
}

KillClip::~KillClip() {
}

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX
