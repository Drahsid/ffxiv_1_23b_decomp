#ifndef ENGINE_VFX_QIX_MANAGER_H
#define ENGINE_VFX_QIX_MANAGER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {

namespace DrawLayer {
class DrawLayerManager;
} // namespace DrawLayer

struct ManagerPrefix;

struct ContextPrefix {
    u32 func_00BAF3B0(u8 arg0, u32 arg1, u32 arg2);
    u32 func_00BAED70(u8 arg0, u32 arg1, u32 arg2);
    u32 func_00BAD0F0(u8 arg0, u32 arg1);
    u32 func_00BAD1B0(u8 arg0, u32 arg1, u32 arg2);

    u8 unk_00[0xBC];
    ManagerPrefix* manager;
    u8 unk_C0[4];
    DrawLayer::DrawLayerManager* drawLayerManager;
};

struct ManagerThreadParametersPrefix {
    u32 unk_00;
    s32 priority;
    u32 unk_08;
    u32 stackSize;
};

struct ManagerPrefix {
    u8 unk_00[0x6C];
    ContextPrefix* currentContext;
    u8 unk_70[0x1C];
    ManagerThreadParametersPrefix unk_8C;
};

extern "C" ManagerPrefix* func_00BAAEA0();

} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
