#ifndef ENGINE_DW_SCENE_GRAPH_RESOURCE_REFERENCED_RESOURCE_NODE_FACTORY_H
#define ENGINE_DW_SCENE_GRAPH_RESOURCE_REFERENCED_RESOURCE_NODE_FACTORY_H

#include "Engine/Dw/SceneGraph/Resource/IResourceNodeFactory.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace SceneGraph {
namespace Resource {

class ReferencedResourceNodeFactory : public IResourceNodeFactory {
public:
    virtual ~ReferencedResourceNodeFactory();
    virtual ResourceNode* Create_Resource_Node(u32 arg0, const char* name, void* data, u32 size, ResourceNodeFactoryArg* arg4);
    virtual ResourceNode* CreateReferencedResourceNode(
        u32 arg0,
        const char* name,
        Memory::Alternative::IHandle* handle,
        u32 size,
        ResourceNodeFactoryArg* arg4
    );
    virtual bool func_005C5C80_18();
};

} // namespace Resource
} // namespace SceneGraph
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
