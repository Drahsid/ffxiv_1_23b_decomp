#include "Engine/Vfx/Common/Thread/BaseThread.h"
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Thread_Name_Info {
    DWORD type;
    LPCSTR name;
    DWORD threadId;
    DWORD flags;
};

static Thread_Name_Info sThreadNameInfo;

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

BaseThread::BaseThread(const char* name, s32 priority, u32 stack_size, u64 arg3) {
    stackSize = stack_size;
    semaphore = 0;
    unk_0C = 0;
    unk_10 = -1;
    unk_3C = 0;
    this->priority = priority;
    unk_08 = static_cast<u32>(arg3);

    u32 length = strlen(name);
    if (length > sizeof(this->name) - 1) {
        length = sizeof(this->name) - 1;
    }

    if (length != 0) {
        memcpy(this->name, name, length);
        this->name[length] = '\0';
    }
    else {
        memset(this->name, 0, sizeof(this->name));
        _snprintf_s(this->name, sizeof(this->name), sizeof(this->name) - 1, "Vfx-Thread.?");
    }
}

void BaseThread::func_00E3B100() {
    if (unk_3C & 1) {
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
        unk_3C &= ~1;
    }
}

void BaseThread::func_00E3B130(u32 thread_id, const char* thread_name) {
    sThreadNameInfo.type = 0x1000;
    sThreadNameInfo.name = thread_name;
    sThreadNameInfo.threadId = thread_id;
    sThreadNameInfo.flags = 0;
    __try {
        RaiseException(0x406D1388, 0, sizeof(sThreadNameInfo) / sizeof(DWORD), reinterpret_cast<DWORD*>(&sThreadNameInfo));
    }
    __except (EXCEPTION_CONTINUE_EXECUTION) {
    }
}

u32 __stdcall BaseThread::func_00E3B1C0(void* arg0) {
    BaseThread* base_thread = static_cast<BaseThread*>(arg0);
    if (base_thread->semaphore) {
        ReleaseSemaphore(base_thread->semaphore, 1, 0);
    }

    base_thread->func_00E3FAA0();
    base_thread->func_00E3B100();
    _endthreadex(0);
    return 0;
}

extern "C" void func_00E3B210(u64 arg0) {
    SleepEx(static_cast<DWORD>(arg0 / 1000), FALSE);
}

extern "C" void func_00E3B230() {
    Sleep(0);
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

BaseThread::~BaseThread() {
    func_00E3B100();
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void BaseThread::CreateThread_() {
    func_00E3B100();
    Io::func_004160E0(Io::Printer::func_00415C90(), 4, "[BaseThread(x%08x)]create thread.", this);
    semaphore = 0;
    semaphore = CreateSemaphoreA(0, 0, 1, 0);
    u32 thread_id;
    thread = reinterpret_cast<HANDLE>(_beginthreadex(0, stackSize, func_00E3B1C0, this, 0, &thread_id));
    if (!thread) {
        Io::func_004160E0(Io::Printer::func_00415C90(), 0, "not create thread.");
        VFX_ASSERT_AT(".\\Thread\\BaseThread.cpp", 102, false);
    }
    
    SetThreadPriority(thread, priority);
    WaitForSingleObject(semaphore, INFINITE);
    CloseHandle(semaphore);
    func_00E3B130(thread_id, name);
    unk_3C |= 1;
}

void BaseThread::func_00E3B450() {
    if (!(unk_3C & 1)) {
        CreateThread_();
    }
}

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
