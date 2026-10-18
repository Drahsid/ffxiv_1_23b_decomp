#ifndef ENGINE_VFX_COMMON_CAMERA_BASE_CAMERA_H
#define ENGINE_VFX_COMMON_CAMERA_BASE_CAMERA_H

#include "Engine/Vfx/Common/Object.h"
#include "Engine/Vfx/IVfxObject/ICamera.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Camera {

class CameraAdjustment;

class BaseCamera : public Object, public IVfxObject::ICamera {
public:
    BaseCamera();
    BaseCamera(u8 adjustment_count);
    virtual ~BaseCamera();
    virtual void Update();
    virtual bool Has_Dirty_Flags();
    virtual const Math::Matrix& Get_Adjusted_View_Matrix();
    virtual const Math::Matrix& Get_Adjusted_Projection_Matrix();
    virtual const Math::Matrix& Get_View_Matrix();
    virtual const Math::Matrix& Get_Projection_Matrix();
    virtual const Math::Vector& Get_Up();
    virtual const Math::Vector& Get_Position();
    virtual const Math::Vector& Get_Target();
    virtual f32 Get_Aspect_Ratio();
    virtual f32 Get_Field_Of_View();
    virtual f32 Get_Near_Distance();
    virtual f32 Get_Far_Distance();
    virtual u32 func_00E3C830();
    virtual u32 func_00E3C840();
    virtual void Set_View_Matrix(Math::Matrix matrix);
    virtual void Set_Projection_Matrix(Math::Matrix matrix);
    virtual void Set_Up(Math::Vector up);
    virtual void Set_Position(Math::Vector position);
    virtual void Set_Target(Math::Vector target);
    virtual void Set_Aspect_Ratio(f32 aspect_ratio);
    virtual void Set_Field_Of_View(f32 field_of_view);
    virtual void Set_Near_Distance(f32 near_distance);
    virtual void Set_Far_Distance(f32 far_distance);
    virtual void func_00E3C8F0(u32 arg0);
    virtual void func_00E3C910(u32 arg0);

    s8 Reserve_Adjustment();
    void Release_Adjustment(s8 index);
    CameraAdjustment* Get_Adjustment(s8 index);
    void Enable_Adjustment(s8 index);
    void Disable_Adjustment(s8 index);
    bool Is_Adjustment_Enabled(s8 index);
    void Copy_State(const BaseCamera* camera);

private:
    void Initialize_(s32 adjustment_count);
    void Update_Adjusted_Projection_Matrix();
    void Update_View_Matrix();
    void Update_Adjusted_View_Matrix();
    void Update_Projection_Matrix();

    Math::Matrix viewMatrix;
    Math::Matrix projectionMatrix;
    Math::Matrix adjustedViewMatrix;
    Math::Matrix adjustedProjectionMatrix;
    Math::Vector up;
    Math::Vector position;
    Math::Vector target;
    f32 aspectRatio;
    f32 fieldOfView;
    f32 nearDistance;
    f32 farDistance;
    u32 unk_144;
    u32 unk_148;
    u16 unk_14C;
    u16 dirtyFlags;
    u8 unk_150;
    bool hasAdjustments;
    u8 adjustmentCount;
    CameraAdjustment** adjustments;
};

} // namespace Camera
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
