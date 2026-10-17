#ifndef ENGINE_CUT_SCHEDULER_I_PROXY_ACTOR_H
#define ENGINE_CUT_SCHEDULER_I_PROXY_ACTOR_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

class IProxyActor {
public:
    virtual ~IProxyActor();
    virtual u32 func_00A20820() = 0;
    virtual u32 func_00A20830() = 0;
    virtual const void* func_00A20840() = 0;
    virtual s32 func_00A20860() = 0;
    virtual const void* func_00A208A0() = 0;
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
