#ifndef ENGINE_DW_RENDERER_SHADERDRIVER_ISHADERDRIVER_H
#define ENGINE_DW_RENDERER_SHADERDRIVER_ISHADERDRIVER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

template<class T>
class IShaderDriver {
public:
    IShaderDriver() {
    }

    virtual ~IShaderDriver() {
    }

    virtual bool Initialize(T* shader) = 0;
    virtual void Apply(void* arg0, T* arg1) = 0;

    virtual s32 func_0053C440(u32 arg0) {
        return -1;
    }
};

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
