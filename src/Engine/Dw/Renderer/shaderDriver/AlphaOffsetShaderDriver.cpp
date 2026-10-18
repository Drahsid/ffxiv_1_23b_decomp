#include "Engine/Dw/Renderer/shaderDriver/AlphaOffsetShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/PixelShader.h"
#include "Engine/Dw/RenderInterface/Surface.h"

extern "C" const char D_010F8E67[];
extern "C" const char D_010F8EEC[];
extern "C" const char D_010F8F0C[];
extern "C" SQEX::CDev::Engine::Dw::RenderInterface::Surface* D_01328D98[4];

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

static const f32 sAlphaOffset[Dw::RenderInterface::MultiSample::NumberOf] = {0.125f, 0.0625f, 0.03125f};

AlphaOffsetShaderDriver::AlphaOffsetShaderDriver() : alphaOffsetHandle(0) {
}

AlphaOffsetShaderDriver::~AlphaOffsetShaderDriver() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE_FORMATS(expression, message, file, line, function, D_010F8EEC, D_010F8F0C);
}

bool AlphaOffsetShaderDriver::Initialize(PixelShader* shader) {
    RenderInterface::PixelShader* shader_object = shader->shader;
    alphaOffsetHandle = shader_object->parameters.func_00420900(0, "alphaOffset");
    return static_cast<bool>(alphaOffsetHandle);
}

void AlphaOffsetShaderDriver::Apply(void* arg0, PixelShader* arg1) {
    u32 multi_sample = D_01328D98[0]->description.multiSample;
    // MultiSample::NumberOf is 16, so this assertion always fails
    LOG_ASSERT_AT(".\\shaderDriver\\AlphaOffsetShaderDriver.cpp", 61, Dw::RenderInterface::MultiSample::NumberOf == 3, D_010F8E67);
    f32 values[4] = {sAlphaOffset[multi_sample], 0.0f, 0.0f, 1.0f};
    D_01374E50->SetFloatArray(alphaOffsetHandle, values, 1);
}

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
