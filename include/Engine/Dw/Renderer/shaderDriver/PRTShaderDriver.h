#ifndef ENGINE_DW_RENDERER_SHADERDRIVER_PRTSHADERDRIVER_H
#define ENGINE_DW_RENDERER_SHADERDRIVER_PRTSHADERDRIVER_H

#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"
#include "Engine/Dw/Renderer/shaderDriver/IShaderDriver.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class VertexShader;

namespace shaderDriver {

class PRTShaderDriver : public DwRendererMemoryObject, public IShaderDriver<VertexShader> {
public:
    virtual ~PRTShaderDriver();
    virtual bool Initialize(VertexShader* shader);
    virtual void Apply(void* arg0, VertexShader* arg1);

private:
    u32 prtOrientHandle;
    u32 prtTableHandles[64];
    u32 prtParamHandle;
};

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
