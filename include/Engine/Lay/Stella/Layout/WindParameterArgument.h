#ifndef ENGINE_LAY_STELLA_LAYOUT_WIND_PARAMETER_ARGUMENT_H
#define ENGINE_LAY_STELLA_LAYOUT_WIND_PARAMETER_ARGUMENT_H

#include <xmmintrin.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Lay {
namespace Stella {

namespace External {
namespace Dw {
namespace DrawEnv {
class ILayoutDrawEnvObject;
} // namespace DrawEnv
} // namespace Dw
} // namespace External

namespace Layout {

struct WindParameterArgument {
    External::Dw::DrawEnv::ILayoutDrawEnvObject* object;
    __m128 value;
};

} // namespace Layout
} // namespace Stella
} // namespace Lay
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
