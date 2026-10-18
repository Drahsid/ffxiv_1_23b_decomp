#ifndef ENGINE_VFX_COMMON_CAMERA_CAMERA_ADJUSTMENT_H
#define ENGINE_VFX_COMMON_CAMERA_CAMERA_ADJUSTMENT_H

#include "Engine/Math/Vector.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Camera {

class BaseCamera;

class CameraAdjustment {
public:
    CameraAdjustment(BaseCamera* owner);
    ~CameraAdjustment();

    BaseCamera* owner;
    bool enabled;
    bool unk_05;
    Math::Vector translation;
    f32 rotation;
    f32 zoom;
};

} // namespace Camera
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
