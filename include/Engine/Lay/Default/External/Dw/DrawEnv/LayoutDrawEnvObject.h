#ifndef ENGINE_LAY_DEFAULT_EXTERNAL_DW_DRAW_ENV_LAYOUT_DRAW_ENV_OBJECT_H
#define ENGINE_LAY_DEFAULT_EXTERNAL_DW_DRAW_ENV_LAYOUT_DRAW_ENV_OBJECT_H

#include "Engine/Lay/Stella/External/Dw/DrawEnv/ILayoutDrawEnvObject.h"
#include "Engine/Common/Misc/NonCopyable.h"
#include "Engine/Lay/Stella/LayoutMemoryObject.h"
#include <xmmintrin.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Lay {
namespace Default {
namespace External {
namespace Dw {
namespace DrawEnv {

struct DrawEnv_Result_00A81790 {
    __m128 value;
};

class LayoutDrawEnvObject : public Stella::LayoutMemoryObject,
                            public Stella::External::Dw::DrawEnv::ILayoutDrawEnvObject,
                            public Engine::Common::Misc::NonCopyable {
public:
    virtual ~LayoutDrawEnvObject();
    virtual DrawEnv_Result_00A81790 func_00A81790(u32 arg0);
    virtual const void* func_008D5570();
    virtual void* func_00A29AA0();
    virtual u32 func_00A811D0();
    virtual void func_00A811F0(u32 arg0, f32* arg1);
    virtual void func_00A812D0(u32 arg0, f32* arg1);
    virtual void func_00A81260(u32 arg0, f32* arg1);
    virtual f32 func_00A81310(u32 arg0);
    virtual f32 func_00A81340(u32 arg0);
    virtual f32 func_00A81370(u32 arg0);
    virtual u32 func_00A813A0();
    virtual f32 func_00A813B0(u32 arg0);
    virtual void func_00A813E0(u32 arg0, f32* arg1);
    virtual u32 func_00A81450();
    virtual u8 func_00A81460(u32 arg0);
    virtual u32 func_00A81480(u32 arg0);
    virtual u32 func_00A814A0(u32 arg0);
    virtual u32 func_00A814C0(u32 arg0, u32 arg1);
    virtual u8 func_00A814F0(u32 arg0, u32 arg1, u32 arg2);
    virtual u32 func_00A81520(u32 arg0, u32 arg1, u32 arg2);
    virtual u32 func_00A81550(u32 arg0, u32 arg1, u32 arg2);
    virtual u32 func_00A81580();
    virtual u8 func_00A81590(u32 arg0);
    virtual u32 func_00A815B0(u32 arg0);
    virtual u32 func_00A815D0(u32 arg0);
    virtual u32 func_00A815F0();
    virtual const void* func_00A81600(u32 arg0);
    virtual const char* func_00A81620(u32 arg0);
    virtual void func_00A817D0(u32 arg0, f32* arg1);
    virtual void UpdateWindParameter();
    virtual const void* func_00A81640();
    virtual u32 func_00A81650();
    virtual u32 func_00A81670(u32 arg0);
    virtual u32 func_00A816A0(u32 arg0);
    virtual void func_00A816C0(void* arg0);
    virtual bool func_00A81710();
    virtual f32 func_00A81730();
    virtual u32 func_00A81740();
    virtual void func_00A81750(const void* arg0);
    virtual void func_00A823E0(void* arg0);
    virtual Engine::Dw::Renderer::DrawEnv* func_00C4BAE0();
    virtual u32 func_00A817B0();
    virtual void func_00A81760();
    virtual void func_00A81770();
};

} // namespace DrawEnv
} // namespace Dw
} // namespace External
} // namespace Default
} // namespace Lay
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
