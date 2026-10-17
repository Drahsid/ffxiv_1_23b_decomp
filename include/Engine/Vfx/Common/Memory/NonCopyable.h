#ifndef ENGINE_VFX_COMMON_MEMORY_NON_COPYABLE_H
#define ENGINE_VFX_COMMON_MEMORY_NON_COPYABLE_H

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Memory {

class NonCopyable {
protected:
    NonCopyable() {
    }

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};

} // namespace Memory
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
