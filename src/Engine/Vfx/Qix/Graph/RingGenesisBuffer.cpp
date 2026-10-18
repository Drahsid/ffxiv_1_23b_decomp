#include "Engine/Vfx/Qix/Graph/RingGenesisBuffer.h"
#include "Engine/Common/Assert.h"
#include "Engine/Vfx/Common/Log.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include <string.h>

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

RingGenesisBuffer::RingGenesisBuffer(u32 arg0, s32 arg1) : BaseGenesisBuffer(arg0, arg1) {
    unk_24 = 0;
    unk_0C = false;
}

RingGenesisBuffer::~RingGenesisBuffer() {
}

void RingGenesisBuffer::func_00BE83C0(GenesisBufferChain* arg0, u32 arg1, GenesisBufferSource* arg2) {
    Entry_(arg0, (entryCount + unk_24) % capacity, arg1, arg2);
    if (entryCount < capacity) {
        ++entryCount;
    }
    else {
        unk_24 = (unk_24 + 1) % capacity;
    }
}

void RingGenesisBuffer::func_00BF7FF0() {
    unk_24 = 0;
    entryCount = 0;
}

GenesisBufferEntry* RingGenesisBuffer::func_00BF8040(s32 arg0) {
    s32 index = arg0 - unk_24;
    if (index < 0) {
        index += capacity;
    }

    if (index >= entryCount) {
        return 0;
    }
    
    return &entries[arg0];
}

void RingGenesisBuffer::Realloc(s32 arg0) {
    Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "まだ対応してない"); // "Not supported yet"
    VFX_ASSERT_AT(".\\Graph\\RingGenesisBuffer.cpp", 79, false);
    if (arg0 == capacity) {
        return;
    }

    GenesisBufferEntry* new_entries = static_cast<GenesisBufferEntry*>(func_00416480(
        arg0 * sizeof(GenesisBufferEntry),
        0,
        16,
        __FUNCTION__,
        ".\\Graph\\RingGenesisBuffer.cpp",
        89
    ));
    if (!new_entries) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "[RingGenesisBuffer] alloc error.");
        Common::Io::Printer::func_00415C90()->func_00415A00(100);
        LOG_ASSERTION_AT(".\\Graph\\RingGenesisBuffer.cpp", 90, false, "");
    }

    s32 start_index = unk_24;
    s32 copy_count = entryCount;
    if (entryCount > arg0) {
        start_index = (entryCount - arg0 + unk_24) % capacity;
        copy_count = arg0;
    }

    s32 new_count = 0;
    if (entryCount != 0) {
        s32 end_index = start_index + copy_count;
        if (end_index > capacity) {
            s32 first_count = capacity - start_index;
            memcpy(new_entries, entries + start_index, first_count * sizeof(GenesisBufferEntry));
            s32 remaining_count = end_index % capacity;
            memcpy(new_entries + first_count, entries, remaining_count * sizeof(GenesisBufferEntry));
            new_count = remaining_count + first_count;
        }
        else {
            // BUG: Shrinking can overflow the new buffer if assertions return
            memcpy(new_entries, entries + unk_24, entryCount * sizeof(GenesisBufferEntry));
            new_count = entryCount;
        }
    }

    func_004162C0(entries);
    entryCount = new_count;
    entries = new_entries;
    unk_24 = 0;
    capacity = arg0;
}

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
