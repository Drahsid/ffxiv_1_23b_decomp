#include "Engine/Memory/ComplexLink.h"
#include "Engine/Common/Log.h"
#include <intrin.h>
#include <new>
#include <string.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Memory {

inline u32 ComplexLink::Get_Bin_Index(u32 size) {
    unsigned long index;
    if (_BitScanReverse(&index, size)) {
        return index + 1;
    }
    return 0;
}

void* ComplexLink::Allocate(AllocationParameters* parameters, u32 size, const u32* alignment_pointer, u32 arg3) {
    Block* end = &bins[0];
    void* memory = 0;
    u32 payload_size = (size + 15) & ~15;
    u32 alignment = (*alignment_pointer + 15) & ~15;
    u32 padding = 0;
    for (Block* block = bins[Get_Bin_Index(payload_size)].next; block != end; block = block->next) {
        if (!block->Is_Used()) {
            padding = (alignment - reinterpret_cast<u32>(block) - sizeof(Block)) & (alignment - 1);
            if (block->size >= padding + payload_size) {
                block->Unlink();
                u32 previous_size = block->previousSize;
                Block* allocated = block;
                if (padding) {
                    previous_size = padding - sizeof(Block);
                    Block* aligned = new (reinterpret_cast<u8*>(block) + padding) Block;
                    u32 aligned_size = block->size - padding;
                    aligned->previousSize = previous_size;
                    aligned->size = aligned_size;
                    Block* next = aligned->Get_Next();
                    next->previousSize = aligned->size;
                    block->size = previous_size;
                    bins[Get_Bin_Index(block->size)].Insert_After(block);
                    allocated = aligned;
                }

                if (allocated->size > payload_size) {
                    Block* remainder = new (reinterpret_cast<u8*>(allocated + 1) + payload_size) Block;
                    u32 remainder_size = allocated->size - payload_size - sizeof(Block);
                    remainder->previousSize = payload_size;
                    remainder->size = remainder_size;
                    Block* next = remainder->Get_Next();
                    next->previousSize = remainder->size;
                    Block* tail = bins[Get_Bin_Index(remainder->size)].Get_Next();
                    tail->previous->Insert_After(remainder);
                }

                allocated->owner = parameters;
                allocated->unk_08 = arg3;
                allocated->previousSize = previous_size;
                allocated->used = true;
                allocated->size = payload_size;
                memory = allocated + 1;

                if (parameters->unk_14) {
                    memset(memory, 0xAA, payload_size);
                }
                break;
            }
        }
    }
    return memory;
}

void ComplexLink::Free(AllocationParameters* parameters, void* memory) {
    Block* block = static_cast<Block*>(memory) - 1;
    Block* previous = block->Get_Previous();
    u32 size = block->size;
    Block* next = block->Get_Next();

    if (!previous->Is_Used()) {
        previous->Unlink();
        size += previous->size + sizeof(Block);
        block = previous;
    }

    if (!next->Is_Used()) {
        next->Unlink();
        size += next->size + sizeof(Block);
        next = next->Get_Next();
    }

    block->used = false;
    block->size = size;
    next->previousSize = size;
    bins[Get_Bin_Index(block->size)].Insert_After(block);

    if (parameters->unk_14) {
        memset(block + 1, 0xAA, block->size);
    }
}

u32 ComplexLink::Get_Allocation_Size(AllocationParameters* parameters, void* memory) {
    return (static_cast<Block*>(memory) - 1)->size;
}

ComplexLink::ComplexLink(AllocationParameters* parameters) {
    Block* begin = ::new (reinterpret_cast<u8*>(parameters) + parameters->unk_04) Block;
    begin->size = 0;
    begin->previousSize = 0;
    begin->used = true;
    Block* block = ::new (reinterpret_cast<u8*>(parameters) + parameters->unk_04 + sizeof(Block)) Block;
    block->size = parameters->allocationLimit - 3 * sizeof(Block);
    block->previousSize = begin->size;
    block->used = false;
    Block* end = ::new (reinterpret_cast<u8*>(parameters) + parameters->unk_04 + parameters->allocationLimit - sizeof(Block)) Block;
    end->size = 0;
    end->previousSize = block->size;
    end->used = true;

    for (u32 index = 0; index < BIN_COUNT - 1; index++) {
        bins[index].Insert_After(&bins[index + 1]);
    }

    for (u32 index = 0; index < BIN_COUNT; index++) {
        bins[index].used = true;
    }

    bins[Get_Bin_Index(block->size)].Insert_After(block);
}

template<class T>
inline void Defer_Default_Assert_Handler() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    Defer_Default_Assert_Handler<void>();
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void* ComplexLink::Realloc(AllocationParameters* parameters, void* memory, u32 size) {
    LOG_ASSERT_AT(".\\modules\\ComplexLink.cpp", 121, false, "");
    return 0;
}

void ComplexLink::CheckConsistency(AllocationParameters* parameters) {
    Block* block = reinterpret_cast<Block*>(reinterpret_cast<u8*>(parameters) + parameters->unk_04) + 1;
    Block* previous = block - 1;
    while (block != reinterpret_cast<Block*>(reinterpret_cast<u8*>(parameters) + parameters->unk_04 + parameters->allocationLimit) - 1) {
        {
            Block* left = previous;
            Block* right = block->Get_Previous();
            LOG_ASSERT_AT(".\\modules\\ComplexLink.cpp", 142, left == right, "");
        }

        {
            Block* left = block;
            Block* right = block->Get_Next()->Get_Previous();
            LOG_ASSERT_AT(".\\modules\\ComplexLink.cpp", 145, left == right, "");
        }

        {
            Block* left = block;
            Block* right = block->Get_Previous()->Get_Next();
            LOG_ASSERT_AT(".\\modules\\ComplexLink.cpp", 148, left == right, "");
        }
        
        previous = block;
        block = block->Get_Next();
    }

    for (block = bins[0].next; block != &bins[0]; block = block->next) {
    }

    for (block = bins[0].previous; block != &bins[0]; block = block->previous) {
    }
}

} // namespace Memory
} // namespace Engine
} // namespace CDev
} // namespace SQEX
