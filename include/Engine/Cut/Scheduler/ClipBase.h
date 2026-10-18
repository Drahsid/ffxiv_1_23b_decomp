#ifndef ENGINE_CUT_SCHEDULER_CLIP_BASE_H
#define ENGINE_CUT_SCHEDULER_CLIP_BASE_H

#include "types.h"
#include "Engine/Cut/Common/CutSceneObject.h"
#include "Engine/Common/Misc/NonCopyable.h"
#include "Engine/Common/ISceneObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Cut {

namespace Plugins {
class IClipListenerHolder;
} // namespace Plugins

namespace Common {

template<class T>
class ListNode {
public:
    virtual ~ListNode();

private:
    T* unk_04;
    T* unk_08;
};

} // namespace Common

namespace Scheduler {

class ClipParameter;

struct ClipData {
    u8 unk_00[3];
    u8 actorIndex;
    u32 unk_04[3];
};

class IClip : public Common::CutSceneObject,
              public Engine::Common::ISceneObject::IClip,
              private Engine::Common::Misc::NonCopyable {
};

class ClipBase : public IClip, public Common::ListNode<ClipBase> {
public:
    ClipBase(const ClipData* data, void* arg1);
    virtual ~ClipBase();
    virtual void OnEnter(ClipParameter* parameter);
    virtual void func_00A20F90(ClipParameter* arg0);
    virtual void func_00A21000(u32 arg0);
    virtual void func_00A21010(u32 arg0);
    virtual u32 func_00A21030();
    virtual u32 func_00A21060();
    virtual u32 func_00A21070();
    virtual u32 func_00A21080();
    virtual u32 func_00A210A0();
    virtual void func_00A210D0(s32 arg0);
    virtual s32 func_00A210E0();
    virtual void func_00A210F0(u32 arg0);
    virtual u32 func_00A21100();
    virtual void func_00A21110(s32 arg0);
    virtual s32 func_00A21120();
    virtual const void* func_00A21130();
    virtual void func_00776340(u32 arg0);
    virtual void Set_Killed(bool killed);
    virtual bool Is_Killed();
    virtual s32 func_00A21170();
    virtual s32 func_00A21180();
    virtual s32 func_00A21190();
    virtual u32 func_00A211A0();
    virtual bool func_00A21210();
    virtual s32 func_00A211B0();
    virtual s32 func_00A211F0();
    virtual s32 func_00A211D0();
    virtual void* func_00A21230();
    virtual const void* GetData() = 0;
    virtual bool func_00B73290();
    virtual bool func_0080FA00(u32 arg0);
    virtual u32 func_00A21250();
    virtual void func_006CE2E0_84();
    virtual void func_006CE2E0_88();
    virtual bool func_005C5C80();
    virtual const void* func_00AB7340();
    virtual const void* func_00A21040(ClipParameter* parameter);
    virtual void func_00A21090(u32 arg0);
    virtual u32 func_00A210B0();
    virtual void* func_00A210C0();
    virtual u32 func_00A21220();

    static void operator delete(void* memory) {
    }

protected:
    const ClipData* mClipData;
    void* unk_18;
    u32 unk_1C[2];
    Plugins::IClipListenerHolder* unk_24;
    u32 unk_28[4];
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
