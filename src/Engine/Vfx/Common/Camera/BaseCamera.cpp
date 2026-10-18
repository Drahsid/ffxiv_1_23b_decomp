#include "Engine/Vfx/Common/Camera/BaseCamera.h"
#include "Engine/Vfx/Common/Camera/CameraAdjustment.h"
#include "Engine/Common/LogBase.h"
#include <math.h>
#include <windows.h>
#include <xmmintrin.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Common {
namespace Camera {

s8 BaseCamera::Reserve_Adjustment() {
    for (s32 index = 0; index < adjustmentCount; index++) {
        CameraAdjustment* adjustment = adjustments[index];
        if (!adjustment->enabled) {
            if (!adjustment->unk_05) {
                adjustment->enabled = true;
            }
            return static_cast<s8>(index);
        }
    }
    return -1;
}

void BaseCamera::Release_Adjustment(s8 index) {
    if (index < adjustmentCount && index >= 0) {
        if (!adjustments[index]->unk_05) {
            adjustments[index]->enabled = false;
        }
    }
}

CameraAdjustment* BaseCamera::Get_Adjustment(s8 index) {
    if (index < adjustmentCount && index >= 0) {
        return adjustments[index];
    }
    return 0;
}

void BaseCamera::Enable_Adjustment(s8 index) {
    CameraAdjustment* adjustment = Get_Adjustment(index);
    if (!adjustment->unk_05) {
        adjustment->enabled = true;
    }
    hasAdjustments = true;
}

void BaseCamera::Disable_Adjustment(s8 index) {
    CameraAdjustment* adjustment = Get_Adjustment(index);
    if (!adjustment->unk_05) {
        adjustment->enabled = false;
    }

    for (s32 index = 0; index < adjustmentCount; index++) {
        if (Get_Adjustment(static_cast<s8>(index))->enabled) {
            hasAdjustments = true;
            return;
        }
    }
    hasAdjustments = false;
}

bool BaseCamera::Is_Adjustment_Enabled(s8 index) {
    return Get_Adjustment(index)->enabled;
}

bool BaseCamera::Has_Dirty_Flags() {
    return dirtyFlags != 0;
}

const Math::Matrix& BaseCamera::Get_Adjusted_View_Matrix() {
    return adjustedViewMatrix;
}

const Math::Matrix& BaseCamera::Get_Adjusted_Projection_Matrix() {
    return adjustedProjectionMatrix;
}

const Math::Matrix& BaseCamera::Get_View_Matrix() {
    return viewMatrix;
}

const Math::Matrix& BaseCamera::Get_Projection_Matrix() {
    return projectionMatrix;
}

const Math::Vector& BaseCamera::Get_Up() {
    return up;
}

const Math::Vector& BaseCamera::Get_Position() {
    return position;
}

const Math::Vector& BaseCamera::Get_Target() {
    return target;
}

f32 BaseCamera::Get_Aspect_Ratio() {
    return aspectRatio;
}

f32 BaseCamera::Get_Field_Of_View() {
    return fieldOfView;
}

f32 BaseCamera::Get_Near_Distance() {
    return nearDistance;
}

f32 BaseCamera::Get_Far_Distance() {
    return farDistance;
}

u32 BaseCamera::func_00E3C830() {
    return unk_144;
}

u32 BaseCamera::func_00E3C840() {
    return unk_148;
}

namespace {

void Default_Log_Output(const char* text, s32 level) {
    if (level != 1) {
        OutputDebugStringA(text);
    }
}

} // namespace

void BaseCamera::Set_Aspect_Ratio(f32 aspect_ratio) {
    aspectRatio = aspect_ratio;
    dirtyFlags |= 0x10;
}

void BaseCamera::Set_Field_Of_View(f32 field_of_view) {
    fieldOfView = field_of_view;
    dirtyFlags |= 0x20;
}

void BaseCamera::Set_Near_Distance(f32 near_distance) {
    nearDistance = near_distance;
    dirtyFlags |= 0x40;
}

void BaseCamera::Set_Far_Distance(f32 far_distance) {
    farDistance = far_distance;
    dirtyFlags |= 0x40;
}

void BaseCamera::func_00E3C8F0(u32 arg0) {
    unk_144 = arg0;
    dirtyFlags |= 0x80;
}

void BaseCamera::func_00E3C910(u32 arg0) {
    unk_148 = arg0;
    dirtyFlags |= 0x80;
}

namespace {

static f32 Degrees_To_Radians(f32 value) {
    return static_cast<f32>(value * 3.1415927f / 180.0);
}

__m128 Set_W(__m128 value, __m128 w) {
    return _mm_shuffle_ps(value, _mm_unpackhi_ps(value, w), _MM_SHUFFLE(3, 0, 1, 0));
}

__m128 Reciprocal_Square_Root(__m128 value) {
    __m128 estimate = _mm_rsqrt_ps(value);
    __m128 correction = _mm_sub_ps(_mm_set1_ps(1.0f), _mm_mul_ps(_mm_mul_ps(estimate, value), estimate));
    __m128 half_estimate = _mm_mul_ps(_mm_set1_ps(0.5f), estimate);
    return _mm_add_ps(_mm_mul_ps(correction, half_estimate), estimate);
}

} // namespace

void BaseCamera::Copy_State(const BaseCamera* camera) {
    viewMatrix = camera->viewMatrix;
    projectionMatrix = camera->projectionMatrix;
    adjustedViewMatrix = camera->adjustedViewMatrix;
    adjustedProjectionMatrix = camera->adjustedProjectionMatrix;
    up = camera->up;
    position = camera->position;
    target = camera->target;
    aspectRatio = camera->aspectRatio;
    fieldOfView = camera->fieldOfView;
    nearDistance = camera->nearDistance;
    farDistance = camera->farDistance;
    unk_144 = camera->unk_144;
    unk_148 = camera->unk_148;
    unk_14C = camera->unk_14C;
    dirtyFlags = camera->dirtyFlags;
    unk_150 = camera->unk_150;
    Update();
}

void BaseCamera::Set_View_Matrix(Math::Matrix matrix) {
    viewMatrix = matrix;
    dirtyFlags |= 0x1000;
}

void BaseCamera::Set_Projection_Matrix(Math::Matrix matrix) {
    projectionMatrix = matrix;
    dirtyFlags |= 0x2000;
}

void BaseCamera::Set_Up(Math::Vector up) {
    this->up = up;
    dirtyFlags |= 0x2;
}

void BaseCamera::Set_Position(Math::Vector position) {
    this->position = position;
    dirtyFlags |= 0x4;
}

void BaseCamera::Set_Target(Math::Vector target) {
    this->target = target;
    dirtyFlags |= 0x8;
}

void BaseCamera::Initialize_(s32 adjustment_count) {
    up.Set(0.0f, 1.0f, 0.0f, 1.0f);
    position.Set(0.0f, 0.0f, 10.0f, 1.0f);
    target.Set(0.0f, 0.0f, 0.0f, 1.0f);
    aspectRatio = 16.0f / 9.0f;
    fieldOfView = Degrees_To_Radians(45.0f);
    unk_144 = 1280;
    unk_148 = 720;
    nearDistance = 1.0f;
    farDistance = 1000000.0f;
    dirtyFlags = 0xFF;
    hasAdjustments = false;
    adjustmentCount = static_cast<u8>(adjustment_count);
    u32 array_size = sizeof(CameraAdjustment*) * static_cast<u8>(adjustment_count);
    adjustments = static_cast<CameraAdjustment**>(func_00416480(array_size, 1, 16, __FUNCTION__, ".\\Camera\\BaseCamera.cpp", 413));
    for (s32 index = 0; index < adjustment_count; index++) {
        adjustments[index] = ::new (1, 16, __FUNCTION__, ".\\Camera\\BaseCamera.cpp", 416) CameraAdjustment(this);
    }
    Update();
}

void BaseCamera::Update_Adjusted_Projection_Matrix() {
    adjustedProjectionMatrix = projectionMatrix;
    if (hasAdjustments) {
        f32 zoom = 0.0f;
        s32 count = adjustmentCount;
        for (s32 index = 0; index < count; index++) {
            CameraAdjustment* adjustment = adjustments[index];
            if (adjustment->enabled && fabsf(zoom) < fabsf(adjustment->zoom)) {
                zoom = adjustment->zoom;
            }
        }

        if (zoom != 0.0f) {
            f32 angle = 3.1415927f / 2 - zoom * 0.5;
            f32 scale = tanf(angle);
            f32 ratio = adjustedProjectionMatrix.values[1].y / adjustedProjectionMatrix.values[0].x;
            adjustedProjectionMatrix.values[0].x = scale / ratio;
            adjustedProjectionMatrix.values[1].y = scale;
        }
    }
}

namespace {

void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

} // namespace

BaseCamera::BaseCamera() {
    Initialize_(0);
}

BaseCamera::~BaseCamera() {
    if (adjustments) {
        for (s32 index = 0; index < adjustmentCount; index++) {
            CameraAdjustment* adjustment = adjustments[index];
            if (adjustment) {
                adjustment->~CameraAdjustment();
                func_004162C0(adjustment);
            }
        }
        func_004162C0(adjustments);
    }
}

void BaseCamera::Update_View_Matrix() {
    if (!(dirtyFlags & 0x1000) && (dirtyFlags & 0xE)) {
        Math::Matrix matrix;
        viewMatrix = *Math::func_007DF590(&matrix, &position, &target, &up);
    }
    dirtyFlags &= ~0x100E;
}

void BaseCamera::Update_Adjusted_View_Matrix() {
    adjustedViewMatrix = viewMatrix;
    if (hasAdjustments) {
        Math::Vector translation(0.0f, 0.0f, 0.0f, 0.0f);
        f32 rotation = 0.0f;
        s32 count = adjustmentCount;
        for (s32 index = 0; index < count; index++) {
            CameraAdjustment* adjustment = adjustments[index];
            if (adjustment->enabled) {
                f32* component = translation.values;
                f32* adjustment_component = adjustment->translation.values;
                for (s32 jndex = 0; jndex < 3; jndex++) {
                    if (fabsf(component[jndex]) < fabsf(adjustment_component[jndex])) {
                        component[jndex] = adjustment_component[jndex];
                    }
                }
                if (fabsf(rotation) < fabsf(adjustment->rotation)) {
                    rotation = adjustment->rotation;
                }
            }
        }

        if (rotation != 0.0f) {
            Math::Matrix matrix;
            Math::func_0042FEB0(&matrix, rotation);
            adjustedViewMatrix = matrix * adjustedViewMatrix;
        }
        
        Math::Vector value;
        value = adjustedViewMatrix.values[3] + translation;
        value.w = 1.0f;
        adjustedViewMatrix.values[3] = value;
    }
}

void BaseCamera::Update_Projection_Matrix() {
    if (!(dirtyFlags & 0x2000) && (dirtyFlags & 0x71)) {
        Math::Matrix matrix;
        Math::func_007DF8C0(&matrix, fieldOfView, aspectRatio, nearDistance, farDistance);
        projectionMatrix = matrix;
    }
    dirtyFlags &= ~0x2071;
}

BaseCamera::BaseCamera(u8 adjustment_count) {
    Initialize_(adjustment_count);
}

void BaseCamera::Update() {
    Update_View_Matrix();
    Update_Projection_Matrix();
    Update_Adjusted_View_Matrix();
    Update_Adjusted_Projection_Matrix();
    dirtyFlags = 0;
}

} // namespace Camera
} // namespace Common
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
