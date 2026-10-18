#include "Engine/Vfx/Qix/Control/AbstractLeafColorRGBA.h"
#include "Engine/Vfx/Common/Log.h"

extern "C" void* func_00E3AD40();

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Control {

struct LeafColorCallbackOwner {
    u8 unk_00[0xA8];
    void (__cdecl* unk_A8)(u32, void*);
};

struct LeafColorLink {
    u8 unk_00[8];
    LeafColorCallbackOwner* unk_08;
};

struct LeafColorSource {
    u8 unk_00[8];
    LeafColorLink* unk_08;
};

struct LeafColorContext {
    u32 unk_00;
    LeafColorSource* unk_04;
};

struct LeafColorWordArgument {
    u32 unk_00;
    u32 unk_04;
};

struct LeafColorPointerArgument {
    u32 unk_00;
    void* unk_04;
};

struct LeafColorBoolArgument {
    u32 unk_00;
    bool unk_04;
};

struct LeafColorPairArgument {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
};

struct LeafColorExtendedArgument {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    bool unk_0C;
};

struct LeafColorDistanceArgument {
    u32 unk_00;
    u32 unk_04;
    f32 unk_08;
    f32 unk_0C;
};

void AbstractLeafColorRGBA::ByQix_Static_(LeafColorContext* arg0, void* arg1) {
    LeafColorCallbackOwner* owner = arg0->unk_04->unk_08->unk_08;
    if (!owner->unk_A8) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "ByQix が定義されていない"); // "ByQix is not defined"
        VFX_ASSERT_AT(".\\Control\\AbstractLeafColorRGBA.cpp", 36, false);
    }
    owner->unk_A8(arg0->unk_00, arg1);
}

void AbstractLeafColorRGBA::func_00BD9CF0(LeafColorContext* arg0, u32 arg1) {
    LeafColorWordArgument argument;
    argument.unk_00 = 0;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

void* AbstractLeafColorRGBA::func_00BD9D20(LeafColorContext* arg0) {
    LeafColorPointerArgument argument;
    argument.unk_00 = 1;
    ByQix_Static_(arg0, &argument);
    if (!argument.unk_04) {
        return func_00E3AD40();
    }
    return argument.unk_04;
}

u32 AbstractLeafColorRGBA::func_00BD9D50(LeafColorContext* arg0) {
    LeafColorWordArgument argument;
    argument.unk_00 = 4;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

u32 AbstractLeafColorRGBA::func_00BD9D80(LeafColorContext* arg0, u32* arg1) {
    LeafColorPairArgument argument;
    argument.unk_00 = 5;
    argument.unk_04 = 0;
    argument.unk_08 = 0;
    ByQix_Static_(arg0, &argument);
    *arg1 = argument.unk_08;
    return argument.unk_04;
}

u32 AbstractLeafColorRGBA::func_00BD9DC0(LeafColorContext* arg0) {
    LeafColorWordArgument argument;
    argument.unk_00 = 6;
    argument.unk_04 = 0;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

bool AbstractLeafColorRGBA::func_00BD9DF0(LeafColorContext* arg0) {
    LeafColorBoolArgument argument;
    argument.unk_00 = 7;
    argument.unk_04 = false;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

bool AbstractLeafColorRGBA::func_00BD9E20(LeafColorContext* arg0) {
    LeafColorBoolArgument argument;
    argument.unk_00 = 8;
    argument.unk_04 = false;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

void AbstractLeafColorRGBA::func_00BD9E50(LeafColorContext* arg0, u32 arg1) {
    LeafColorWordArgument argument;
    argument.unk_00 = 9;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

void AbstractLeafColorRGBA::func_00BD9E80(LeafColorContext* arg0, u32 arg1) {
    LeafColorWordArgument argument;
    argument.unk_00 = 10;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

bool AbstractLeafColorRGBA::func_00BD9EB0(LeafColorContext* arg0) {
    LeafColorBoolArgument argument;
    argument.unk_00 = 11;
    argument.unk_04 = false;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

void AbstractLeafColorRGBA::func_00BD9EE0(LeafColorContext* arg0, u32 arg1) {
    LeafColorWordArgument argument;
    argument.unk_00 = 12;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

bool AbstractLeafColorRGBA::func_00BD9F10(LeafColorContext* arg0, u32 arg1) {
    LeafColorExtendedArgument argument;
    argument.unk_00 = 14;
    argument.unk_04 = arg1;
    argument.unk_08 = 0;
    argument.unk_0C = true;
    ByQix_Static_(arg0, &argument);
    return argument.unk_0C;
}

void AbstractLeafColorRGBA::GetDistanceClip_Static(LeafColorCallbackOwner* arg0, u32 arg1, f32* arg2, f32* arg3) {
    LeafColorDistanceArgument argument;
    argument.unk_00 = 13;
    argument.unk_04 = arg1;
    argument.unk_08 = -1.0f;
    argument.unk_0C = -1.0f;
    if (!arg0->unk_A8) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "ByQix が定義されていない"); // "ByQix is not defined"
        VFX_ASSERT_AT(".\\Control\\AbstractLeafColorRGBA.cpp", 231, false);
    }
    arg0->unk_A8(0, &argument);
    *arg2 = argument.unk_08;
    *arg3 = argument.unk_0C;
}

} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
