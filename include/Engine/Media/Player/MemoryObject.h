#ifndef ENGINE_MEDIA_PLAYER_MEMORY_OBJECT_H
#define ENGINE_MEDIA_PLAYER_MEMORY_OBJECT_H

#include <stddef.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {

class MemoryObject {
public:
    static void* operator new(size_t size);
    static void operator delete(void* memory);
};

} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
