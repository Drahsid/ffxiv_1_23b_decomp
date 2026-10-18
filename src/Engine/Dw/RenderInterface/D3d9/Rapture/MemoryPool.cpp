#include "Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool.h"
#include "Engine/Common/Log.h"
#include <string.h>

namespace {

void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function);

} // namespace

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {
namespace D3d9 {
namespace Rapture {

bool MemoryPool::Has_Pools() {
    return !memoryPools_.empty();
}

void MemoryPool::Reset() {
    pUsedPool_ = &memoryPools_[0];
    usedSize = 0;
}

u32 MemoryPool::Get_Used_Size() {
    u32 total = 0;
    u32 count = memoryPools_.size();
    for (u32 index = 0; index < count; index++) {
        if (&memoryPools_[index] == pUsedPool_) {
            total += usedSize;
            break;
        }
        total += memoryPools_[index].size;
    }
    return total;
}

MemoryPool::~MemoryPool() {
    u32 count = memoryPools_.size();
    for (u32 index = 0; index < count; index++) {
        delete[] memoryPools_[index].memory;
    }
}

MemoryPool::MemoryPool() : pUsedPool_(0), usedSize(0) {
}

void MemoryPool::Initialize(u32 size) {
    LOG_ASSERT_AT(
        "c:\\work\\project\\cdev\\src\\dw\\cdev\\engine\\dw\\renderinterface\\d3d9\\rapture\\memorypool.cpp",
        44,
        memoryPools_.empty() == true,
        ""
    );
    memoryPools_.reserve(5);
    Pool pool;
    pool.memory = new u8[size];
    pool.size = size;
    memoryPools_.push_back(pool);
    pUsedPool_ = &memoryPools_[0];
    usedSize = 0;
}

void MemoryPool::ChangeUsePool() {
    u32 count = memoryPools_.size();
    for (u32 index = 0; index < count; index++) {
        if (&memoryPools_[index] == pUsedPool_) {
            if (index == count - 1) {
                Pool pool;
                pool.memory = new u8[10240000];
                pool.size = 10240000;
                memoryPools_.push_back(pool);
            }
            pUsedPool_ = &memoryPools_[index + 1];
            LOG_ASSERT_AT(
                "c:\\work\\project\\cdev\\src\\dw\\cdev\\engine\\dw\\renderinterface\\d3d9\\rapture\\memorypool.cpp",
                183,
                pUsedPool_ != NULL,
                "メモリの取得に失敗しました" // "Failed to allocate memory"
            );
            break;
        }
    }
    usedSize = 0;
}

void* MemoryPool::Allocate_And_Copy(const void* source, u32 size) {
    if (usedSize + size >= pUsedPool_->size) {
        ChangeUsePool();
    }
    u8* memory = pUsedPool_->memory + usedSize;
    memcpy(memory, source, size);
    usedSize += size;
    return memory;
}

void* MemoryPool::Allocate(u32 size) {
    if (usedSize + size >= pUsedPool_->size) {
        ChangeUsePool();
    }
    u8* memory = pUsedPool_->memory + usedSize;
    usedSize += size;
    return memory;
}

void* MemoryPool::Allocate_Aligned_And_Copy(const void* source, u32 size, u32 alignment_shift) {
    usedSize += Get_Alignment_Padding(usedSize, alignment_shift);
    size += Get_Alignment_Padding(size, alignment_shift);
    if (usedSize + size >= pUsedPool_->size) {
        ChangeUsePool();
    }
    u8* memory = pUsedPool_->memory + usedSize;
    memcpy(memory, source, size);
    usedSize += size;
    return memory;
}

void* MemoryPool::Allocate_Aligned(u32 size, u32 alignment_shift) {
    usedSize += Get_Alignment_Padding(usedSize, alignment_shift);
    size += Get_Alignment_Padding(size, alignment_shift);
    if (usedSize + size >= pUsedPool_->size) {
        ChangeUsePool();
    }
    u8* memory = pUsedPool_->memory + usedSize;
    usedSize += size;
    return memory;
}

} // namespace Rapture
} // namespace D3d9
} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

namespace {

void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

} // namespace
