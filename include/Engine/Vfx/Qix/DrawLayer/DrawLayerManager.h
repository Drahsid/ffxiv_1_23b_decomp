#ifndef ENGINE_VFX_QIX_DRAW_LAYER_DRAW_LAYER_MANAGER_H
#define ENGINE_VFX_QIX_DRAW_LAYER_DRAW_LAYER_MANAGER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Common {
namespace ISceneObject {
namespace DrawLayer {
class IDrawLayerManager;
} // namespace DrawLayer
} // namespace ISceneObject
} // namespace Common

namespace Vfx {
namespace Qix {
namespace DrawLayer {

struct DrawLayerEntryPrefix {
    DrawLayerEntryPrefix();
    void func_00BE8730(s8 arg0, const void* arg1, const void* arg2);

    u8 unk_00[6];
    bool unk_06;
    u8 unk_07;
    u32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
    u8 unk_16[2];
    u32 unk_18;
    u32 unk_1C;
};

class DrawLayerManager {
public:
    DrawLayerEntryPrefix* func_00BD4F40(s8 arg0);
    void func_00BD4FB0();
    void Initialize(::SQEX::CDev::Engine::Common::ISceneObject::DrawLayer::IDrawLayerManager* arg0);

private:
    DrawLayerEntryPrefix* unk_00;
    s32 unk_04;
};

} // namespace DrawLayer
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
