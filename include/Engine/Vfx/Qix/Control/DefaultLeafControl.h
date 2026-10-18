#ifndef ENGINE_VFX_QIX_CONTROL_DEFAULT_LEAF_CONTROL_H
#define ENGINE_VFX_QIX_CONTROL_DEFAULT_LEAF_CONTROL_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {

struct ContextPrefix;

namespace Control {

class DefaultLeafControl {
public:
    ~DefaultLeafControl();

private:
    ContextPrefix* context;
    void* unk_04[3];
    void* unk_10;
};

} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
