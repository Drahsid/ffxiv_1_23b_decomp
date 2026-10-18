#ifndef ENGINE_DW_DWMEMORYOBJECT_H
#define ENGINE_DW_DWMEMORYOBJECT_H

#include "Engine/Memory/Allocator.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {

class DwMemoryObject {
public:
    static void operator delete(void* memory) {
        if (memory != 0) {
            reinterpret_cast<Memory::Allocator**>(memory)[-1]->Free(memory);
        }
    }
};

} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
