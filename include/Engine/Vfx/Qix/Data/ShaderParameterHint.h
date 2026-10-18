#ifndef ENGINE_VFX_QIX_DATA_SHADER_PARAMETER_HINT_H
#define ENGINE_VFX_QIX_DATA_SHADER_PARAMETER_HINT_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

struct ShaderParameterHintSourcePrefix;

class ShaderParameterHint {
public:
    ShaderParameterHint(const ShaderParameterHintSourcePrefix* arg0);
    static void RebuildTable_Static_(const ShaderParameterHintSourcePrefix* arg0, u16* arg1);

    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
};

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
