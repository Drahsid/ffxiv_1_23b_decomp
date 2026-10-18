#include "Engine/Vfx/Qix/Graph/SureGenesisBuffer.h"
#include "Engine/Common/Log.h"
#include "Engine/Common/Assert.h"
#include "Engine/Vfx/Common/Io/Printer.h"
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

SureGenesisBuffer::SureGenesisBuffer(u32 arg0, s32 arg1) : BaseGenesisBuffer(arg0, arg1) {
    unk_0C = true;
}

SureGenesisBuffer::~SureGenesisBuffer() {
}

void SureGenesisBuffer::func_00BE83C0(GenesisBufferChain* arg0, u32 arg1, GenesisBufferSource* arg2) {
    if (entryCount < capacity - 1 && entryCount < capacity) {
        Entry_(arg0, entryCount, arg1, arg2);
        ++entryCount;
    }
}

void SureGenesisBuffer::Realloc(s32 arg0) {
    if (capacity > arg0) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "まだ対応してない"); // "Not supported yet"
        Common::Io::Printer::func_00415C90()->func_00415A00(100);
        LOG_ASSERTION_AT(".\\Graph\\SureGenesisBuffer.cpp", 73, false, "");
    }

    if (arg0 < capacity) {
        arg0 = entryCount;
    }

    if (arg0 == capacity) {
        return;
    }

    GenesisBufferEntry* new_entries = static_cast<GenesisBufferEntry*>(func_00416480(
        arg0 * sizeof(GenesisBufferEntry),
        0,
        16,
        __FUNCTION__,
        ".\\Graph\\SureGenesisBuffer.cpp",
        89
    ));
    if (!new_entries) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "[SureGenesisBuffer] alloc error.");
        Common::Io::Printer::func_00415C90()->func_00415A00(100);
        LOG_ASSERTION_AT(".\\Graph\\SureGenesisBuffer.cpp", 90, false, "");
    }

    if (entryCount != 0) {
        memcpy(new_entries, entries, entryCount * sizeof(GenesisBufferEntry));
    }
    
    func_004162C0(entries);
    entries = new_entries;
    capacity = arg0;
}

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
