#ifndef ENGINE_DW_RENDERER_DEPTHDRAWTAG_H
#define ENGINE_DW_RENDERER_DEPTHDRAWTAG_H

#include "Engine/Dw/Renderer/DrawTag.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class DrawableNode;

class DepthDrawTag : public DrawTag {
public:
    virtual void Draw(shaderDriver::ShaderDriverState* state);

private:
    DrawableNode* node;
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
