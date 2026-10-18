#ifndef ENGINE_DW_RENDERER_DWRENDERERMEMORYOBJECT_H
#define ENGINE_DW_RENDERER_DWRENDERERMEMORYOBJECT_H

#include "Engine/Memory/Allocator.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace Renderer {

class DwRendererMemoryObject {
public:
    static void* operator new(u32 size, const Memory::AllocationInfo& information);
    static void operator delete(void* memory) {
        reinterpret_cast<Memory::Allocator**>(memory)[-1]->Free(memory);
    }
};

} // namespace Renderer
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
