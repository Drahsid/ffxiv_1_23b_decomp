#include "Engine/Vfx/Qix/DrawLayer/DrawLayerManager.h"
#include "Engine/Vfx/Common/Log.h"
#include "Engine/Vfx/Common/Memory/Memory.h"
#include "asm.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace DrawLayer {

class DrawLayerInterfacePrefix {
public:
    virtual void unk_00() = 0;
    virtual void unk_04() = 0;
    virtual void unk_08() = 0;
    virtual void unk_0C() = 0;
    virtual s32 func_00A5E0C0(const char* arg0) = 0;
    virtual const void* func_00A5E0D0(u8 arg0) = 0;
    virtual s32 func_00A5E0F0() = 0;
    virtual const void* func_00A5E100(u8 arg0) = 0;
};

extern "C" const char* D_01303F78 = "EFF";

void DrawLayerManager::func_00BD4FB0() {
    if (unk_00) {
        func_004162C0(unk_00);
        unk_00 = 0;
    }
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

void DrawLayerManager::Initialize(::SQEX::CDev::Engine::Common::ISceneObject::DrawLayer::IDrawLayerManager* arg0) {
    func_00BD4FB0();
    DrawLayerInterfacePrefix* interface_view = reinterpret_cast<DrawLayerInterfacePrefix*>(arg0);
    unk_04 = interface_view->func_00A5E0F0();
    const u32 allocation_size = (unk_04 + 1) * sizeof(DrawLayerEntryPrefix);
    unk_00 = static_cast<DrawLayerEntryPrefix*>(func_00416480(
        allocation_size,
        1,
        16,
        __FUNCTION__,
        ".\\DrawLayer\\DrawLayerManager.cpp",
        41
    ));

    if (!unk_00) {
        Common::Io::func_004160E0(Common::Io::Printer::func_00415C90(), 0, "[DrawLayerManager] alloc error.");
        VFX_ASSERT_AT(".\\DrawLayer\\DrawLayerManager.cpp", 42, false);
    }

    for (s32 index = 0; index < unk_04; ++index) {
        const void* descriptor = interface_view->func_00A5E0D0(static_cast<u8>(index));
        const void* value = interface_view->func_00A5E100(static_cast<u8>(index));
        const s8 layer_index = static_cast<s8>(index);
        DrawLayerEntryPrefix* entry;
        if (layer_index >= 0) {
            entry = unk_00 + layer_index;
        }
        else {
            u32 offset = -1 - layer_index;
            entry = unk_00 + (unk_04 + offset);
        }
        ::new (entry) DrawLayerEntryPrefix;
        entry->func_00BE8730(static_cast<s8>(index), descriptor, value);
    }

    DrawLayerEntryPrefix* entry = unk_00 + unk_04;
    ::new (entry) DrawLayerEntryPrefix;
    s32 index = interface_view->func_00A5E0C0(D_01303F78);
    if (index < 0) {
        Common::Io::func_004160E0(
            Common::Io::Printer::func_00415C90(),
            0,
            "VeffCenter を解決するレイヤーが存在しません" // "No layer exists to resolve VeffCenter"
        );
        VFX_ASSERT_AT(".\\DrawLayer\\DrawLayerManager.cpp", 65, false);
    }
    
    const void* descriptor = interface_view->func_00A5E0D0(static_cast<u8>(index));
    const void* value = interface_view->func_00A5E100(static_cast<u8>(index));
    entry->func_00BE8730(-1, descriptor, value);
    entry->unk_06 = true;
}

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD52A0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD52C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD52E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD53D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD54B0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5530.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5550.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD55F0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5600.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD56D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5760.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD57C0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5800.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5870.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD58A0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD58D0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5930.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD59E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5A00.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5AA0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5AE0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5B40.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5B80.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5BB0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5C00.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5C30.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5C60.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5C90.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5CA0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5CE0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5D10.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5D40.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD5E90.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD61E0.s");

INCLUDE_ASM("asm/nonmatchings/Engine/Vfx/Qix/DrawLayer/DrawLayerManager/00BD6290.s");

} // namespace DrawLayer
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX
