#ifndef ENGINE_DW_RENDERER_SHADERDRIVER_CELLSHADERDRIVER_H
#define ENGINE_DW_RENDERER_SHADERDRIVER_CELLSHADERDRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

namespace shaderDriver {

class CellShaderDriver : public DwRendererMemoryObject, public IShaderDriver<PixelShader> {
public:
    virtual ~CellShaderDriver();
    virtual bool Initialize(PixelShader* shader);
    virtual void Apply(void* arg0, PixelShader* arg1);

private:
    u32 cellShadeColor;
};

} // namespace shaderDriver

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
