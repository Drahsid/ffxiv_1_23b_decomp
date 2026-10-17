#ifndef ENGINE_VFX_COMMON_THREAD_UNLOCK_CONDITION_H
#define ENGINE_VFX_COMMON_THREAD_UNLOCK_CONDITION_H

#include "Engine/Vfx/Common/Memory/NonCopyable.h"
#include "Engine/Vfx/Common/Object.h"
#include "types.h"
#include <windows.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

class Mutex;

class UnlockCondition : public Object, public Memory::NonCopyable {
public:
    UnlockCondition(s32 wait_object_count);
    virtual ~UnlockCondition();

    void func_00E3BE70();
    void func_00E3BF70(bool arg0);
    void func_00E3C0A0();
    void func_00E3C0B0();
    void SetWaitObjectCount(u32 count);
    void AddWaitObjectCount(s32 count);

private:
    void Initialize_(s32 wait_object_count);

    volatile s32 unk_08;
    volatile s32 unk_0C;
    bool unk_10;
    s32 waitObjectCount;
    volatile s32 unk_18[2];
    volatile s32 unk_20[2][16];
    Mutex* mutex;
    HANDLE unk_A4;
    HANDLE unk_A8;
    HANDLE unk_AC;
    HANDLE unk_B0;
    volatile s32 unk_B4;
};

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
