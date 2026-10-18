#include "Engine/Dw/Renderer/VarianceDepthDrawShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/PixelShader.h"
#include "Engine/Dw/Renderer/ShaderFactory.h"
#include "Engine/Dw/Renderer/shaderDriver/ShaderDriverState.h"
#include "Engine/Math/Matrix.h"
#include "asm.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

struct VarianceDepthDrawShaderData : public DwRendererMemoryObject {
    VarianceDepthDrawShaderData() {
    }

    ~VarianceDepthDrawShaderData() {
        delete shader;
    }

    PixelShader* shader;
};

extern "C" const char D_010F6690[];
extern "C" const u8 D_010F67E0[0x230];
extern "C" const char D_010F6A10[];
extern "C" const char D_010F6A28[];

extern "C" {
VarianceDepthDrawShaderData* D_01374E70 = 0;
}

extern "C" PixelShader* func_00C5BF00() {
    return D_01374E70->shader;
}

extern "C" void func_00C5BF30() {
    D_01374E70 = new (Memory::AllocationInfo(16, D_010F6A10)) VarianceDepthDrawShaderData;
    D_01374E70->shader = D_0136EBF0.func_00C2CA70(D_010F67E0, sizeof(D_010F67E0)).release();
    D_01374E70->shader->func_00C57560(new (Memory::AllocationInfo(16, D_010F6A28)) VarianceDepthDrawShaderDriver);
}

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/Renderer/VarianceDepthDrawShaderDriver/00C5BFE0.s");

extern "C" void func_00C5C0A0() {
    delete D_01374E70;
}

bool VarianceDepthDrawShaderDriver::Initialize(PixelShader* shader) {
    RenderInterface::PixelShader* shader_object = shader->shader;
    viewMatrixHandles[0] = shader_object->parameters.func_00420900(0, "viewMatrix[0]");
    viewMatrixHandles[1] = shader_object->parameters.func_00420900(0, "viewMatrix[1]");
    viewMatrixHandles[2] = shader_object->parameters.func_00420900(0, "viewMatrix[2]");
    viewMatrixHandles[3] = shader_object->parameters.func_00420900(0, "viewMatrix[3]");
    normalizeFactorHandle = shader_object->parameters.func_00420900(0, "normalizeFactor");
    shadowBufferZBiasHandle = shader_object->parameters.func_00420900(0, D_010F6690);
    return true;
}

void VarianceDepthDrawShaderDriver::Apply(void* arg0, PixelShader* arg1) {
    const shaderDriver::ShaderDriverState* state = static_cast<const shaderDriver::ShaderDriverState*>(arg0);
    const Math::Matrix& matrix = state->func_00C47C60();
    D_01374E50->SetFloatArray(viewMatrixHandles[0], matrix.values[0].values, 4);
    D_01374E50->SetFloatArray(viewMatrixHandles[1], matrix.values[1].values, 4);
    D_01374E50->SetFloatArray(viewMatrixHandles[2], matrix.values[2].values, 4);
    D_01374E50->SetFloatArray(viewMatrixHandles[3], matrix.values[3].values, 4);
    f32 normalize_factor = 1.0f / state->func_00C47EC0();
    f32 normalize_values[4] = {normalize_factor, normalize_factor, normalize_factor, normalize_factor};
    D_01374E50->SetFloatArray(normalizeFactorHandle, normalize_values, 4);
    f32 bias_values[4] = {state->func_00C47D30(), 0.0f, 0.0f, 0.0f};
    D_01374E50->SetFloatArray(shadowBufferZBiasHandle, bias_values, 4);
}

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
