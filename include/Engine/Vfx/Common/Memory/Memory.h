#ifndef ENGINE_VFX_COMMON_MEMORY_MEMORY_H
#define ENGINE_VFX_COMMON_MEMORY_MEMORY_H

#include "types.h"
#include <stddef.h>

struct Memory_Stats {
    u32 count;
    u32 size;
    u32 allocationCount;
    u32 freeCount;
    u32 failureCount;
    u32 unsizedFreeCount;
};

typedef void* (*Allocation_Callback)(u32 size, u32 arg1, u32 alignment, const char* function, const char* file, s32 line);
typedef void (*Free_Callback)(void* memory);
typedef u32 (*Size_Callback)(void* memory);

extern "C" void func_004162A0();
extern "C" void func_004162C0(void* memory);
extern "C" void func_00416310(void* arg0);
extern "C" void func_00416320();
extern "C" Memory_Stats* func_00416350();
extern "C" void func_00416360(u32 base, u32 size);
extern "C" void func_00416380();
void func_00416400(
    Allocation_Callback allocation_callback,
    Free_Callback free_callback,
    void (*arg2)(void*),
    Size_Callback size_callback,
    void (*arg4)()
);
void* func_00416480(u32 size, u32 arg1, u32 alignment, const char* function, const char* file, s32 line);

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
inline void* operator new(size_t size, void* memory) {
    return memory;
}

inline void operator delete(void* memory, void* place) {
}
#endif

inline void* operator new(size_t size, u32 arg1, u32 alignment, const char* function, const char* file, s32 line) {
    return func_00416480(size, arg1, alignment, function, file, line);
}

inline void operator delete(void* memory, u32 arg1, u32 alignment, const char* function, const char* file, s32 line) {
    func_004162C0(memory);
}

#endif
