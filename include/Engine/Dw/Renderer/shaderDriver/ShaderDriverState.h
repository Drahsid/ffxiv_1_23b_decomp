#ifndef ENGINE_DW_RENDERER_SHADER_DRIVER_STATE_H
#define ENGINE_DW_RENDERER_SHADER_DRIVER_STATE_H

#include "types.h"
#include <emmintrin.h>

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Math {
class Vector;
class Matrix;
} // namespace Math

namespace Dw {
namespace Renderer {
class DrawEnv;
class DrawTag;
class PixelShader;

namespace shaderDriver {

struct ShaderDriverState {
    void func_00C47850(PixelShader* shader);
    const Math::Vector& func_00C47970() const;
    const Math::Matrix& func_00C47C60() const;
    f32 func_00C47D30() const;
    f32 func_00C47EC0() const;

    u8 unk_00[0x1A0];
    DrawTag* unk_1A0;
    u8 unk_1A4[0x74C];
    u8 unk_8F0;
    u8 unk_8F1[3];
    s32 unk_8F4;
    s32 unk_8F8;
    u8 unk_8FC[0x1C];
    f32 unk_918;
    f32 unk_91C;
    u8 unk_920[0x31C];
    DrawEnv* drawEnvironment;
    s32 environmentMapIndex;
    f32 blendRatio;
    u8 unk_C48[12];
    u8 unk_C54;
    u8 unk_C55[11];
    __m128i unk_C60;
};

} // namespace shaderDriver
} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
