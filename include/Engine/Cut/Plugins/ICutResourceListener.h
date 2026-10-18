#ifndef ENGINE_CUT_PLUGINS_I_CUT_RESOURCE_LISTENER_H
#define ENGINE_CUT_PLUGINS_I_CUT_RESOURCE_LISTENER_H

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
class ClipBase;
class IScheduleActor;
class ResourceReference;
struct Resource_Id;
class Resource_Id_Type;
} // namespace Scheduler

namespace Plugins {

class ICutResourceListener {
public:
    virtual void func_00A07670() = 0;
    virtual void func_00A076B0() = 0;
    virtual Dw::SceneGraph::DagNode* func_00A076D0(
        Scheduler::ClipBase* clip,
        Scheduler::IScheduleActor* actor,
        Scheduler::ResourceReference* reference,
        const Scheduler::Resource_Id& id,
        const Scheduler::Resource_Id_Type& type
    ) = 0;
    virtual void func_00A07750() = 0;
    virtual void func_00A07760() = 0;
    virtual ~ICutResourceListener();
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
