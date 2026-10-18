#include "Engine/Vfx/Qix/Data/ControlInstance.h"
#include "Engine/Vfx/Common/Log.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

ControlInstance::ControlInstance(u32 arg0, void* arg1, u16 arg2)
    : controlNodeWorkBufferOffsetOnUnitBuffer(0), randomExtensionWorkBufferOffsetOnUnitBuffer(0) {
    unk_00 = arg0;
    unk_04 = true;
    unk_08 = arg1;
    unk_14 = arg2;
}

void ControlInstance::func_00BD20F0(u32 arg0) {
    if (unk_04) {
        unk_00 += arg0;
    }
}

void* ControlInstance::func_00BD2100() {
    return unk_08;
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

u32 ControlInstance::GetControlNodeWorkBufferOffsetOnUnitBuffer() {
    VFX_ASSERT_AT(".\\Data\\ControlInstance_Data.cpp", 85, controlNodeWorkBufferOffsetOnUnitBuffer != 0);
    return controlNodeWorkBufferOffsetOnUnitBuffer;
}

void ControlInstance::SetControlNodeWorkBufferOffsetOnUnitBuffer(u32 arg0) {
    VFX_ASSERT_AT(".\\Data\\ControlInstance_Data.cpp", 96, controlNodeWorkBufferOffsetOnUnitBuffer == 0);
    controlNodeWorkBufferOffsetOnUnitBuffer = arg0;
}

u32 ControlInstance::GetRandomExtensionWorkBufferOffsetOnUnitBuffer() {
    VFX_ASSERT_AT(".\\Data\\ControlInstance_Data.cpp", 107, randomExtensionWorkBufferOffsetOnUnitBuffer != 0);
    return randomExtensionWorkBufferOffsetOnUnitBuffer;
}

void ControlInstance::SetRandomExtensionWorkBufferOffsetOnUnitBuffer(u32 arg0) {
    VFX_ASSERT_AT(".\\Data\\ControlInstance_Data.cpp", 118, randomExtensionWorkBufferOffsetOnUnitBuffer == 0);
    randomExtensionWorkBufferOffsetOnUnitBuffer = arg0;
}

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
