#ifndef ENGINE_VFX_COMMON_OBJECT_H
#define ENGINE_VFX_COMMON_OBJECT_H

#include "Engine/Vfx/IVfxObject/IObject.h"
#include "Engine/Vfx/Common/Memory/Memory.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {

class Object : private IVfxObject::IObject {
public:
    static void operator delete(void* memory) {
        func_004162C0(memory);
    }
};

} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
