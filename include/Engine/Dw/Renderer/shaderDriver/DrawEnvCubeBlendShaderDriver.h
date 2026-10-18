#ifndef ENGINE_DW_RENDERER_SHADER_DRIVER_DRAW_ENV_CUBE_BLEND_SHADER_DRIVER_H
#define ENGINE_DW_RENDERER_SHADER_DRIVER_DRAW_ENV_CUBE_BLEND_SHADER_DRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

namespace shaderDriver {

class DrawEnvCubeBlendShaderDriver : public DwRendererMemoryObject, public IShaderDriver<PixelShader> {
public:
    DrawEnvCubeBlendShaderDriver();
    virtual ~DrawEnvCubeBlendShaderDriver();
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    s32 cubeMapSamplerIndex;
    u32 blendRatioHandle;
};

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
