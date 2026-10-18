#ifndef ENGINE_DW_RENDERER_PIXELSHADER_H
#define ENGINE_DW_RENDERER_PIXELSHADER_H

#include "Engine/Dw/Renderer/ShaderHandle.h"
#include "Engine/Dw/RenderInterface/Shader.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

namespace shaderDriver {
template<class T>
class IShaderDriver;
} // namespace shaderDriver

class PixelShader : public ShaderHandle<RenderInterface::PixelShader> {
public:
    void func_00C57560(shaderDriver::IShaderDriver<PixelShader>* driver);
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
