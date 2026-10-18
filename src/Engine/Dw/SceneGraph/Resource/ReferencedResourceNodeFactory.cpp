#include "Engine/Dw/SceneGraph/Resource/ReferencedResourceNodeFactory.h"
#include "Engine/Common/StdioLog.h"

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace SceneGraph {
namespace Resource {

ResourceNode* ReferencedResourceNodeFactory::CreateReferencedResourceNode(
    u32 arg0,
    const char* name,
    Memory::Alternative::IHandle* handle,
    u32 size,
    ResourceNodeFactoryArg* arg4
) {
    LOG_ASSERT_AT(".\\Resource\\ReferencedResourceNodeFactory.cpp", 58, false, "not implemented yet.");
    return 0;
}

} // namespace Resource
} // namespace SceneGraph
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX
