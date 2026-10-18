#include "Engine/Dw/Renderer/shaderDriver/CellShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/PixelShader.h"
#include "Engine/Dw/Renderer/shaderDriver/ShaderDriverState.h"
#include <emmintrin.h>

extern "C" const char D_010F8CC7[];
extern "C" const char D_010F8D64[];
extern "C" const char D_010F8D84[];

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

static inline s32 Extract_Signed_Lane_3(const __m128i& arg0) {
    u32 high_word = static_cast<u32>(_mm_extract_epi16(arg0, 7));
    u16 low_word = static_cast<u16>(_mm_extract_epi16(arg0, 6));
    return static_cast<s32>((high_word << 16) | low_word);
}

CellShaderDriver::~CellShaderDriver() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE_FORMATS(expression, message, file, line, function, D_010F8D64, D_010F8D84);
}

extern "C" CellShaderDriver* func_00C67BF0() {
    return new (Memory::AllocationInfo(16, "CDev.Engine.Dw.Renderer")) CellShaderDriver;
}

bool CellShaderDriver::Initialize(PixelShader* shader) {
    RenderInterface::PixelShader* shader_object = shader->shader;
    cellShadeColor = shader_object->parameters.func_00420900(0, "cellShadeColor");
    return cellShadeColor != 0;
}

void CellShaderDriver::Apply(void* arg0, PixelShader* arg1) {
    LOG_ASSERT_AT(".\\shaderDriver\\CellShaderDriver.cpp", 28, cellShadeColor != 0, D_010F8CC7);
    const ShaderDriverState* state = static_cast<const ShaderDriverState*>(arg0);
    const __m128i& temp_0 = state->unk_C60;
    f32 values[4] = {
        static_cast<f32>(Extract_Signed_Lane_3(temp_0)) / 255.0f,
        static_cast<f32>(Extract_Signed_Lane_3(temp_0)) / 255.0f,
        static_cast<f32>(Extract_Signed_Lane_3(temp_0)) / 255.0f,
        static_cast<f32>((state->unk_C54 & 0x3F) * 4) / 255.0f
    };
    D_01374E50->SetFloatArray(cellShadeColor, values, 4);
}

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
