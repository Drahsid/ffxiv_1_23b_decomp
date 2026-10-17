#ifndef ENGINE_CUT_CUT_SCENE_PLAYER_CUT_SCENE_OBJECT_H
#define ENGINE_CUT_CUT_SCENE_PLAYER_CUT_SCENE_OBJECT_H

#include "Engine/Cut/Common/CutSceneMemoryObject.h"
#include "Engine/Cut/Scheduler/ClipBase.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {

namespace Scheduler {
class Scheduler;
} // namespace Scheduler

namespace CutScenePlayer {

class CutSceneObject : public Common::CutSceneMemoryObject, private Engine::Common::Misc::NonCopyable {
public:
    CutSceneObject(u32 arg0);
    virtual ~CutSceneObject();
    void func_00A03C00(Scheduler::Scheduler* scheduler);

private:
    Scheduler::Scheduler* unk_08;
    u32 unk_0C;
    u32 unk_10[5];
    f32 unk_24;
};

} // namespace CutScenePlayer
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
