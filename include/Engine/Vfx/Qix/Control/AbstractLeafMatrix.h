#ifndef ENGINE_VFX_QIX_CONTROL_ABSTRACT_LEAF_MATRIX_H
#define ENGINE_VFX_QIX_CONTROL_ABSTRACT_LEAF_MATRIX_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Control {

struct LeafMatrixContext;
struct LeafMatrixCallbackOwner;

class AbstractLeafMatrix {
public:
    static void ByQix_Static_(LeafMatrixContext* arg0, void* arg1);
    static void func_00BDA180(LeafMatrixContext* arg0, void* arg1);
    static void* func_00BDA1B0(LeafMatrixContext* arg0);
    static void func_00BDA1E0(LeafMatrixContext* arg0, void* arg1);
    static void* func_00BDA210(LeafMatrixContext* arg0);
    static u32 func_00BDA240(LeafMatrixContext* arg0);
    static void GetLeafMatrix_Static(LeafMatrixCallbackOwner* arg0, u32 arg1, void* arg2);
};

} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
