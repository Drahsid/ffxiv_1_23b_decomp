#include "Engine/Memory/SystemHeap.h"
#include "Engine/Common/Log.h"
#include <malloc.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

bool SystemHeap::Has_Allocations() {
    return &allocations != allocations.next;
}

u32 SystemHeap::Get_Used_Bytes() {
    return usedBytes;
}

u32 SystemHeap::Get_Available_Physical_Memory() {
    MEMORYSTATUS status;
    GlobalMemoryStatus(&status);
    return status.dwAvailPhys;
}

void* SystemHeap::Allocate(AllocationParameters* parameters, u32 size, const u32* alignment_pointer, u32 arg3) {
    u32 alignment = *alignment_pointer;
    u32 payload_size = (size + alignment - 1) & ~(alignment - 1);
    u32 header_size = (sizeof(AllocationHeader) + alignment - 1) & ~(alignment - 1);
    u32 allocation_size = payload_size + header_size + sizeof(AllocationFooter);
    if (!parameters->allocationLimit || parameters->allocationLimit - usedBytes >= allocation_size) {
        u8* allocation = static_cast<u8*>(allocateCallback(allocation_size, alignment));
        if (allocation) {
            AllocationHeader* header = reinterpret_cast<AllocationHeader*>(allocation + header_size - sizeof(AllocationHeader));
            header->owner = parameters;
            header->payloadSize = payload_size;

            AllocationFooter* footer = header->Get_Footer();
            footer->allocation = allocation;
            footer->unk_0C = arg3;
            footer->alignment = alignment;
            footer->allocationSize = allocation_size;
            allocations.Insert_After(header);
            usedBytes += allocation_size;
            return header + 1;
        }
    }
    return 0;
}

void SystemHeap::Free(AllocationParameters* parameters, void* memory) {
    AllocationHeader* header = static_cast<AllocationHeader*>(memory) - 1;
    header->Unlink();

    AllocationFooter* footer = header->Get_Footer();
    usedBytes -= footer->allocationSize;
    freeCallback(footer->allocation);
}

void* SystemHeap::Realloc(AllocationParameters* parameters, void* memory, u32 size) {
    AllocationHeader* header = static_cast<AllocationHeader*>(memory) - 1;
    u32 old_size = header->payloadSize;
    AllocationFooter* old_footer = header->Get_Footer();
    u32 alignment = old_footer->alignment;
    u32 metadata = old_footer->unk_0C;
    u32 payload_size = (size + alignment - 1) & ~(alignment - 1);
    u32 header_size = (sizeof(AllocationHeader) + alignment - 1) & ~(alignment - 1);
    u32 allocation_size = payload_size + header_size + sizeof(AllocationFooter);
    if (!parameters->allocationLimit || parameters->allocationLimit - usedBytes >= allocation_size) {
        u8* allocation = static_cast<u8*>(allocateCallback(allocation_size, alignment));
        if (allocation) {
            void* new_memory = allocation + header_size;
            memcpy(new_memory, memory, old_size);
            header->Unlink();
            usedBytes -= old_footer->allocationSize;
            freeCallback(old_footer->allocation);
            AllocationHeader* new_header = static_cast<AllocationHeader*>(new_memory) - 1;
            new_header->payloadSize = payload_size;
            AllocationFooter* footer = new_header->Get_Footer();
            footer->allocation = allocation;
            footer->allocationSize = allocation_size;
            footer->alignment = alignment;
            footer->unk_0C = metadata;
            allocations.Insert_After(new_header);
            usedBytes += allocation_size;
        }
    }
    
    // BUG: Returns freed memory after successful reallocation
    return memory;
}

u32 SystemHeap::Get_Allocation_Size(AllocationParameters* parameters, void* memory) {
    AllocationHeader* header = static_cast<AllocationHeader*>(memory) - 1;
    return header->Get_Footer()->allocationSize;
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace {

struct System {
    static void* Allocate(u32 size, u32 alignment) {
        return _aligned_malloc(size, alignment);
    }

    static void Free(void* memory) {
        _aligned_free(memory);
    }

    static void* Realloc(void* arg0, u32 arg1, u32 arg2) {
        LOG_ASSERT_AT(".\\modules\\SystemHeap.cpp", 122, false, "");
        return 0;
    }
};

} // namespace

SystemHeap::SystemHeap(void* arg0)
    : usedBytes(0), allocateCallback(System::Allocate), freeCallback(System::Free), reallocateCallback(System::Realloc) {
}

void SystemHeap::Set_Callbacks(AllocateCallback allocate, FreeCallback free, ReallocateCallback reallocate) {
    if (!allocate) {
        allocate = System::Allocate;
    }

    allocateCallback = allocate;
    if (!free) {
        free = System::Free;
    }

    freeCallback = free;
    if (!reallocate) {
        reallocate = System::Realloc;
    }
    
    reallocateCallback = reallocate;
}

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX
