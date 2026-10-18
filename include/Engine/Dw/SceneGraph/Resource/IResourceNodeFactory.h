#ifndef ENGINE_DW_SCENE_GRAPH_RESOURCE_IRESOURCE_NODE_FACTORY_H
#define ENGINE_DW_SCENE_GRAPH_RESOURCE_IRESOURCE_NODE_FACTORY_H

#include "types.h"
#include <memory>

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Memory {
namespace Alternative {
class IHandle;
} // namespace Alternative
} // namespace Memory

namespace Dw {
namespace SceneGraph {
namespace Resource {

class ResourceNode;
class ResourceNodeFactoryArg;

class IResourceNodeFactory {
public:
    virtual ~IResourceNodeFactory();
    virtual std::auto_ptr<ResourceNode> Create_Owned_Resource_Node(
        u32 arg0,
        const char* name,
        void* data,
        u32 size,
        ResourceNodeFactoryArg* arg4
    ) = 0;
    virtual ResourceNode* Create_Resource_Node(u32 arg0, const char* name, void* data, u32 size, ResourceNodeFactoryArg* arg4);
    virtual ResourceNode* CreateReferencedResourceNode(
        u32 arg0,
        const char* name,
        Memory::Alternative::IHandle* handle,
        u32 size,
        ResourceNodeFactoryArg* arg4
    );
    virtual u32 Get_Resource_Node_Size() = 0;
    virtual bool func_005C5C80_14();
    virtual bool func_005C5C80_18();
};

} // namespace Resource
} // namespace SceneGraph
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
