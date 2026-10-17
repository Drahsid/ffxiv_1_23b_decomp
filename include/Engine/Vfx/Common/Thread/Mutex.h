#ifndef ENGINE_VFX_COMMON_THREAD_MUTEX_H
#define ENGINE_VFX_COMMON_THREAD_MUTEX_H

#include "Engine/Vfx/Common/Memory/NonCopyable.h"
#include "Engine/Vfx/Common/Object.h"
#include <windows.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Thread {

class Mutex : public Object, public Memory::NonCopyable {
public:
    Mutex();
    virtual ~Mutex();

    void func_00E3AFE0();
    void func_00E3AFF0();

private:
    CRITICAL_SECTION criticalSection;
};

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
