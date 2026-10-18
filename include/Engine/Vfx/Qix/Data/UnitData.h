#ifndef ENGINE_VFX_QIX_DATA_UNIT_DATA_H
#define ENGINE_VFX_QIX_DATA_UNIT_DATA_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

struct Struct_00BD2550_Arg0;

struct UnitDataSourcePrefix {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 unk_0C;
};

class UnitInstance;

class UnitData {
public:
    ~UnitData();
    void func_00BD2400(u32 arg0);
    u32 func_00BD2410();
    UnitDataSourcePrefix* func_00BD2420();
    u32 func_00BD2430();
    UnitInstance** func_00BD2440();
    u32 func_00BD2450();
    u32 func_00BD2460();
    u32 func_00BD2470();
    u32 func_00BD2480();
    u32 func_00BD2490();
    u32 func_00BD24D0();
    u16 func_00BD2510();
    u16 func_00BD2520();
    u16 func_00BD2530();
    u16 func_00BD2540();
    static u32 func_00BD2550(const Struct_00BD2550_Arg0* arg0, u32* arg1);

private:
    u32 unk_00;
    UnitDataSourcePrefix* unk_04;
    bool unk_08;
    u32 unk_0C;
    UnitInstance** unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u16 unk_24;
    u16 unk_26;
    u16 unk_28;
    u16 unk_2A;
};

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
