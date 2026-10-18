#ifndef ENGINE_VFX_QIX_DATA_UNIT_INSTANCE_H
#define ENGINE_VFX_QIX_DATA_UNIT_INSTANCE_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {

namespace DrawLayer {
struct DrawLayerEntryPrefix;
} // namespace DrawLayer

namespace Data {

class UnitData;

struct UnitInstanceSourcePrefix {
    u8 unk_00[8];
    u8 unk_08;
    u8 unk_09;
    s16 unk_0A;
    s16 unk_0C;
    u8 unk_0E[2];
    u8 unk_10;
    u8 unk_11[15];
    u32 unk_20;
    f32 unk_24;
};

struct UnitInstanceEntry {
    u32 unk_00;
    s16 unk_04;
    u8 unk_06[2];
};

class UnitInstance {
public:
    UnitInstance(const u8* arg0, UnitData* arg1);
    UnitInstance(u8 arg0, void* arg1, void* arg2, s32 arg3, const UnitInstanceEntry* arg4);
    UnitInstance(u8 arg0, void* arg1, void* arg2, const void* arg3, const void* arg4);
    ~UnitInstance();
    void func_00BD1380(u32 arg0);
    const u8* func_00BD1390();
    UnitData* func_00BD13A0();
    bool func_00BD13B0(void* arg0, void* arg1, s32 arg2, const UnitInstanceEntry* arg3);
    void Finalize_();
    void Referenced_();
    bool Unreferenced_();

private:
    u8 unk_00;
    u8 unk_01[3];
    const UnitInstanceSourcePrefix* unk_04;
    u32 unk_08;
    bool unk_0C;
    u8 unk_0D[3];
    UnitData* unk_10;
    void* unk_14;
    DrawLayer::DrawLayerEntryPrefix* unk_18;
    s16 layer;
    s16 depth;
    u16 referenceCount;
    u8 unk_22;
    u8 unk_23;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[2];
    f32 unk_28;
};

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
