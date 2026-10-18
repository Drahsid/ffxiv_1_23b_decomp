#ifndef ENGINE_DW_RENDERER_SHADERFACTORY_H
#define ENGINE_DW_RENDERER_SHADERFACTORY_H

#include "types.h"
#include <memory>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class PixelShader;

class ShaderFactory {
public:
    std::auto_ptr<PixelShader> func_00C2CA70(const void* data, u32 size);
};

extern "C" ShaderFactory D_0136EBF0;

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
