#ifndef ENGINE_DW_RENDERER_SHADERDRIVER_ALPHAOFFSETSHADERDRIVER_H
#define ENGINE_DW_RENDERER_SHADERDRIVER_ALPHAOFFSETSHADERDRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

namespace shaderDriver {

class AlphaOffsetShaderDriver : public DwRendererMemoryObject, public IShaderDriver<PixelShader> {
public:
    AlphaOffsetShaderDriver();
    virtual ~AlphaOffsetShaderDriver();
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    u32 alphaOffsetHandle;
};

} // namespace shaderDriver

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
