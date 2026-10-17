#ifndef ENGINE_VFX_COMMON_LOG_H
#define ENGINE_VFX_COMMON_LOG_H

#include "Engine/Common/Log.h"
#include "Engine/Vfx/Common/Io/Printer.h"

#define VFX_ASSERT_AT(file, line, expression) \
    do { \
        if (!(expression)) { \
            ::SQEX::CDev::Engine::Vfx::Common::Io::Printer::func_00415C90()->func_00415A00(100); \
            LOG_ASSERT_AT(file, line, false, ""); \
        } \
    } while (0)

#endif
