#ifndef ENGINE_DW_RENDERER_VARIANCEDEPTHDRAWSHADERDRIVER_H
#define ENGINE_DW_RENDERER_VARIANCEDEPTHDRAWSHADERDRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

class VarianceDepthDrawShaderDriver : public DwRendererMemoryObject, public shaderDriver::IShaderDriver<PixelShader> {
public:
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    u32 viewMatrixHandles[4];
    u32 normalizeFactorHandle;
    u32 shadowBufferZBiasHandle;
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
