#ifndef ENGINE_CUT_SCHEDULER_ACTOR_ITERATOR_H
#define ENGINE_CUT_SCHEDULER_ACTOR_ITERATOR_H

#include "Engine/Cut/Common/CutSceneMemoryObject.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

class IScheduleActor;

class ActorIterator : public Common::CutSceneMemoryObject {
public:
    virtual ~ActorIterator();
    bool func_00A21D30();
    IScheduleActor* func_00A21D50();
    void func_00A21D80();

private:
    s32 unk_04;
    s32 unk_08;
    void* unk_0C;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
