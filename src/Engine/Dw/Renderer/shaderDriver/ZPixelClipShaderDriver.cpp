#include "Engine/Dw/Renderer/shaderDriver/ZPixelClipShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/PixelShader.h"
#include "Engine/Dw/Renderer/shaderDriver/ShaderDriverState.h"
#include "asm.h"

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/Renderer/shaderDriver/ZPixelClipShaderDriver/00C66500.s");

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

ZPixelClipShaderDriver::~ZPixelClipShaderDriver() {
}

bool ZPixelClipShaderDriver::Initialize(PixelShader* shader) {
    RenderInterface::PixelShader* shader_object = shader->shader;
    pixelClippingDistanceHandle = shader_object->parameters.func_00420900(0, "pixelClippingDistance");
    return static_cast<bool>(pixelClippingDistanceHandle);
}

void ZPixelClipShaderDriver::Apply(void* arg0, PixelShader* arg1) {
    if (pixelClippingDistanceHandle != 0) {
        const ShaderDriverState* state = static_cast<const ShaderDriverState*>(arg0);
        f32 near_distance = state->unk_918;
        f32 far_distance = state->unk_91C;
        if (near_distance > 0.0f && far_distance > near_distance) {
            f32 values[4] = {near_distance, far_distance, 0.0f, 0.0f};
            D_01374E50->SetFloatArray(pixelClippingDistanceHandle, values, 4);
        }
    }
}

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
