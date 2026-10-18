#ifndef ENGINE_VFX_QIX_EX_RESOURCE_EX_RESOURCE_MANAGER_H
#define ENGINE_VFX_QIX_EX_RESOURCE_EX_RESOURCE_MANAGER_H

#include "Engine/Vfx/Common/Object.h"
#include "Engine/Vfx/IVfxObject/IResourceManager.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace ExResource {

class ExResourceManager : public Common::Object, public IVfxObject::IResourceManager {
public:
    virtual ~ExResourceManager();
    virtual void ManualUpdate();
    virtual void func_00BD6760(u64 arg0);
    virtual void func_00BD6790(IVfxObject::ResourceUpdateCallback arg0);
    virtual bool func_00BD67B0();
    virtual bool func_00BD69F0();
    void func_00BD6750();

private:
    u32 unk_04;
    u64 unk_08;
    u8 unk_10[0x6C];
    IVfxObject::ResourceUpdateCallback unk_7C;
    u8 unk_80[0x1A];
    u16 unk_9A;
    u8 unk_9C;
    u8 unk_9D;
};

} // namespace ExResource
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
