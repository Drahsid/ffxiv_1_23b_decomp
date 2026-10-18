#ifndef ENGINE_COMMON_MISC_NONCOPYABLE_H
#define ENGINE_COMMON_MISC_NONCOPYABLE_H

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {
namespace Misc {

class NonCopyable {
protected:
    NonCopyable() {
    }

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};

} // namespace Misc
} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
