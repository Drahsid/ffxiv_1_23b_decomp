#include "Engine/CDevVfx/Common/Memory/Malloc.h"
#include "Engine/Memory/Allocator.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "Engine/Vfx/Common/Log.h"

using SQEX::CDev::Engine::Memory::Allocator;
using SQEX::CDev::Engine::Memory::AllocationInfo;
using SQEX::CDev::Engine::Vfx::Common::Io::Printer;
using SQEX::CDev::Engine::Vfx::Common::Io::func_004160E0;

extern "C" Allocator* D_0132807C;

static Allocator* D_01328088 = 0;
static s32 sRandomMallocSwitch = 0;

namespace SQEX {
namespace CDev {
namespace Engine {
namespace CDevVfx {
namespace Common {
namespace Memory {

static Allocator* Get_Allocator(Allocator* allocator) {
    if (allocator) {
        D_0132807C = allocator;
    }

    if (!D_0132807C) {
        D_0132807C = func_0040E500();
    }

    return D_0132807C;
}

static Allocator* func_00414F90(Allocator* allocator) {
    if (allocator) {
        D_01328088 = allocator;
    }

    if (!D_01328088) {
        D_01328088 = func_0040E500();
    }

    return D_01328088;
}

static void func_00414FB0(void* arg0) {
}

const char* Get_Allocation_Category(s32 category) {
    const char* must[] = {
        "CDev.Engine.Vfx.Must",
        "CDev.Engine.Vfx.MustFix",
        "CDev.Engine.Vfx.MustTemporary",
        "CDev.Engine.Vfx.Unhandled"
    };
    const char* engine[] = {
        "CDev.Engine.Vfx.Instance",
        "CDev.Engine.Vfx.Common",
        "CDev.Engine.Vfx.Stl",
        "CDev.Engine.Vfx.Qix",
        "CDev.Engine.Vfx.BaseControl",
        "CDev.Engine.Vfx.QixControl",
        "CDev.Engine.Vfx.IntermediateResource",
        "CDev.Engine.Vfx.ResourceLoader",
        "CDev.Engine.Vfx.VfxResourceFormat",
        "CDev.Engine.Vfx.VfxResourceModel"
    };
    const char* framework[] = {
        "CDev.Engine.Vfx.Framework.CDev",
        "CDev.Engine.Vfx.Framework.CDev.Vfx",
        "CDev.Engine.Vfx.Framework.CDev.Dw",
        "CDev.Engine.Vfx.Framework.CDev.Cut",
        "CDev.Engine.Vfx.Framework.CDev.Lay",
        "CDev.Engine.Vfx.Framework.CDev.Fw"
    };

    if (category <= 4) {
        return must[category];
    }

    if (category <= 18) {
        return engine[category - 8];
    }

    if (category >= 96 && category <= 101) {
        return framework[category - 96];
    }

    if (category >= 128 && category <= 191) {
        return "CDev.Engine.Vfx.Application";
    }

    return "CDev.Engine.Vfx.Unknown";
}

static u32 func_004150B0(void* arg0) {
    return 0;
}

static void* Allocate(u32 size, u32 category, s32 alignment, const char* function, const char* file, s32 line) {
    const char* category_name = Get_Allocation_Category(static_cast<s32>(category));
    Allocator* allocator = category != 14 ? Get_Allocator(0) : func_00414F90(0);
    return allocator->Allocate(size, AllocationInfo(alignment, category_name, function, file, line));
}

static void Free(void* memory) {
    if (memory) {
        reinterpret_cast<Allocator**>(memory)[-1]->Free(memory);
    }
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void VfxSwitchRandomVfxMalloc_StaticDebug(bool arg0) {
    if (!arg0) {
        sRandomMallocSwitch++;
    }
    else {
        sRandomMallocSwitch--;
    }
    
    if (sRandomMallocSwitch < 0) {
        func_004160E0(Printer::func_00415C90(), 0, "[Malloc] random malloc switch error.");
        VFX_ASSERT_AT(".\\Memory\\Malloc.cpp", 207, false);
    }
}

void Initialize_Malloc() {
    func_00416400(Allocate, Free, func_00414FB0, func_004150B0, VfxSwitchRandomVfxMalloc_StaticDebug);
}

} // namespace Memory
} // namespace Common
} // namespace CDevVfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
