#include "Engine/Dw/Renderer/DepthDrawTag.h"
#include "Engine/Common/Log.h"
#include "Engine/Dw/Renderer/DepthDrawShaderDriver.h"
#include "Engine/Dw/Renderer/shaderDriver/ShaderDriverState.h"

using SQEX::CDev::Engine::Dw::Renderer::shaderDriver::ShaderDriverState;

struct __declspec(align(16)) DrawableNodeVector {
    f32 values[4];
};

class DrawableNodeVirtualPrefix {
public:
    virtual ~DrawableNodeVirtualPrefix();
    virtual const char* func_00A3B8C0();
    virtual void func_00A3D3E0(const char* arg0);
    virtual bool func_00A3B810();
    virtual bool func_0060D1C0();
    virtual bool func_006D6F80(u32 arg0);
    virtual DrawableNodeVector func_00BDB450();
    virtual void func_00776340(u32 arg0);
    virtual void Draw(ShaderDriverState* state);
};

extern "C" char D_010F92B9[];
extern "C" char D_010F92E0[];
extern "C" char D_010F9300[];
extern "C" u8 D_0130967D;
extern "C" u32 D_01328F0C;
extern "C" u8 D_01328F18;

extern "C" void func_0041C210(u32 arg0);
extern "C" void func_0041C2B0(bool arg0);

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE_FORMATS(expression, message, file, line, function, D_010F92E0, D_010F9300);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

void DepthDrawTag::Draw(shaderDriver::ShaderDriverState* state) {
    LOG_ASSERT_AT(".\\DepthDrawTag.cpp", 24, node != 0, D_010F92B9);
    state->unk_1A0 = this;
    D_0130967D = true;
    D_01328F0C = 0;
    func_0041C210(0);
    D_01328F18 = true;
    func_0041C2B0(true);
    state->func_00C47850(func_00C64510());
    reinterpret_cast<DrawableNodeVirtualPrefix*>(node)->Draw(state);
    D_01328F0C = 15;
    func_0041C210(15);
    state->func_00C47850(0);
}

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
