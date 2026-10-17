#ifndef ENGINE_COMMON_ASSERT_H
#define ENGINE_COMMON_ASSERT_H

#include "Engine/Common/Log.h"

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

struct Assertion {
    __declspec(noinline) Assertion(const char* expression, const char* message, const char* file, s32 line, const char* function) {
        Get_Assert_Callback(Default_Assert_Handler)(expression, message, file, line, function);
    }
};

#define LOG_ASSERTION_AT(file, line, expression, message) \
    do { \
        if (!(expression)) { \
            Assertion(#expression, message, file, line, __FUNCTION__); \
        } \
    } while (0)

#endif
