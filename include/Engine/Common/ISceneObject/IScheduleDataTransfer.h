#ifndef ENGINE_COMMON_I_SCENE_OBJECT_I_SCHEDULE_DATA_TRANSFER_H
#define ENGINE_COMMON_I_SCENE_OBJECT_I_SCHEDULE_DATA_TRANSFER_H

#include "Engine/Common/ISceneObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Common {
namespace ISceneObject {

class IScheduleDataTransfer {
public:
    virtual ~IScheduleDataTransfer() {
    }

    virtual void func_007143E0() = 0;
    virtual void func_00CB1C80() = 0;
};

} // namespace ISceneObject
} // namespace Common
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
