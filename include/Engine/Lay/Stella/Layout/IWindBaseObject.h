#ifndef ENGINE_LAY_STELLA_LAYOUT_I_WIND_BASE_OBJECT_H
#define ENGINE_LAY_STELLA_LAYOUT_I_WIND_BASE_OBJECT_H

#include "Engine/Lay/Stella/Layout/ILayoutBaseObject.h"
#include "Engine/Lay/Stella/Layout/WindParameterArgument.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Lay {
namespace Stella {
namespace Layout {

class IWindBaseObject : public ILayoutBaseObject {
public:
    virtual ~IWindBaseObject();
    virtual void unk_9C() = 0;
    virtual void unk_A0() = 0;
    virtual void unk_A4() = 0;
    virtual void unk_A8() = 0;
    virtual void unk_AC() = 0;
    virtual void unk_B0() = 0;
    virtual void unk_B4() = 0;
    virtual void unk_B8() = 0;
    virtual void unk_BC() = 0;
    virtual void unk_C0() = 0;
    virtual void unk_C4() = 0;
    virtual bool func_00AB56F0(const WindParameterArgument* arg0) = 0;
    virtual void unk_CC() = 0;
};

} // namespace Layout
} // namespace Stella
} // namespace Lay
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
