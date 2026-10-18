#ifndef ENGINE_COMMON_ASSERT_H
#define ENGINE_COMMON_ASSERT_H

#include "Engine/Common/LogBase.h"

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function);

struct Assertion {
    __declspec(noinline) Assertion(const char* expression, const char* message, const char* file, s32 line, const char* function) {
        Get_Assert_Callback(Default_Assert_Handler)(expression, message, file, line, function);
    }
};

#define LOG_ASSERTION_AT(file, line, expression, message) \
    switch (static_cast<s32>(!!(expression))) \
    case 0: Assertion(#expression, message, file, line, __FUNCTION__)

#endif
