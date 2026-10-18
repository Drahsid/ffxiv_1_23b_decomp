#ifndef ENGINE_CUT_SCHEDULER_CALCULATE_REGISTER_CLIP_H
#define ENGINE_CUT_SCHEDULER_CALCULATE_REGISTER_CLIP_H

#include "Engine/Cut/Scheduler/BaseClipImpl.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "Engine/Cut/Scheduler/Scheduler.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Scheduler {

struct CALCULATEREGISTERCLIP_CLIP_DATA : ClipData {
    s8 targetRegisterIndex;
    u8 operandMode;
    s8 operation;
    s8 firstRegisterIndex;
    s8 secondRegisterIndex;
    u8 unk_15[3];
    s32 value;
};

class CalculateRegisterClip : public BaseClipImpl<CALCULATEREGISTERCLIP_CLIP_DATA> {
public:
    CalculateRegisterClip(const ClipData* data, void* arg1);
    virtual ~CalculateRegisterClip();
    virtual void OnEnter(ClipParameter* parameter) {
        ClipBase::OnEnter(parameter);
        const CALCULATEREGISTERCLIP_CLIP_DATA* data = static_cast<const CALCULATEREGISTERCLIP_CLIP_DATA*>(mClipData);
        ScheduleRegister* registers = &parameter->func_00A20070()->registers;
        if (data->operandMode == 0) {
            s32 value = Arithmetic(data->operation, registers->Get_Number_Register(data->firstRegisterIndex), data->value);
            func_00A21110(value);
            registers->Set_Number_Register(data->targetRegisterIndex, value);
        }
        else if (data->operandMode == 1) {
            s32 value = Arithmetic(
                data->operation,
                registers->Get_Number_Register(data->firstRegisterIndex),
                registers->Get_Number_Register(data->secondRegisterIndex)
            );
            func_00A21110(value);
            registers->Set_Number_Register(data->targetRegisterIndex, value);
        }
        else {
            func_00A21110(data->value);
            registers->Set_Number_Register(data->targetRegisterIndex, data->value);
        }
    }

    virtual void func_00A20F90(ClipParameter* parameter);

private:
    s32 Arithmetic(s32 operation, s32 value1, s32 value2);
};

} // namespace Scheduler
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
