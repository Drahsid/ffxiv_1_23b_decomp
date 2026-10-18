#include "Engine/Vfx/Qix/Data/UnitInstance.h"
#include "Engine/Vfx/Qix/Manager.h"
#include "Engine/Vfx/Common/Log.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "Engine/Common/Assert.h"
#include "Engine/Vfx/Qix/DrawLayer/DrawLayerManager.h"
#include "asm.h"

extern "C" u32 D_01369F50;
extern "C" u8 func_00BE7580(const void* arg0, const void* arg1, SQEX::CDev::Engine::Vfx::Qix::Data::UnitInstanceEntry* arg2);

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

UnitInstance::~UnitInstance() {
    if (unk_14) {
        func_004162C0(unk_14);
        unk_14 = 0;
    }
}

void UnitInstance::func_00BD1380(u32 arg0) {
    if (unk_0C) {
        unk_04 = reinterpret_cast<const UnitInstanceSourcePrefix*>(reinterpret_cast<const u8*>(unk_04) + arg0);
    }
}

const u8* UnitInstance::func_00BD1390() {
    return reinterpret_cast<const u8*>(unk_04);
}

UnitData* UnitInstance::func_00BD13A0() {
    return unk_10;
}

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Data/UnitInstance_Data/00BD13B0.s");

void UnitInstance::Finalize_() {
    unk_00 = 0;
    referenceCount = 0;
    switch (unk_04->unk_10) {
    case 0:
        unk_23 = 0;
        break;
    case 1:
        unk_23 = 2;
        break;
    case 2:
        unk_23 = 1;
        break;
    default:
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "unknown random life type.(type=%d)", unk_04->unk_10);
        Common::Io::Printer::func_00415C90()->func_00415A00(100);
        LOG_ASSERTION_AT(".\\Data\\UnitInstance_Data.cpp", 580, false, "");
        break;
    }
    DrawLayer::DrawLayerManager* manager = func_00BAAEA0()->currentContext->drawLayerManager;
    unk_18 = manager->func_00BD4F40(unk_04->unk_08);
    switch (unk_04->unk_09) {
    case 0:
        unk_22 = 0;
        unk_24 = 0;
        layer = unk_18->unk_14;
        break;
    case 1:
        unk_22 = 1;
        unk_24 = 1;
        layer = 0;
        break;
    case 2:
        unk_22 = 2;
        unk_24 = 0;
        layer = unk_04->unk_0C;
        break;
    case 3:
        unk_00 |= 1;
        unk_22 = 3;
        unk_24 = 0;
        layer = unk_04->unk_0C;
        break;
    default:
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "unknown ot type.(type=%d)", unk_04->unk_09);
        Common::Io::Printer::func_00415C90()->func_00415A00(100);
        LOG_ASSERTION_AT(".\\Data\\UnitInstance_Data.cpp", 611, false, "");
        break;
    }
    depth = unk_04->unk_0A;
    s32 depth_count = unk_18->unk_0C;
    s32 layer_count = unk_18->unk_10;
    if (!(0 <= depth && depth_count > depth)) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 2, "fixed ot depth error. (depth=%d)", depth);
        depth = 0;
    }
    if (!(0 <= layer && layer_count > layer)) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 2, "fixed ot layer error. (layer=%d)", layer);
        layer = 0;
    }
    depth = depth_count - depth - 1;
    layer = layer_count - layer - 1;
    unk_28 = 0.0f;
    if (unk_04->unk_20 & 1) {
        unk_28 = unk_04->unk_24;
    }
}

void UnitInstance::Referenced_() {
    VFX_ASSERT_AT(".\\Data\\UnitInstance_Data.cpp", 653, referenceCount < 0xFFFF);
    ++referenceCount;
}

bool UnitInstance::Unreferenced_() {
    VFX_ASSERT_AT(".\\Data\\UnitInstance_Data.cpp", 660, referenceCount != 0);
    --referenceCount;
    return referenceCount == 0;
}

UnitInstance::UnitInstance(const u8* arg0, UnitData* arg1) {
    D_01369F50 = 0;
    unk_04 = reinterpret_cast<const UnitInstanceSourcePrefix*>(arg0);
    unk_25 = 0x48;
    unk_10 = arg1;
    unk_14 = 0;
    unk_0C = true;
    unk_08 = 0;
    Finalize_();
}

UnitInstance::UnitInstance(u8 arg0, void* arg1, void* arg2, const void* arg3, const void* arg4) {
    UnitInstanceEntry entries[256];
    D_01369F50 = 0;
    unk_25 = arg0;
    u8 count = func_00BE7580(arg3, arg4, entries);
    if (func_00BD13B0(arg1, arg2, count, entries)) {
        Finalize_();
    }
}

UnitInstance::UnitInstance(u8 arg0, void* arg1, void* arg2, s32 arg3, const UnitInstanceEntry* arg4) {
    D_01369F50 = 0;
    unk_25 = arg0;
    if (func_00BD13B0(arg1, arg2, arg3, arg4)) {
        Finalize_();
    }
}

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
