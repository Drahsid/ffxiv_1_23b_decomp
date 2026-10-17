#ifndef ENGINE_CUT_SCHEDULER_SCHEDULE_DATA_TRANSFER_H
#define ENGINE_CUT_SCHEDULER_SCHEDULE_DATA_TRANSFER_H

#include "Engine/Cut/Common/CutSceneMemoryObject.h"
#include "Engine/Cut/Scheduler/ClipBase.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Common {

class ISceneObject::IScheduleDataTransfer {
public:
    virtual ~IScheduleDataTransfer() {
    }

    virtual void func_007143E0() = 0;
    virtual void func_00CB1C80() = 0;
};

} // namespace Common

namespace Cut {
namespace Scheduler {

class ScheduleDataTransfer : public Engine::Common::ISceneObject::IScheduleDataTransfer,
                             public Common::CutSceneMemoryObject,
                             private Engine::Common::Misc::NonCopyable {
public:
    ScheduleDataTransfer(void* arg0, u32 arg1) : unk_08(arg0), unk_0C(arg1) {
    }

    virtual ~ScheduleDataTransfer() {
    }

    virtual void func_007143E0();
    virtual void func_00CB1C80();

private:
    void* unk_08;
    u32 unk_0C;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
