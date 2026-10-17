#ifndef ENGINE_CUT_SCHEDULER_BASE_CLIP_IMPL_H
#define ENGINE_CUT_SCHEDULER_BASE_CLIP_IMPL_H

#include "Engine/Cut/Scheduler/ClipBase.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

template<class T>
class BaseClipImpl : public ClipBase {
public:
    BaseClipImpl(const ClipData* data, void* arg1) : ClipBase(data, arg1) {
    }

    virtual ~BaseClipImpl() {
    }

    virtual const void* GetData() {
        return reinterpret_cast<const u8*>(mClipData) + sizeof(T);
    }

protected:
    const T* Get_Clip_Data() const {
        return static_cast<const T*>(mClipData);
    }
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
