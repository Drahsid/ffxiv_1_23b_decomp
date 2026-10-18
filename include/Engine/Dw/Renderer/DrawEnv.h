#ifndef ENGINE_DW_RENDERER_DRAW_ENV_H
#define ENGINE_DW_RENDERER_DRAW_ENV_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class WindParameter;

struct EnvmapTexture {
    void* Get_Handle() const {
        return handle;
    }

    void* handle;
};

struct EnvmapResource {
    EnvmapTexture* Get_Texture() const {
        return texture;
    }

    u8 unk_00[0x40];
    EnvmapTexture* texture;
};

class DrawEnv {
public:
    WindParameter* func_00C1F3E0();
    EnvmapResource* GetEnvmapTexture(s32 index);
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
