#ifndef ENGINE_CUT_SCHEDULER_SCHEDULER_H
#define ENGINE_CUT_SCHEDULER_SCHEDULER_H

#include "Engine/Cut/Common/CutSceneMemoryObject.h"
#include "Engine/Common/ISceneObject.h"
#include "Engine/Cut/Scheduler/Float4.h"
#include "Engine/Cut/Scheduler/ScheduleRegister.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {

namespace CutScenePlayer {
class CutSceneObject;
} // namespace CutScenePlayer

namespace Scheduler {

class ActorIterator;
class ResourceReference;

class Scheduler {
public:
    class ListenerIterator : public Common::CutSceneMemoryObject {
    public:
        ListenerIterator(Scheduler* scheduler);

        virtual ~ListenerIterator() {
        }

        void* func_00A1BF80();
        bool func_00A1CDE0();
        void func_00A1DAB0();

    private:
        u32 unk_04[4];
        void* unk_14;
        u32 unk_18;
    };

    virtual ~Scheduler();
    virtual void func_00A19210();
    virtual void func_00A19190();
    virtual void func_00A191B0();
    virtual void func_00A191D0();
    virtual void func_00A191F0();
    virtual void func_00A19230();
    virtual void func_00A19250();
    virtual void func_00A19270();
    virtual void func_00A192E0();
    virtual void func_00A19330();
    virtual void func_00A1F0C0();

    void Execute();
    const char* func_00A1B700(u32 index);
    const u32* func_00A1B7F0();
    void func_00A1B7D0(u32 arg0);
    bool func_00A1BC60(void* arg0);
    void func_00A1BCB0();
    void func_00A1BF60(CutScenePlayer::CutSceneObject* arg0, Engine::Common::ISceneObject::IScheduleDataTransfer* arg1);
    const Float4& func_00A1C030();
    const Float4& func_00A1C040();
    ActorIterator func_00A1C5B0(const char* name);
    void func_00A1CE20(const Float4& arg0);
    void func_00A1CE70(const Float4& arg0);

    u32 unk_04[28];
    ResourceReference* unk_74;
    u32 unk_78[6];
    u8 unk_90;
    u8 unk_91[3];
    u32 unk_94[9];
    CutScenePlayer::CutSceneObject* unk_B8;
    u32 unk_BC[13];
    ScheduleRegister registers;
    u32 unk_1B4;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
