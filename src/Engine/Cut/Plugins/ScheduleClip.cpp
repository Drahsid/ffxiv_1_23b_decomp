#include "Engine/Cut/Scheduler/BaseClipImpl.h"
#include "Engine/Cut/Plugins/IClipListenerHolder.h"
#include "Engine/Cut/Plugins/ICutResourceListener.h"
#include "Engine/Cut/Scheduler/ActorIterator.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "Engine/Cut/Scheduler/ProxyActor.h"
#include "Engine/Cut/Scheduler/ResourceReference.h"
#include "Engine/Cut/Scheduler/Scheduler.h"
#include "Engine/Cut/Scheduler/SchedulerFactory.h"
#include "Engine/Common/Log.h"
#include <memory>
#include <stddef.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

struct SCHEDULE_CLIP_DATA : Scheduler::ClipData {
    s32 resourceIndex;
    u32 unk_14[2];
    u8 unk_1C;
    u8 unk_1D[1];
};

class ScheduleClip : public Scheduler::BaseClipImpl<SCHEDULE_CLIP_DATA> {
public:
    ScheduleClip(const Scheduler::ClipData* data, void* arg1);
    virtual ~ScheduleClip();
    virtual void OnEnter(Scheduler::ClipParameter* parameter);
    virtual void func_00A21000(u32 arg0);
    virtual void func_00A20F90(Scheduler::ClipParameter* arg0);
    virtual void func_00A21010(u32 arg0);
    virtual const void* GetData();

private:
    std::auto_ptr<Scheduler::Scheduler> scheduler;
};

void ScheduleClip::func_00A21000(u32 arg0) {
    Scheduler::ClipBase::func_00A21000(arg0);
}

ScheduleClip::ScheduleClip(const Scheduler::ClipData* data, void* arg1)
    : BaseClipImpl<SCHEDULE_CLIP_DATA>(data, arg1), scheduler(0) {
}

const void* ScheduleClip::GetData() {
    const SCHEDULE_CLIP_DATA* data = Get_Clip_Data();
    u32 size = offsetof(SCHEDULE_CLIP_DATA, unk_1C) + data->unk_1C;
    return reinterpret_cast<const u8*>(data) + ((size + 3) & ~3);
}

template<class T>
inline void Defer_Default_Assert_Handler() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    Defer_Default_Assert_Handler<void>();
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

ScheduleClip::~ScheduleClip() {
    if (scheduler.get()) {
        scheduler->func_00A1F0C0();
    }
}

void ScheduleClip::func_00A20F90(Scheduler::ClipParameter* arg0) {
    Scheduler::ClipBase::func_00A20F90(arg0);
    scheduler->Execute();
    if (*scheduler->func_00A1B7F0() == 4) {
        func_00A210F0(0);
    }
}

void ScheduleClip::func_00A21010(u32 arg0) {
    Scheduler::ClipBase::func_00A21010(arg0);
    if (scheduler.get()) {
        scheduler->func_00A1F0C0();
    }
}

void ScheduleClip::OnEnter(Scheduler::ClipParameter* parameter) {
    Scheduler::ClipBase::OnEnter(parameter);
    const SCHEDULE_CLIP_DATA* data = Get_Clip_Data();
    if (data->resourceIndex < 0) {
        // "[ScheduleClip] Invalid Resource index=%d"
        LOG_WARNING("[ScheduleClip] 不正Resourceです index=%d", data->resourceIndex);
        Set_Killed(true);
        return;
    }

    Scheduler::IScheduleActor* actor = parameter->func_00A1FFA0(data->actorIndex);
    ICutResourceListener* listener = unk_24->func_00657340();
    Scheduler::ResourceReference* resources = parameter->func_00A20070()->unk_74;
    Dw::SceneGraph::DagNode* pDagNode = listener->func_00A076D0(
        this,
        actor,
        resources,
        resources->func_00A27560(data->resourceIndex),
        resources->func_00A27600(data->resourceIndex)
    );

    LOG_ASSERT_AT(".\\ScheduleClip.cpp", 67, pDagNode != 0, "");

    void* factory_arg1 = parameter->func_00A20040()->unk_04;
    Scheduler::SchedulerFactory factory(
        pDagNode,
        factory_arg1,
        parameter->func_00A20050(),
        parameter->func_00A20060(),
        parameter->func_00A20070()
    );

    scheduler.reset(factory.func_00A26640(0).release());
    scheduler->unk_90 |= 0x40;
    scheduler->func_00A1B7D0(2);

    if (data->unk_1C > 0) {
        Scheduler::ActorIterator iterator = scheduler->func_00A1C5B0("ProxyActor");
        u32 index = 0;
        while (iterator.func_00A21D30()) {
            if (data->unk_1D[index] != 0xFF) {
                Scheduler::ProxyActor* actor = static_cast<Scheduler::ProxyActor*>(iterator.func_00A21D50());
                Scheduler::IScheduleActor* target = parameter->func_00A1FFA0(data->unk_1D[index]);
                actor->Bind(target);
            }
            iterator.func_00A21D80();
            index++;
        }
    }
    
    scheduler->func_00A1CE70(Scheduler::Float4(static_cast<Scheduler::Scheduler*>(func_00A21230())->func_00A1C040()));
    scheduler->func_00A1CE20(Scheduler::Float4(static_cast<Scheduler::Scheduler*>(func_00A21230())->func_00A1C030()));
    func_00A210F0(2);
}

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

