#ifndef ENGINE_VFX_QIX_THREAD_EFFECT_THREAD_H
#define ENGINE_VFX_QIX_THREAD_EFFECT_THREAD_H

#include "Engine/Vfx/Common/Object.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Thread {

class ThreadManager;

typedef void (*ThreadCallback)(u64 arg0);

class BaseThread : public Common::Object {
public:
    BaseThread(ThreadManager* arg0, u8 arg1);
    virtual ~BaseThread();
    void func_00BDCCF0(s32 arg0, u32 arg1, const char* arg2);
    virtual void func_00BDCC10();
    virtual ThreadCallback func_00BD66F0() = 0;

protected:
    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
    char unk_10[32];
    u8 unk_30;
    u8 unk_31[3];
    void* unk_34;
};

class EffectThread : public BaseThread {
public:
    EffectThread(ThreadManager* arg0, u8 arg1);
    virtual ~EffectThread();
    virtual void func_00BDCC10();
    virtual ThreadCallback func_00BD66F0() {
        return Callback_Static;
    }
    void func_00BD63E0();
    static void Callback_Static(u64 arg0);

private:
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
};

} // namespace Thread
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
