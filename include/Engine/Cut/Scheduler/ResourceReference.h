#ifndef ENGINE_CUT_SCHEDULER_RESOURCE_REFERENCE_H
#define ENGINE_CUT_SCHEDULER_RESOURCE_REFERENCE_H

#include "Engine/Cut/Common/CutSceneObject.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

struct __declspec(align(8)) Resource_Id {
    char unk_00[16];
};

class Resource_Id_Type {
public:
    u32 unk_00;
};

class ResourceReference : public Common::CutSceneObject {
public:
    virtual void* func_00A274F0(void* arg0, s32 index);
    virtual void* func_00A27490(void* arg0, const Resource_Id& id, const Resource_Id_Type& type);
    virtual const char* func_00A276A0(s32 index);
    virtual Resource_Id func_00A27560(s32 index);
    virtual Resource_Id_Type func_00A27600(s32 index);

    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
    void* unk_10;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
