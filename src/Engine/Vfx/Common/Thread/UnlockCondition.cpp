#include "Engine/Vfx/Common/Thread/UnlockCondition.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "Engine/Vfx/Common/Thread/Mutex.h"

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function);

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

UnlockCondition::~UnlockCondition() {
    CloseHandle(unk_A4);
    CloseHandle(unk_A8);
    CloseHandle(unk_AC);
    CloseHandle(unk_B0);
    delete mutex;
}

void UnlockCondition::func_00E3BE70() {
    WaitForSingleObject(unk_A8, INFINITE);
    mutex->func_00E3AFE0();
    unk_08++;
    s32 count = unk_08;
    s32 generation = unk_0C;
    mutex->func_00E3AFF0();
    if (waitObjectCount) {
        if (count == waitObjectCount) {
            SetEvent(unk_AC);
            SetEvent(unk_B0);
        }
        else {
            WaitForSingleObject(unk_AC, INFINITE);
        }
    }

    for (;;) {
        WaitForSingleObject(unk_A4, INFINITE);
        mutex->func_00E3AFE0();
        ResetEvent(unk_A8);
        bool released = unk_B4 > 0 && unk_0C != generation;
        if (released) {
            unk_08--;
            unk_B4--;
            if (!unk_B4) {
                ResetEvent(unk_A4);
                ResetEvent(unk_AC);
                SetEvent(unk_A8);
            }
        }

        mutex->func_00E3AFF0();
        if (released) {
            break;
        }
    }
}

void UnlockCondition::func_00E3BF70(bool arg0) {
    if (waitObjectCount) {
        WaitForSingleObject(unk_B0, INFINITE);
        ResetEvent(unk_B0);
    }

    mutex->func_00E3AFE0();
    if (!arg0) {
        if (unk_B4 < unk_08) {
            s32 index = unk_18[0];
            unk_20[0][index] = unk_08;
            unk_18[0] = (index + 1) % 8;
            unk_B4++;
            unk_10 = true;
            unk_0C++;
            SetEvent(unk_A4);
        }
        else {
            unk_20[0][15]++;
        }
    }
    else {
        if (unk_08 > 0) {
            s32 index = unk_18[1];
            unk_20[1][index] = unk_08;
            unk_18[1] = (index + 1) % 8;
            unk_10 = true;
            unk_B4 = unk_08;
            unk_0C++;
            SetEvent(unk_A4);
        }
        else {
            unk_20[1][15]++;
        }
    }

    mutex->func_00E3AFF0();
}

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#include "Engine/Vfx/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

void UnlockCondition::func_00E3C0A0() {
    func_00E3BF70(false);
}

void UnlockCondition::func_00E3C0B0() {
    func_00E3BF70(true);
}

void UnlockCondition::SetWaitObjectCount(u32 count) {
    VFX_ASSERT_AT(".\\Thread\\UnlockCondition.cpp", 116, !unk_10);
    VFX_ASSERT_AT(".\\Thread\\UnlockCondition.cpp", 117, count < 0x7FFFFFFF);
    waitObjectCount = count;
}

void UnlockCondition::AddWaitObjectCount(s32 count) {
    VFX_ASSERT_AT(".\\Thread\\UnlockCondition.cpp", 125, !unk_10);
    s32 total = waitObjectCount + count;
    VFX_ASSERT_AT(".\\Thread\\UnlockCondition.cpp", 127, total >= 0);
    waitObjectCount = total;
}

void UnlockCondition::Initialize_(s32 wait_object_count) {
    for (s32 index = 0; index < 2; index++) {
        unk_18[index] = 0;
        for (s32 entry = 0; entry < 16; entry++) {
            unk_20[index][entry] = 0;
        }
    }
    
    unk_08 = 0;
    unk_10 = false;
    waitObjectCount = wait_object_count;
    unk_A4 = CreateEventA(0, TRUE, FALSE, 0);
    unk_A8 = CreateEventA(0, TRUE, TRUE, 0);
    unk_AC = CreateEventA(0, TRUE, FALSE, 0);
    unk_B0 = CreateEventA(0, TRUE, FALSE, 0);
    unk_B4 = 0;
    unk_0C = 0;
    mutex = ::new (0, 16, __FUNCTION__, ".\\Thread\\UnlockCondition.cpp", 154) Mutex;
}

UnlockCondition::UnlockCondition(s32 wait_object_count) {
    Initialize_(wait_object_count);
}

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}
