#ifndef ENGINE_LAY_STELLA_EXTERNAL_DW_DRAW_ENV_I_LAYOUT_DRAW_ENV_OBJECT_H
#define ENGINE_LAY_STELLA_EXTERNAL_DW_DRAW_ENV_I_LAYOUT_DRAW_ENV_OBJECT_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Dw {
namespace Renderer {
class DrawEnv;
} // namespace Renderer
} // namespace Dw

namespace Lay {
namespace Stella {
namespace External {
namespace Dw {
namespace DrawEnv {

class ILayoutDrawEnvObject {
public:
    virtual ~ILayoutDrawEnvObject();
    virtual const void* func_008D5570() = 0;
    virtual void* func_00A29AA0() = 0;
    virtual u32 func_00A811D0() = 0;
    virtual void func_00A811F0(u32 arg0, f32* arg1) = 0;
    virtual void func_00A812D0(u32 arg0, f32* arg1) = 0;
    virtual void func_00A81260(u32 arg0, f32* arg1) = 0;
    virtual f32 func_00A81310(u32 arg0) = 0;
    virtual f32 func_00A81340(u32 arg0) = 0;
    virtual f32 func_00A81370(u32 arg0) = 0;
    virtual u32 func_00A813A0() = 0;
    virtual f32 func_00A813B0(u32 arg0) = 0;
    virtual void func_00A813E0(u32 arg0, f32* arg1) = 0;
    virtual u32 func_00A81450() = 0;
    virtual u8 func_00A81460(u32 arg0) = 0;
    virtual u32 func_00A81480(u32 arg0) = 0;
    virtual u32 func_00A814A0(u32 arg0) = 0;
    virtual u32 func_00A814C0(u32 arg0, u32 arg1) = 0;
    virtual u8 func_00A814F0(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual u32 func_00A81520(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual u32 func_00A81550(u32 arg0, u32 arg1, u32 arg2) = 0;
    virtual u32 func_00A81580() = 0;
    virtual u8 func_00A81590(u32 arg0) = 0;
    virtual u32 func_00A815B0(u32 arg0) = 0;
    virtual u32 func_00A815D0(u32 arg0) = 0;
    virtual u32 func_00A815F0() = 0;
    virtual const void* func_00A81600(u32 arg0) = 0;
    virtual const char* func_00A81620(u32 arg0) = 0;
    virtual void func_00A817D0(u32 arg0, f32* arg1) = 0;
    virtual void UpdateWindParameter() = 0;
    virtual const void* func_00A81640() = 0;
    virtual u32 func_00A81650() = 0;
    virtual u32 func_00A81670(u32 arg0) = 0;
    virtual u32 func_00A816A0(u32 arg0) = 0;
    virtual void func_00A816C0(void* arg0) = 0;
    virtual bool func_00A81710() = 0;
    virtual f32 func_00A81730() = 0;
    virtual u32 func_00A81740() = 0;
    virtual void func_00A81750(const void* arg0) = 0;
    virtual void func_00A823E0(void* arg0) = 0;
    virtual Engine::Dw::Renderer::DrawEnv* func_00C4BAE0() = 0;
    virtual u32 func_00A817B0() = 0;
    virtual void func_00A81760() = 0;
    virtual void func_00A81770() = 0;
};

} // namespace DrawEnv
} // namespace Dw
} // namespace External
} // namespace Stella
} // namespace Lay
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
