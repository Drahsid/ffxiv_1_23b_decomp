#ifndef ENGINE_CDEV_VFX_COMMON_MEMORY_MALLOC_H
#define ENGINE_CDEV_VFX_COMMON_MEMORY_MALLOC_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace CDevVfx {
namespace Common {
namespace Memory {

const char* Get_Allocation_Category(s32 category);
void VfxSwitchRandomVfxMalloc_StaticDebug(bool arg0);
void Initialize_Malloc();

} // namespace Memory
} // namespace Common
} // namespace CDevVfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
