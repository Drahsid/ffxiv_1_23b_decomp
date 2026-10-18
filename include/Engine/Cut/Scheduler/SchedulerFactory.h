#ifndef ENGINE_CUT_SCHEDULER_SCHEDULER_FACTORY_H
#define ENGINE_CUT_SCHEDULER_SCHEDULER_FACTORY_H

#include "Engine/Cut/Common/CutSceneMemoryObject.h"
#include "Engine/Common/Misc/NonCopyable.h"
#include "types.h"
#include <memory>

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Dw {
namespace SceneGraph {
class DagNode;
} // namespace SceneGraph
} // namespace Dw

namespace Cut {
namespace Scheduler {

class Scheduler;

class SchedulerFactory : public Common::CutSceneMemoryObject, private Engine::Common::Misc::NonCopyable {
public:
    SchedulerFactory(Dw::SceneGraph::DagNode* dagNode, void* arg1, u32 arg2, u32 arg3, Scheduler* scheduler);
    virtual ~SchedulerFactory();
    virtual std::auto_ptr<Scheduler> func_00A26640(u32 arg0);
    virtual void func_00A25B70();
    virtual void func_00A267F0();

private:
    void* unk_08;
    Dw::SceneGraph::DagNode* unk_0C;
    u32 unk_10;
    u32 unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
