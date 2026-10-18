#include "Engine/Vfx/Qix/Thread/EffectThread.h"
#include "Engine/Vfx/Common/Log.h"
#include "Engine/Vfx/Qix/Thread/ThreadManager.h"
#include "Engine/Vfx/Qix/Manager.h"
#include "Engine/Vfx/Common/Thread/UnlockCondition.h"
#include <stdio.h>

u32 func_00BB9920(u32 arg0);

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Thread {

extern "C" bool D_01304127;
extern "C" u32 D_01368020;
extern "C" void (*D_01368024)(void*);
extern "C" ThreadSyncPrefix D_01369F68;

extern "C" void func_00BD6360(void* arg0) {
}

void EffectThread::func_00BDCC10() {
    char name[1024];
    _snprintf_s(name, sizeof(name), sizeof(name) - 1, "vfx-qix-effect-thread-%d", unk_30);
    ManagerPrefix* manager = static_cast<ThreadManagerPrefix*>(unk_04)->context->manager;
    ManagerThreadParametersPrefix* parameters = &manager->unk_8C;
    BaseThread::func_00BDCCF0(parameters->priority, parameters->stackSize, name);
    BaseThread::func_00BDCC10();
}

void EffectThread::func_00BD63E0() {
    unk_40 = 0;
    unk_44 = 0;
    unk_48 = 0;
    unk_4C = 0;
}

EffectThread::EffectThread(ThreadManager* arg0, u8 arg1) : BaseThread(arg0, arg1) {
    unk_38 = 0xFF;
    unk_3C = 0xFF;
    func_00BB9920(reinterpret_cast<u32>(arg0));
    unk_40 = 0;
    unk_44 = 0;
    unk_48 = 0;
    unk_4C = 0;
}

EffectThread::~EffectThread() {
    D_01369F68.unk_14->AddWaitObjectCount(-1);
    if (--D_01369F68.unk_18 == 0) {
        D_01304127 = true;
    }
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void EffectThread::Callback_Static(u64 arg0) {
    EffectThread* thread = reinterpret_cast<EffectThread*>(static_cast<u32>(arg0));
    u8 index = thread->unk_30;
    while (true) {
        thread->unk_3C = thread->unk_38;
        thread->unk_38 = 0xFE;
        s32 result = D_01369F68.func_00BDCDB0();
        if (result == -1) {
            break;
        }

        if (result == -3) {
            ThreadManagerPrefix* manager = static_cast<ThreadManagerPrefix*>(thread->unk_04);
            ContextPrefix* context = manager->context;
            u32 argument = manager->unk_7C;
            u32 mode = D_01368020;
            u32 temp_0 = D_01369F68.unk_04;
            thread->unk_38 = mode;
            switch (mode) {
            case 0:
                thread->unk_40 = context->func_00BAF3B0(index, temp_0, argument);
                break;
            case 1:
                thread->unk_44 = context->func_00BAED70(index, temp_0, argument);
                break;
            case 2:
                thread->unk_48 = context->func_00BAD0F0(index, temp_0);
                break;
            case 3:
                thread->unk_4C = context->func_00BAD1B0(index, temp_0, argument);
                break;
            default:
                Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "unknown update type = %#x\n", mode);
                VFX_ASSERT_AT(".\\Thread\\EffectThread.cpp", 197, false);
                break;
            }
        }
        
        if (D_01368024) {
            D_01368024(thread);
        }
        D_01369F68.func_00BDCE00();
    }
}

} // namespace Thread
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
