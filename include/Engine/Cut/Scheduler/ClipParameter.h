#ifndef ENGINE_CUT_SCHEDULER_CLIP_PARAMETER_H
#define ENGINE_CUT_SCHEDULER_CLIP_PARAMETER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

class ClipBase;
class IScheduleActor;
class ResourceReference;
class Scheduler;

class ClipParameter {
public:
    virtual ~ClipParameter();
    IScheduleActor* func_00A1FFA0(s32 index);
    ClipBase* Get_Clip(s32 index);
    ResourceReference* func_00A20040();
    u32 func_00A20050();
    u32 func_00A20060();
    Scheduler* func_00A20070();
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
