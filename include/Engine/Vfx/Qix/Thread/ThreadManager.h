#ifndef ENGINE_VFX_QIX_THREAD_THREAD_MANAGER_H
#define ENGINE_VFX_QIX_THREAD_THREAD_MANAGER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {

namespace Common {
namespace Thread {
class UnlockCondition;
} // namespace Thread
} // namespace Common

namespace Qix {

struct ContextPrefix;

namespace Thread {

struct ThreadManagerPrefix {
    u8 unk_00[0x18];
    ContextPrefix* context;
    u8 unk_1C[0x60];
    u32 unk_7C;
};

struct ThreadSyncPrefix {
    s32 func_00BDCDB0();
    void func_00BDCE00();

    s32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void* unk_10;
    Common::Thread::UnlockCondition* unk_14;
    u32 unk_18;
    ThreadManagerPrefix* unk_1C;
};

} // namespace Thread
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
