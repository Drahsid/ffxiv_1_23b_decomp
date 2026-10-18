#ifndef ENGINE_VFX_I_VFX_OBJECT_I_RESOURCE_MANAGER_H
#define ENGINE_VFX_I_VFX_OBJECT_I_RESOURCE_MANAGER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace IVfxObject {

class IResourceManager;
typedef bool (*ResourceUpdateCallback)(IResourceManager* arg0);

class IResourceManager {
public:
    virtual ~IResourceManager();
    virtual void ManualUpdate() = 0;
    virtual void func_00BD6760(u64 arg0) = 0;
    virtual void func_00BD6790(ResourceUpdateCallback arg0) = 0;
    virtual bool func_00BD67B0() = 0;
    virtual bool func_00BD69F0() = 0;
};

} // namespace IVfxObject
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
