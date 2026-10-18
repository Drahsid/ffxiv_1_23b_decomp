#ifndef ENGINE_CUT_SCHEDULER_ACTOR_BASE_H
#define ENGINE_CUT_SCHEDULER_ACTOR_BASE_H

#include "Engine/Cut/Common/CutSceneObject.h"
#include "types.h"
#include <vector>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

struct ActorData {
    u32 unk_00[8];
};

struct Actor_Result_00622ED0;
struct Actor_Result_00622F10;

class IScheduleActor : public Common::CutSceneObject {
public:
    virtual ~IScheduleActor() {
    }

    virtual bool func_00B73290_04() = 0;
    virtual bool func_00B73290_08() = 0;
    virtual const void* func_00A20A20() = 0;
    virtual u32 func_00A20A30() = 0;
    virtual void func_00A20BD0(void* arg0) = 0;
    virtual void func_00A20B00(void* arg0) = 0;
    virtual bool func_00622EC0() = 0;
    virtual bool func_00A20A40() = 0;
    virtual bool func_00A20A50() = 0;
    virtual u8 func_00A20A60() = 0;
    virtual u16 func_00A20A70() = 0;
    virtual u32 func_00A20A80() = 0;
    virtual u32 func_00A20A90() = 0;
    virtual void func_00776340_38(u32 arg0) = 0;
    virtual void func_00776340_3C(u32 arg0) = 0;
    virtual Actor_Result_00622ED0 func_00622ED0_40() = 0;
    virtual void func_00776340_44(u32 arg0) = 0;
    virtual Actor_Result_00622ED0 func_00622ED0_48() = 0;
    virtual void func_00776340_4C(u32 arg0) = 0;
    virtual Actor_Result_00622F10 func_00622F10() = 0;
    virtual void func_00776340_54(u32 arg0) = 0;
    virtual bool func_00B73290_58() = 0;
    virtual void* func_00AB7340() = 0;

    static void operator delete(void* memory) {
    }
};

class ActorBase : public IScheduleActor {
public:
    ActorBase(const ActorData* data, void* arg1, void* arg2);
    virtual ~ActorBase();
    virtual bool func_00B73290_04();
    virtual bool func_00B73290_08();
    virtual const void* func_00A20A20();
    virtual u32 func_00A20A30();
    virtual void func_00A20BD0(void* arg0);
    virtual void func_00A20B00(void* arg0);
    virtual bool func_00622EC0();
    virtual bool func_00A20A40();
    virtual bool func_00A20A50();
    virtual u8 func_00A20A60();
    virtual u16 func_00A20A70();
    virtual u32 func_00A20A80();
    virtual u32 func_00A20A90();
    virtual void func_00776340_38(u32 arg0);
    virtual void func_00776340_3C(u32 arg0);
    virtual Actor_Result_00622ED0 func_00622ED0_40();
    virtual void func_00776340_44(u32 arg0);
    virtual Actor_Result_00622ED0 func_00622ED0_48();
    virtual void func_00776340_4C(u32 arg0);
    virtual Actor_Result_00622F10 func_00622F10();
    virtual void func_00776340_54(u32 arg0);
    virtual bool func_00B73290_58();
    virtual void* func_00AB7340();

protected:
    const ActorData* mActorData;
    void* unk_08;
    std::vector<void*> unk_0C;
    u32 unk_1C;
    void* unk_20;
    u32 unk_24[15];
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
