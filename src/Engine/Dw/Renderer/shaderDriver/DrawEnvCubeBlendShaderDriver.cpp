#include "Engine/Dw/Renderer/shaderDriver/DrawEnvCubeBlendShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/PixelShader.h"
#include "Engine/Dw/Renderer/DrawEnv.h"
#include "Engine/Dw/Renderer/shaderDriver/ShaderDriverState.h"
#include "Engine/Dw/RenderInterface/Sampler.h"
#include "asm.h"

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/Renderer/shaderDriver/DrawEnvCubeBlendShaderDriver/00C67D90.s");

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

DrawEnvCubeBlendShaderDriver::DrawEnvCubeBlendShaderDriver() : cubeMapSamplerIndex(-1), blendRatioHandle(0) {
}

DrawEnvCubeBlendShaderDriver::~DrawEnvCubeBlendShaderDriver() {
}

bool DrawEnvCubeBlendShaderDriver::Initialize(PixelShader* shader) {
    RenderInterface::PixelShader* shader_object = shader->shader;
    u32 handle = shader_object->Get_Parameter_Handle("drawEnvCubeMap");
    if (handle) {
        cubeMapSamplerIndex = shader_object->Get_Parameter_Register(handle);
    }
    
    blendRatioHandle = shader_object->Get_Parameter_Handle("drawEnvBlendRatio");
    return cubeMapSamplerIndex < 0 ? false : true;
}

void DrawEnvCubeBlendShaderDriver::Apply(void* arg0, PixelShader* arg1) {
    ShaderDriverState* state = static_cast<ShaderDriverState*>(arg0);
    f32 blend_ratio = state->blendRatio;
    if (state->drawEnvironment && blend_ratio > 0.0f && blend_ratio < 1.0f && state->environmentMapIndex >= 0) {
        EnvmapResource* resource = state->drawEnvironment->GetEnvmapTexture(state->environmentMapIndex);
        if (resource) {
            RenderInterface::func_00418410(cubeMapSamplerIndex, resource->Get_Texture()->Get_Handle());
            RenderInterface::func_00418380(cubeMapSamplerIndex, 0, 12, true);
            RenderInterface::func_004183C0(
                cubeMapSamplerIndex,
                RenderInterface::TextureFilter(RenderInterface::TextureFilter::Linear),
                RenderInterface::TextureFilter(RenderInterface::TextureFilter::Linear),
                RenderInterface::TextureFilter(RenderInterface::TextureFilter::None),
                0
            );
            RenderInterface::func_00418300(
                cubeMapSamplerIndex,
                RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
                RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
                RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
                RenderInterface::TextureCoordinateMask(7)
            );
            RenderInterface::func_00C23A80(blendRatioHandle, &blend_ratio, 1);
            return;
        }
    }
    RenderInterface::PixelShaderInterface* shader_object = reinterpret_cast<RenderInterface::PixelShaderInterface*>(arg1->shader);
    blend_ratio = 1.0f;
    shader_object->SetFloatArray(blendRatioHandle, &blend_ratio, 1);
    RenderInterface::func_00418410(cubeMapSamplerIndex, 0);
    RenderInterface::func_00418380(cubeMapSamplerIndex, 0, 12, true);
    RenderInterface::func_004183C0(
        cubeMapSamplerIndex,
        RenderInterface::TextureFilter(RenderInterface::TextureFilter::Point),
        RenderInterface::TextureFilter(RenderInterface::TextureFilter::Point),
        RenderInterface::TextureFilter(RenderInterface::TextureFilter::None),
        0
    );
    RenderInterface::func_00418300(
        cubeMapSamplerIndex,
        RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
        RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
        RenderInterface::TextureAddressMode(RenderInterface::TextureAddressMode::Clamp),
        RenderInterface::TextureCoordinateMask(7)
    );
}

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
