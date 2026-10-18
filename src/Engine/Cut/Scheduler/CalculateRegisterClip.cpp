#include "Engine/Common/Log.h"
#include "Engine/Common/Assert.h"
#include "Engine/Cut/Scheduler/CalculateRegisterClip.h"

using namespace SQEX::CDev::Engine::Cut::Scheduler;

template<class T>
inline void Defer_Default_Assert_Handler() {
}

void CalculateRegisterClip::func_00A20F90(ClipParameter* parameter) {
    ClipBase::func_00A20F90(parameter);
}

CalculateRegisterClip::CalculateRegisterClip(const ClipData* data, void* arg1)
    : BaseClipImpl<CALCULATEREGISTERCLIP_CLIP_DATA>(data, arg1) {
}

CalculateRegisterClip::~CalculateRegisterClip() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    Defer_Default_Assert_Handler<void>();
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

s32 CalculateRegisterClip::Arithmetic(s32 operation, s32 value1, s32 value2) {
    switch (operation) {
    case 0:
        return value1 + value2;
    case 1:
        return value1 - value2;
    case 2:
        return value1 * value2;
    case 3:
        // "Division by zero occurred in CalculateRegisterClip"
        LOG_ASSERTION_AT(".\\CalculateRegisterClip.cpp", 102, value2!=0, "CalculateRegisterClipでゼロ割り発生");
        if (value2 != 0) {
            return value1 / value2;
        }
        break;
    case 4:
        // "Division by zero occurred in CalculateRegisterClip"
        LOG_ASSERTION_AT(".\\CalculateRegisterClip.cpp", 107, value2!=0, "CalculateRegisterClipでゼロ割り発生");
        if (value2 != 0) {
            return value1 % value2;
        }
        break;
    case 5:
        return value1 & value2;
    case 6:
        return value1 << value2;
    case 7:
        return value1 >> value2;
    }
    return 0;
}
