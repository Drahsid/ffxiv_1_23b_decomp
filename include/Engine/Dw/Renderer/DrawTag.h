#ifndef ENGINE_DW_RENDERER_DRAWTAG_H
#define ENGINE_DW_RENDERER_DRAWTAG_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

namespace shaderDriver {
struct ShaderDriverState;
} // namespace shaderDriver

class DrawTag : public DwRendererMemoryObject {
public:
    virtual ~DrawTag();
    virtual void Draw(shaderDriver::ShaderDriverState* state);

private:
    u8 unk_04[0x18];
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
