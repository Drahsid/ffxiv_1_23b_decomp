#include "Engine/Vfx/Qix/Graph/BaseGenesisBuffer.h"
#include "Engine/Common/Log.h"
#include "Engine/Common/Assert.h"
#include "Engine/Vfx/Common/Io/Printer.h"
#include "Engine/Vfx/Common/Memory/Memory.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

class Struct_00BDB4F0 {
public:
    void func_00BDB4F0();
};

struct GenesisBufferSource {
    u32 unk_00;
    u32 unk_04;
    Struct_00BDB4F0* unk_08;
};

BaseGenesisBuffer::~BaseGenesisBuffer() {
    func_004162C0(entries);
}

void BaseGenesisBuffer::func_00BF7FF0() {
    previousEntryCount = entryCount;
    if (peakEntryCount < entryCount) {
        peakEntryCount = entryCount;
    }
    entryCount = 0;
}

void BaseGenesisBuffer::func_00BF8010() {
    Realloc(unk_10);
}

s32 BaseGenesisBuffer::func_00BF8020() {
    return capacity;
}

s32 BaseGenesisBuffer::func_00BF8030() {
    return entryCount;
}

GenesisBufferEntry* BaseGenesisBuffer::func_00BF8040(s32 arg0) {
    if (arg0 >= entryCount) {
        return 0;
    }
    return &entries[arg0];
}

u16 BaseGenesisBuffer::func_00BF8060(GenesisBufferEntry* arg0) {
    s32 index = arg0 - entries;
    if (index < 0 || index >= capacity) {
        return 0xFFFF;
    }
    return static_cast<u16>(index);
}

void BaseGenesisBuffer::func_00BF8080() {
    unk_0C = true;
}

void BaseGenesisBuffer::func_00BF8090() {
    unk_0C = false;
}

bool BaseGenesisBuffer::func_00BF80A0() {
    return unk_0C;
}

BaseGenesisBuffer::BaseGenesisBuffer(u32 arg0, s32 arg1) : unk_04(arg0) {
    entries = static_cast<GenesisBufferEntry*>(func_00416480(
        arg1 * sizeof(GenesisBufferEntry),
        11,
        16,
        __FUNCTION__,
        ".\\Graph\\BaseGenesisBuffer.cpp",
        27
    ));
    capacity = arg1;
    unk_10 = 0;
    entryCount = 0;
    previousEntryCount = 0;
    peakEntryCount = 0;
    unk_0C = false;
}
} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

void BaseGenesisBuffer::Entry_(GenesisBufferChain* arg0, s32 arg1, u32 arg2, GenesisBufferSource* arg3) {
    GenesisBufferEntry* entry = &entries[arg1];
    entry->unk_04 = arg3;
    entry->unk_08 = arg2;
    Struct_00BDB4F0* temp_0 = arg3->unk_08;
    entry->unk_00 = temp_0;
    
    if (arg0->headIndex < 0) {
        arg0->headIndex = static_cast<s16>(arg1);
        entry->previousIndex = -1;
    }
    else {
        if (arg0->headIndex == arg1) {
            if (entry->nextIndex < 0) {
                Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "[vfx] Entry_ error");
                Common::Io::Printer::func_00415C90()->func_00415A00(100);
                LOG_ASSERTION_AT(".\\Graph\\BaseGenesisBuffer.cpp", 80, false, "");
            }
            arg0->headIndex = entry->nextIndex;
        }
        entries[arg0->tailIndex].nextIndex = static_cast<s16>(arg1);
        entry->previousIndex = arg0->tailIndex;
    }

    entry->nextIndex = -1;
    arg0->tailIndex = static_cast<s16>(arg1);
    temp_0->func_00BDB4F0();
}

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
