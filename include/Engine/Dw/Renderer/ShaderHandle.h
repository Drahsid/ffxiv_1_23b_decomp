#ifndef ENGINE_DW_RENDERER_SHADERHANDLE_H
#define ENGINE_DW_RENDERER_SHADERHANDLE_H

#include "Engine/Dw/Renderer/LinkTag.h"
#include "Engine/Dw/Renderer/DwRendererMemoryObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

template<class T>
class ShaderHandle : public LinkTag, public DwRendererMemoryObject {
public:
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    T* shader;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
