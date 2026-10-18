#ifndef ENGINE_DW_RENDERER_SHADERDRIVER_ZPIXELCLIPSHADERDRIVER_H
#define ENGINE_DW_RENDERER_SHADERDRIVER_ZPIXELCLIPSHADERDRIVER_H

#include "Engine/Dw/DwMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

namespace shaderDriver {

class ZPixelClipShaderDriver : public DwMemoryObject, public IShaderDriver<PixelShader> {
public:
    virtual ~ZPixelClipShaderDriver();
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    u32 pixelClippingDistanceHandle;
};

} // namespace shaderDriver

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
