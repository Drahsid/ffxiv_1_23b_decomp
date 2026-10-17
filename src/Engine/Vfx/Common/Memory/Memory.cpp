#include "Engine/Vfx/Common/Io/File.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "Engine/Vfx/Common/Memory/MemoryMap.h"

#include <stdlib.h>
#include <string.h>

extern u8 gMemoryMapBuffer[sizeof(SQEX::CDev::Engine::Vfx::Common::Memory::MemoryMap)];
extern "C" u32 D_01328D88;
extern "C" u32 D_01328D8C;

Memory_Stats gMemoryStats = {0};
Allocation_Callback gAllocationCallback = 0;
Free_Callback gFreeCallback = 0;
extern "C" void (*D_01328D70)(void* arg0) = 0;
Size_Callback gSizeCallback = 0;
extern "C" void (*D_01328D78)() = 0;
bool gTrackStats = false;
extern "C" u8 D_01328D7D = 0;
SQEX::CDev::Engine::Vfx::Common::Memory::MemoryMap* gMemoryMap = 0;

extern "C" void func_004162A0() {
    if (gMemoryMap) {
        gMemoryMap->~MemoryMap();
        gMemoryMap = 0;
    }
}

extern "C" void func_004162C0(void* memory) {
    u32 size = gSizeCallback(memory);
    gFreeCallback(memory);
    if (gTrackStats) {
        gMemoryStats.freeCount++;
        gMemoryStats.count--;
        if (size) {
            gMemoryStats.size -= size;
        }
        else {
            gMemoryStats.unsizedFreeCount++;
        }
    }
}

extern "C" void func_00416310(void* arg0) {
    D_01328D70(arg0);
}

extern "C" void func_00416320() {
    gMemoryStats.size = 0;
    gMemoryStats.count = 0;
    gMemoryStats.allocationCount = 0;
    gMemoryStats.freeCount = 0;
    gMemoryStats.failureCount = 0;
    gMemoryStats.unsizedFreeCount = 0;
    gTrackStats = true;
}

extern "C" Memory_Stats* func_00416350() {
    gTrackStats = false;
    return &gMemoryStats;
}

extern "C" void func_00416360(u32 base, u32 size) {
    u32 aligned = (base + 15) & ~15;
    D_01328D88 = aligned;
    D_01328D8C = base - aligned + size;
}

extern "C" void func_00416380() {
    D_01328D88 = 0;
    D_01328D8C = 0;
}

extern "C" void* func_00416390(u32 size, u32 arg1, u32 alignment, const char* function, const char* file, s32 line) {
    return malloc(size);
}

extern "C" void func_004163A0(void* memory) {
    if (memory) {
        free(memory);
    }
}

extern "C" void func_004163C0(void* arg0) {
}

extern "C" u32 func_004163D0(void* memory) {
    return 0;
}

extern "C" void func_004163E0() {
}

extern "C" void func_004163F0() {
}

void func_00416400(
    Allocation_Callback allocation_callback,
    Free_Callback free_callback,
    void (*arg2)(void*),
    Size_Callback size_callback,
    void (*arg4)()
) {
    if (!gAllocationCallback) {
        gAllocationCallback = allocation_callback;
        gFreeCallback = free_callback;
        D_01328D70 = arg2;
        gSizeCallback = size_callback;
        D_01328D78 = arg4;
        gMemoryMap = reinterpret_cast<SQEX::CDev::Engine::Vfx::Common::Memory::MemoryMap*>(gMemoryMapBuffer);
        ::new (gMemoryMap) SQEX::CDev::Engine::Vfx::Common::Memory::MemoryMap(1, 0, true);
    }
}

void* func_00416480(u32 size, u32 arg1, u32 alignment, const char* function, const char* file, s32 line) {
    if (!gAllocationCallback) {
        func_00416400(func_00416390, func_004163A0, func_004163C0, func_004163D0, func_004163E0);
    }
    D_01328D7D = arg1;
    void* memory = gAllocationCallback(size, arg1, alignment, function, file, line);
    if (gTrackStats) {
        if (memory) {
            gMemoryStats.count++;
            gMemoryStats.allocationCount++;
            gMemoryStats.size += (size + alignment - 1) & ~(alignment - 1);
        }
        else {
            gMemoryStats.failureCount++;
        }
    }
    return memory;
}

extern "C" void func_00416580() {
}

extern "C" void func_00416590(u32 arg0) {
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Io {

File::File() {
    unk_04 = 0;
    unk_00 = 0;
    unk_05 = 0;
    unk_06 = 0;
}

u8 File::func_004165B0(const char* path, s32 arg1) {
    u8 value = unk_04 & 1;
    return value;
}

u8 File::func_004165C0() {
    return 0;
}

u8 File::func_004165D0(u32 arg0, u32 arg1) {
    return 0;
}

u8 File::func_004165E0(const char* text, s32 arg1) {
    u8 value = unk_04 & 1;
    return value;
}

extern "C" u8 __stdcall func_004165F0(u32 arg0) {
    return 0;
}

extern "C" u8 __stdcall func_00416600(u32 arg0) {
    return 0;
}

extern "C" void func_00416610(char* path) {
    u32 length = strlen(path);
    for (u32 index = 0; index < length; index++) {
        if (path[index] == '\\') {
            path[index] = '/';
        }
    }
}

void File::func_00416650() {
}

} // namespace Io
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
