#ifndef ENGINE_VFX_QIX_CONTROL_ABSTRACT_LEAF_COLOR_RGBA_H
#define ENGINE_VFX_QIX_CONTROL_ABSTRACT_LEAF_COLOR_RGBA_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Control {

struct LeafColorContext;
struct LeafColorCallbackOwner;

class AbstractLeafColorRGBA {
public:
    static void ByQix_Static_(LeafColorContext* arg0, void* arg1);
    static void func_00BD9CF0(LeafColorContext* arg0, u32 arg1);
    static void* func_00BD9D20(LeafColorContext* arg0);
    static u32 func_00BD9D50(LeafColorContext* arg0);
    static u32 func_00BD9D80(LeafColorContext* arg0, u32* arg1);
    static u32 func_00BD9DC0(LeafColorContext* arg0);
    static bool func_00BD9DF0(LeafColorContext* arg0);
    static bool func_00BD9E20(LeafColorContext* arg0);
    static void func_00BD9E50(LeafColorContext* arg0, u32 arg1);
    static void func_00BD9E80(LeafColorContext* arg0, u32 arg1);
    static bool func_00BD9EB0(LeafColorContext* arg0);
    static void func_00BD9EE0(LeafColorContext* arg0, u32 arg1);
    static bool func_00BD9F10(LeafColorContext* arg0, u32 arg1);
    static void GetDistanceClip_Static(LeafColorCallbackOwner* arg0, u32 arg1, f32* arg2, f32* arg3);
};

} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
