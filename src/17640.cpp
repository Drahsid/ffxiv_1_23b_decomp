#include "Engine/Dw/RenderInterface/D3d9/Rapture/MemoryPool.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {
namespace D3d9 {
namespace Rapture {

u32 MemoryPool::func_00417640(u32 value, u32 shift) {
    u32 negated = ~value + 1;
    return ((negated >> shift) << shift) ^ negated;
}

} // namespace Rapture
} // namespace D3d9
} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

