#ifndef ENGINE_VFX_QIX_DATA_CONTROL_INSTANCE_H
#define ENGINE_VFX_QIX_DATA_CONTROL_INSTANCE_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Data {

class ControlInstance {
public:
    ControlInstance(u32 arg0, void* arg1, u16 arg2);
    void func_00BD20F0(u32 arg0);
    void* func_00BD2100();
    u32 GetControlNodeWorkBufferOffsetOnUnitBuffer();
    void SetControlNodeWorkBufferOffsetOnUnitBuffer(u32 arg0);
    u32 GetRandomExtensionWorkBufferOffsetOnUnitBuffer();
    void SetRandomExtensionWorkBufferOffsetOnUnitBuffer(u32 arg0);
private:
    u32 unk_00;
    bool unk_04;
    void* unk_08;
    u32 controlNodeWorkBufferOffsetOnUnitBuffer;
    u32 randomExtensionWorkBufferOffsetOnUnitBuffer;
    u16 unk_14;
    u8 unk_16[6];
};

} // namespace Data
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
