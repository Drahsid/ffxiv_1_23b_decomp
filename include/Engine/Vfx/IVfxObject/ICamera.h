#ifndef ENGINE_VFX_I_VFX_OBJECT_I_CAMERA_H
#define ENGINE_VFX_I_VFX_OBJECT_I_CAMERA_H

#include "Engine/Math/Matrix.h"
#include "Engine/Math/Vector.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace IVfxObject {

class ICamera {
public:
    virtual ~ICamera() {
    }
    virtual void Update() = 0;
    virtual bool Has_Dirty_Flags() = 0;
    virtual const Math::Matrix& Get_Adjusted_View_Matrix() = 0;
    virtual const Math::Matrix& Get_Adjusted_Projection_Matrix() = 0;
    virtual const Math::Matrix& Get_View_Matrix() = 0;
    virtual const Math::Matrix& Get_Projection_Matrix() = 0;
    virtual const Math::Vector& Get_Up() = 0;
    virtual const Math::Vector& Get_Position() = 0;
    virtual const Math::Vector& Get_Target() = 0;
    virtual f32 Get_Aspect_Ratio() = 0;
    virtual f32 Get_Field_Of_View() = 0;
    virtual f32 Get_Near_Distance() = 0;
    virtual f32 Get_Far_Distance() = 0;
    virtual u32 func_00E3C830() = 0;
    virtual u32 func_00E3C840() = 0;
    virtual void Set_View_Matrix(Math::Matrix matrix) = 0;
    virtual void Set_Projection_Matrix(Math::Matrix matrix) = 0;
    virtual void Set_Up(Math::Vector up) = 0;
    virtual void Set_Position(Math::Vector position) = 0;
    virtual void Set_Target(Math::Vector target) = 0;
    virtual void Set_Aspect_Ratio(f32 aspect_ratio) = 0;
    virtual void Set_Field_Of_View(f32 field_of_view) = 0;
    virtual void Set_Near_Distance(f32 near_distance) = 0;
    virtual void Set_Far_Distance(f32 far_distance) = 0;
    virtual void func_00E3C8F0(u32 arg0) = 0;
    virtual void func_00E3C910(u32 arg0) = 0;
};

} // namespace IVfxObject
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
