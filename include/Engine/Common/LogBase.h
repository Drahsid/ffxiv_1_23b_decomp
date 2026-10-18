#ifndef ENGINE_COMMON_LOG_BASE_H
#define ENGINE_COMMON_LOG_BASE_H

#include "types.h"
#include <stdio.h>
#include <string.h>

typedef void (*LogCallback)(const char*, s32);
typedef void (*AssertCallback)(const char*, const char*, const char*, s32, const char*);

extern "C" LogCallback gLogCallback;

inline AssertCallback& Get_Assert_Callback(AssertCallback default_callback) {
    static AssertCallback callback = default_callback;
    return callback;
}

#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_ASSERT 6

#define LOG_FORMAT_LINE(level, format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 2] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 2, format, __VA_ARGS__); \
        strcat_s(buffer, sizeof(buffer), "\n"); \
        gLogCallback(buffer, level); \
    } while (0)

#define LOG_ERROR_AT(file, line, format, ...) \
    LOG_FORMAT_LINE(LOG_LEVEL_ERROR, "[ERROR:%s:%d] " format, file, line, __VA_ARGS__)

#define LOG_WARNING(format, ...) \
    LOG_FORMAT_LINE(LOG_LEVEL_WARNING, "[WARNING]" format, __VA_ARGS__)

#define LOG_ERROR(format, ...) \
    LOG_FORMAT_LINE(LOG_LEVEL_ERROR, format, __VA_ARGS__)

#define LOG_PRINT(format, ...) \
    do { \
        char buffer[1024]; \
        buffer[sizeof(buffer) - 1] = 0; \
        _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, format, __VA_ARGS__); \
        gLogCallback(buffer, LOG_LEVEL_WARNING); \
    } while (0)

#define LOG_ASSERT_FAILURE_FORMATS(expression, message, file, line, function, format_with_function, format_without_function) \
    do { \
        char buffer[2048]; \
        if (function) { \
            _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, format_with_function, file, line, function, expression, message); \
        } \
        else { \
            _snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, format_without_function, file, line, expression, message); \
        } \
        gLogCallback(buffer, LOG_LEVEL_ASSERT); \
        *static_cast<u32*>(0) = 0; \
    } while (0)

#define LOG_ASSERT_FAILURE(expression, message, file, line, function) \
    LOG_ASSERT_FAILURE_FORMATS(expression, message, file, line, function, "%s(%d):[%s] <assert> (%s) %s\n", "%s(%d): <assert> (%s) %s\n")

#define LOG_ASSERT_AT(file, line, expression, message) \
    switch (static_cast<s32>(!!(expression))) \
    case 0: Get_Assert_Callback(Default_Assert_Handler)(#expression, message, file, line, __FUNCTION__)

#endif
