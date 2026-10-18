#include "Engine/Vfx/Common/Thread/ThreadManager.h"
#include "Engine/Vfx/Common/Thread/BaseThread.h"
#include "Engine/Vfx/Common/Map/UsIntMap.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include <windows.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

ThreadManager::~ThreadManager() {
    u32 count = unk_14->Get_Count();
    for (u32 index = 0; index < count; index++) {
        u32* entry = static_cast<u32*>(unk_14->Get_Entry(index));
        delete reinterpret_cast<BaseThread*>(entry[1]);
    }
    delete unk_14;
}

s32 ThreadManager::Get_Processor_Count(u32* affinity_mask) {
    HANDLE process = GetCurrentProcess();
    DWORD_PTR process_mask;
    DWORD_PTR system_mask;
    // BUG: Reads process_mask even if GetProcessAffinityMask fails
    GetProcessAffinityMask(process, &process_mask, &system_mask);
    *affinity_mask = process_mask;
    s32 count = 0;
    for (s32 index = 0; index < 32; index++) {
        if (process_mask & (1u << index)) {
            count++;
        }
    }
    
    if (!count) {
        *affinity_mask = 1;
        count = 1;
    }
    return count;
}

ThreadManager::ThreadManager(u32 capacity) : capacity(capacity), unk_08(0) {
    unk_14 = ::new (0, 16, __FUNCTION__, ".\\Thread\\ThreadManager.cpp", 33) Map::UsIntMap(capacity, false);
    processorCount = Get_Processor_Count(&affinityMask);
}

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
