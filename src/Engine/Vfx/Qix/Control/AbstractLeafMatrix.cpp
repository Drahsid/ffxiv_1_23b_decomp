#include "Engine/Vfx/Qix/Control/AbstractLeafMatrix.h"
#include "Engine/Vfx/Common/Log.h"

extern "C" void* func_00E3ACF0();

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Control {

struct LeafMatrixCallbackOwner {
    u8 unk_00[0xA8];
    void (__cdecl* unk_A8)(u32, void*);
};

struct LeafMatrixLink {
    u8 unk_00[8];
    LeafMatrixCallbackOwner* unk_08;
};

struct LeafMatrixSource {
    u8 unk_00[8];
    LeafMatrixLink* unk_08;
};

struct LeafMatrixContext {
    u32 unk_00;
    LeafMatrixSource* unk_04;
};

struct LeafMatrixPointerArgument {
    u32 unk_00;
    void* unk_04;
};

struct LeafMatrixWordArgument {
    u32 unk_00;
    u32 unk_04;
};

struct LeafMatrixArguments {
    u32 unk_00;
    u32 unk_04;
    void* unk_08;
};

void AbstractLeafMatrix::ByQix_Static_(LeafMatrixContext* arg0, void* arg1) {
    LeafMatrixCallbackOwner* owner = arg0->unk_04->unk_08->unk_08;
    if (!owner->unk_A8) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "ByQix が定義されていない"); // "ByQix is not defined"
        VFX_ASSERT_AT(".\\Control\\AbstractLeafMatrix.cpp", 37, false);
    }
    owner->unk_A8(arg0->unk_00, arg1);
}

void AbstractLeafMatrix::func_00BDA180(LeafMatrixContext* arg0, void* arg1) {
    LeafMatrixPointerArgument argument;
    argument.unk_00 = 0;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

void* AbstractLeafMatrix::func_00BDA1B0(LeafMatrixContext* arg0) {
    LeafMatrixPointerArgument argument;
    argument.unk_00 = 1;
    ByQix_Static_(arg0, &argument);
    if (!argument.unk_04) {
        return func_00E3ACF0();
    }
    return argument.unk_04;
}

void AbstractLeafMatrix::func_00BDA1E0(LeafMatrixContext* arg0, void* arg1) {
    LeafMatrixPointerArgument argument;
    argument.unk_00 = 2;
    argument.unk_04 = arg1;
    ByQix_Static_(arg0, &argument);
}

void* AbstractLeafMatrix::func_00BDA210(LeafMatrixContext* arg0) {
    LeafMatrixPointerArgument argument;
    argument.unk_00 = 3;
    ByQix_Static_(arg0, &argument);
    if (!argument.unk_04) {
        return func_00E3ACF0();
    }
    return argument.unk_04;
}

u32 AbstractLeafMatrix::func_00BDA240(LeafMatrixContext* arg0) {
    LeafMatrixWordArgument argument;
    argument.unk_00 = 4;
    ByQix_Static_(arg0, &argument);
    return argument.unk_04;
}

void AbstractLeafMatrix::GetLeafMatrix_Static(LeafMatrixCallbackOwner* arg0, u32 arg1, void* arg2) {
    LeafMatrixArguments argument;
    argument.unk_00 = 5;
    argument.unk_04 = arg1;
    argument.unk_08 = arg2;
    if (!arg0->unk_A8) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "ByQix が定義されていない"); // "ByQix is not defined"
        VFX_ASSERT_AT(".\\Control\\AbstractLeafMatrix.cpp", 122, false);
    }
    arg0->unk_A8(0, &argument);
}

} // namespace Control
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
