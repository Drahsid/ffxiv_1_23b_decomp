#include "Engine/Vfx/Qix/Data/UnitData.h"
#include "Engine/Vfx/Qix/Data/UnitInstance.h"
#include "Engine/Common/Log.h"
#include "asm.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

struct Struct_00BD2550_Entry {
    u8 unk_00[8];
    u16 unk_08;
    u8 unk_0A[2];
};

struct Struct_00BD2550_Arg0 {
    u8 unk_00[0x18];
    Struct_00BD2550_Entry* unk_18;
    s32 unk_1C;
    Struct_00BD2550_Entry* unk_20;
    s32 unk_24;
};

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Data/UnitData_Data/00BD2380.s");

UnitData::~UnitData() {
}

void UnitData::func_00BD2400(u32 arg0) {
    if (unk_08) {
        unk_04 = reinterpret_cast<UnitDataSourcePrefix*>(reinterpret_cast<u8*>(unk_04) + arg0);
    }
}

u32 UnitData::func_00BD2410() {
    return unk_00;
}

UnitDataSourcePrefix* UnitData::func_00BD2420() {
    return unk_04;
}

u32 UnitData::func_00BD2430() {
    return unk_0C;
}

UnitInstance** UnitData::func_00BD2440() {
    return unk_10;
}

u32 UnitData::func_00BD2450() {
    return unk_14;
}

u32 UnitData::func_00BD2460() {
    return unk_18;
}

u32 UnitData::func_00BD2470() {
    return unk_1C;
}

u32 UnitData::func_00BD2480() {
    return unk_20;
}

u32 UnitData::func_00BD2490() {
    UnitInstance** position = unk_10;
    UnitInstance** end = position + unk_04->unk_0C;
    u32 result = 1;
    for (; position != end; ++position) {
        result += (*position)->func_00BD13A0()->func_00BD2490();
    }
    return result;
}

u32 UnitData::func_00BD24D0() {
    UnitInstance** position = unk_10;
    UnitInstance** end = position + unk_04->unk_0C;
    u32 result = unk_04->unk_04;
    for (; position != end; ++position) {
        result += (*position)->func_00BD13A0()->func_00BD24D0();
    }
    return result;
}

u16 UnitData::func_00BD2510() {
    return unk_24;
}

u16 UnitData::func_00BD2520() {
    return unk_26;
}

u16 UnitData::func_00BD2530() {
    return unk_28;
}

u16 UnitData::func_00BD2540() {
    return unk_2A;
}

u32 UnitData::func_00BD2550(const Struct_00BD2550_Arg0* arg0, u32* arg1) {
    u32 first_total = 0;
    u32 second_total = 0;
    for (s32 index = 0; index < arg0->unk_1C; ++index) {
        first_total += arg0->unk_18[index].unk_08;
    }
    for (s32 index = 0; index < arg0->unk_24; ++index) {
        second_total += arg0->unk_20[index].unk_08;
    }
    *arg1 = second_total;
    return first_total;
}

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Data/UnitData_Data/00BD25B0.s");
INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/Data/UnitData_Data/00BD2660.s");

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
