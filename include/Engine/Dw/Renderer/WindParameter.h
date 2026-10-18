#ifndef ENGINE_DW_RENDERER_WIND_PARAMETER_H
#define ENGINE_DW_RENDERER_WIND_PARAMETER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class WindParameter {
public:
    WindParameter(bool arg0);
    virtual ~WindParameter();
    WindParameter& operator=(const WindParameter& arg0);

private:
    u8 unk_04[0x2C];
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
