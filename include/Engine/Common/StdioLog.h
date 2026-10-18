#ifndef ENGINE_COMMON_STDIO_LOG_H
#define ENGINE_COMMON_STDIO_LOG_H

#include "Engine/Common/LogBase.h"

static void Default_Log_Output(const char* text, s32 level) {
    if (level != 1) {
        fputs(text, stdout);
    }
}

extern "C" __declspec(selectany) LogCallback gLogCallback = Default_Log_Output;

#endif
