#ifndef ENGINE_VFX_COMMON_THREAD_BASE_THREAD_H
#define ENGINE_VFX_COMMON_THREAD_BASE_THREAD_H

#include "Engine/Vfx/Common/Object.h"
#include "types.h"
#include <windows.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

extern "C" void func_00E3B210(u64 arg0);
extern "C" void func_00E3B230();

class BaseThread : public Object {
public:
    BaseThread(const char* name, s32 priority, u32 stack_size, u64 arg3);
    virtual ~BaseThread();

    void func_00E3B100();
    void CreateThread_();
    void func_00E3B450();

protected:
    virtual void func_00E3FAA0() = 0;

    HANDLE thread;
    u32 unk_08;
    u32 unk_0C;
    s32 unk_10;
    s32 priority;
    u32 stackSize;
    char name[32];
    u8 unk_3C;
    HANDLE semaphore;

private:
    void func_00E3B130(u32 thread_id, const char* thread_name);

    static u32 __stdcall func_00E3B1C0(void* arg0);
};

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
