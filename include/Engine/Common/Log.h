#ifndef ENGINE_COMMON_LOG_H
#define ENGINE_COMMON_LOG_H

#include "Engine/Common/LogBase.h"
#include <windows.h>

static void Default_Log_Output(const char* text, s32 level) {
    if (level != 1) {
        OutputDebugStringA(text);
    }
}

extern "C" __declspec(selectany) LogCallback gLogCallback = Default_Log_Output;

#endif
