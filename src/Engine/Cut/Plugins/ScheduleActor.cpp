#include "Engine/Cut/Plugins/ScheduleActor.h"
#include "Engine/Cut/Plugins/IClipListenerHolder.h"
#include "Engine/Cut/Plugins/ICutResourceListener.h"
#include "Engine/Cut/Scheduler/ActorIterator.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "Engine/Cut/Scheduler/ProxyActor.h"
#include "Engine/Cut/Scheduler/ResourceReference.h"
#include "Engine/Cut/Scheduler/ScheduleDataTransfer.h"
#include "Engine/Cut/Scheduler/Scheduler.h"
#include "Engine/Cut/Scheduler/SchedulerFactory.h"
#include "Engine/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

void ScheduleActor::func_00DE73E0(u32 arg0) {
    unk_60 = arg0;
}

u32 ScheduleActor::func_00DE73F0() {
    return unk_60;
}

u32 ScheduleActor::func_00DE7400() {
    return unk_64;
}

ScheduleActor::ScheduleActor(const Scheduler::ActorData* data, void* arg1, void* arg2)
    : BaseActorImpl<SCHEDULE_ACTOR_DATA>(data, arg1, arg2), unk_60(0), unk_64(0), scheduler(0), unk_6C(0), unk_70(0) {
}

ScheduleActor::~ScheduleActor() {
    scheduler.reset();
}

template<class T>
inline void Defer_Default_Assert_Handler() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    Defer_Default_Assert_Handler<void>();
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void ScheduleActor::func_00DE75C0(Scheduler::ClipParameter* arg0) {
    scheduler->Execute();
    if (*scheduler->func_00A1B7F0() == 4) {
        unk_60 = 3;
    }
}

void ScheduleActor::func_00DE75F0(Scheduler::ClipParameter* arg0) {
    scheduler->func_00A1BCB0();
    if (scheduler.get()) {
        scheduler->func_00A1F0C0();
        scheduler.reset();
    }
    unk_60 = 0;
}

void ScheduleActor::OnEnter(Scheduler::ClipBase* clip, IClipListenerHolder* listeners, Scheduler::ClipParameter* parameter) {
    unk_60 = 0;
    unk_64 = 0;
    unk_6C = 0;
    if (scheduler.get()) {
        scheduler->func_00A1F0C0();
        scheduler.reset();
    }

    const SCHEDULE_ACTOR_DATA* data = static_cast<const SCHEDULE_ACTOR_DATA*>(mActorData);
    if (data->resourceIndex < 0) {
        // "[ScheduleActor] Invalid Resource index=%d"
        LOG_WARNING("[ScheduleActor] 不正Resourceです index=%d", data->resourceIndex);
        return;
    }

    ICutResourceListener* listener = listeners->func_00657340();
    Scheduler::ResourceReference* reference = parameter->func_00A20070()->unk_74;
    Dw::SceneGraph::DagNode* pDagNode = listener->func_00A076D0(
        clip,
        this,
        reference,
        reference->func_00A27560(data->resourceIndex),
        reference->func_00A27600(data->resourceIndex)
    );
    LOG_ASSERT_AT(".\\ScheduleActor.cpp", 88, pDagNode != 0, "");

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

    if (data->unk_24 > 0) {
        Scheduler::ActorIterator iterator = scheduler->func_00A1C5B0("ProxyActor");
        for (s32 index = 0; iterator.func_00A21D30(); index++) {
            if (data->unk_25[index] != 0xFF) {
                Scheduler::ProxyActor* proxy = static_cast<Scheduler::ProxyActor*>(iterator.func_00A21D50());
                Scheduler::IScheduleActor* actor = parameter->func_00A1FFA0(data->unk_25[index]);
                proxy->Bind(actor);
            }
            iterator.func_00A21D80();
        }
    }

    unk_70.func_00A03C00(scheduler.get());
    scheduler->unk_B8 = &unk_70;
    unk_6C = parameter->func_00A20070();
    
    Scheduler::Scheduler::ListenerIterator listener_iterator(unk_6C);
    while (listener_iterator.func_00A1CDE0()) {
        scheduler->func_00A1BC60(listener_iterator.func_00A1BF80());
        listener_iterator.func_00A1DAB0();
    }

    unk_60 = 2;
    unk_64 = 2;
    Scheduler::ScheduleDataTransfer transfer(unk_6C->unk_F0, unk_6C->unk_1B4);
    scheduler->func_00A1BF60(&unk_70, &transfer);
    scheduler->func_00A1CE70(Scheduler::Float4(unk_6C->func_00A1C040()));
    scheduler->func_00A1CE20(Scheduler::Float4(unk_6C->func_00A1C030()));
}

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX
