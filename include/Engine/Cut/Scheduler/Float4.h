#ifndef ENGINE_CUT_SCHEDULER_FLOAT4_H
#define ENGINE_CUT_SCHEDULER_FLOAT4_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

struct Float4 {
    Float4(const Float4& value) : unk_00(value.unk_00), unk_04(value.unk_04), unk_08(value.unk_08), unk_0C(value.unk_0C) {
    }

    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
