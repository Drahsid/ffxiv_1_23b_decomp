#ifndef ENGINE_DW_RENDERER_FLATCOLORSHADERDRIVER_H
#define ENGINE_DW_RENDERER_FLATCOLORSHADERDRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

class FlatColorShaderDriver : public DwRendererMemoryObject, public shaderDriver::IShaderDriver<PixelShader> {
public:
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    u32 flatColorHandle;
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
