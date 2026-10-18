#include "Engine/Dw/Renderer/shaderDriver/PRTShaderDriver.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/VertexShader.h"
#include "asm.h"
#include <stdio.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {
namespace shaderDriver {

PRTShaderDriver::~PRTShaderDriver() {
}

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/Renderer/shaderDriver/PRTShaderDriver/00C66180.s");

bool PRTShaderDriver::Initialize(VertexShader* shader) {
    RenderInterface::VertexShader* shader_object = shader->shader;
    prtOrientHandle = shader_object->parameters.func_00420900(0, "prtOrient");
    if (prtOrientHandle != 0) {
        for (s32 index = 0; index < 64; ++index) {
            char name[128];
            sprintf(name, "prtTable[%d]", index);
            prtTableHandles[index] = shader_object->parameters.func_00420900(0, name);
        }
    }
    prtParamHandle = shader_object->parameters.func_00420900(0, "prtParam");
    return prtOrientHandle;
}

INCLUDE_ASM("asm/nonmatchings/Engine/Dw/Renderer/shaderDriver/PRTShaderDriver/00C662F0.s");

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
