#ifndef ENGINE_COMMON_LOG_H
#define ENGINE_COMMON_LOG_H

#include "types.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

static void Default_Log_Output(const char* text, s32 level) {
    if (level != 1) {
        OutputDebugStringA(text);
    }
}

extern "C" __declspec(selectany) void (*gLogCallback)(const char*, s32) = Default_Log_Output;

typedef void (*AssertCallback)(const char*, const char*, const char*, s32, const char*);

inline AssertCallback& Get_Assert_Callback(AssertCallback default_callback) {
    static AssertCallback callback = default_callback;
    return callback;
}

#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_ASSERT 6

#define LOG_ERROR_AT(file, line, format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 2] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 2, "[ERROR:%s:%d] " format, file, line, __VA_ARGS__); \
        strcat_s(buffer, sizeof(buffer), "\n"); \
        gLogCallback(buffer, LOG_LEVEL_ERROR); \
    } while (0)

#define LOG_WARNING(format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 2] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 2, "[WARNING]" format, __VA_ARGS__); \
        strcat_s(buffer, sizeof(buffer), "\n"); \
        gLogCallback(buffer, LOG_LEVEL_WARNING); \
    } while (0)

#define LOG_PRINT(format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 1] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, format, __VA_ARGS__); \
        gLogCallback(buffer, LOG_LEVEL_WARNING); \
    } while (0)

#define LOG_ERROR(format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 2] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 2, format, __VA_ARGS__); \
        strcat_s(buffer, sizeof(buffer), "\n"); \
        gLogCallback(buffer, LOG_LEVEL_ERROR); \
    } while (0)

#define LOG_ASSERT_FAILURE(expression, message, file, line, function) \
    do { \
        char buffer[2048]; \
        if (function) { \
            _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, "%s(%d):[%s] <assert> (%s) %s\n", file, line, function, expression, message); \
        } \
        else { \
            _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, "%s(%d): <assert> (%s) %s\n", file, line, expression, message); \
        } \
        gLogCallback(buffer, LOG_LEVEL_ASSERT); \
        *static_cast<volatile u32*>(0) = 0; \
    } while (0)

#define LOG_ASSERT_AT(file, line, expression, message) \
    do { \
        if (!(expression)) { \
            Get_Assert_Callback(Default_Assert_Handler)(#expression, message, file, line, __FUNCTION__); \
        } \
    } while (0)

#endif
