#ifndef ENGINE_VFX_COMMON_THREAD_THREAD_MANAGER_H
#define ENGINE_VFX_COMMON_THREAD_THREAD_MANAGER_H

#include "Engine/Vfx/Common/Object.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {

namespace Map {

class UsIntMap;

} // namespace Map

namespace Thread {

class ThreadManager : public Object {
public:
    ThreadManager(u32 capacity);
    virtual ~ThreadManager();

private:
    static s32 Get_Processor_Count(u32* affinity_mask);

    u32 capacity;
    u32 unk_08;
    u32 affinityMask;
    s32 processorCount;
    Map::UsIntMap* unk_14;
};

} // namespace Thread
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
