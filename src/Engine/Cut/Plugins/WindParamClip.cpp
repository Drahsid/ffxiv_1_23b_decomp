#include "Engine/Cut/Plugins/WindParamClip.h"
#include "Engine/Lay/Stella/Layout/IWindBaseObject.h"
#include "Engine/Common/Log.h"
#include "Engine/Cut/Scheduler/ClipParameter.h"
#include "Engine/Dw/Renderer/DrawEnv.h"
#include "Engine/Lay/Default/External/Dw/DrawEnv/LayoutDrawEnvObject.h"
#include "asm.h"
#include <string.h>

extern "C" void* D_013657B4;

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

void WindParamClip::SetWindParameter(Lay::Default::External::Dw::DrawEnv::LayoutDrawEnvObject* arg0, Lay::Stella::Layout::IWindBaseObject* arg1) {
    Dw::Renderer::DrawEnv* pEnv = arg0->func_00C4BAE0();
    LOG_ASSERT_AT(".\\WindParamClip.cpp", 121, pEnv, "");
    arg1->func_008D5430();
    u32 count = arg0->func_00A815F0();
    for (u32 index = 0; index < count; ++index) {
        Lay::Stella::Layout::WindParameterArgument argument = {arg0, arg0->func_00A81790(index).value};
        arg1->func_00AB56F0(&argument);
    }
}

void WindParamClip::Leap(Lay::Stella::Layout::IWindBaseObject* to, Lay::Stella::Layout::IWindBaseObject* from, f32 k) {
    LOG_ASSERT_AT(".\\WindParamClip.cpp", 150, to, "");
    LOG_ASSERT_AT(".\\WindParamClip.cpp", 151, from, "");

    if (!(0.f <= k) || k > 1.f) {
        Get_Assert_Callback(Default_Assert_Handler)("0.f <= k && k <= 1.f", "", ".\\WindParamClip.cpp", 152, __FUNCTION__);
    }

    Lay::Stella::Layout::IWindBaseObject* object = k < 0.5f ? from : to;
    DrawEnvSet::iterator iterator;
    for (iterator = drawEnvironments.begin(); iterator != drawEnvironments.end(); ++iterator) {
        SetWindParameter(*iterator, object);
    }
}

INCLUDE_ASM("asm/nonmatchings/Engine/Cut/Plugins/WindParamClip/00DF7FB0.s");

void WindParamClip::func_00A20F90(Scheduler::ClipParameter* parameter) {
    if (!windEntries.empty() && func_00DF9EB0()) {
        Init();
        Scheduler::ClipBase::func_00A20F90(parameter);
        f32 frame_interval = static_cast<f32>(parameter->func_00A1FFC0());
        f32 time = static_cast<f32>(static_cast<s32>(func_00A210A0()));
        s32 frame = static_cast<s32>(time / frame_interval + 0.5);

        if (func_00A210A0() == Get_Clip_Data()->unk_14) {
            frame = 0;
        }

        s32 previous_frame = frame;
        WindMap::iterator previous;
        while ((previous = windEntries.find(previous_frame)) == windEntries.end()) {
            --previous_frame;
        }

        s32 next_frame = previous_frame + 1;
        WindMap::iterator next;
        while ((next = windEntries.find(next_frame)) == windEntries.end()) {
            ++next_frame;
        }
        
        f32 k = static_cast<f32>(frame - previous_frame) / static_cast<f32>(next_frame - previous_frame);
        Leap(next->second.object, previous->second.object, k);
    }
}

void WindParamClip::OnEnter(Scheduler::ClipParameter* parameter) {
    Scheduler::ClipBase::OnEnter(parameter);
    WindMap::iterator first = windEntries.begin();
    WindMap::reverse_iterator last = windEntries.rbegin();
    f32 first_value = static_cast<f32>(static_cast<s32>(func_00A21080()));
    f32 second_value = static_cast<f32>(parameter->func_00A1FFC0());
    s32 offset = static_cast<s32>(first_value / second_value + 0.5);
    windEntries[first->first + offset] = first->second;
    windEntries[last->first - offset] = last->second;
}

WindParamClip::~WindParamClip() {
    DrawEnvSet::iterator iterator;
    for (iterator = drawEnvironments.begin(); iterator != drawEnvironments.end(); ++iterator) {
        Dw::Renderer::DrawEnv* environment = (*iterator)->func_00C4BAE0();
        *environment->func_00C1F3E0() = savedWindParameter;
    }
}

WindParamClip::WindParamClip(const Scheduler::ClipData* data, void* arg1)
    : Scheduler::BaseClipImpl<WINDPARAM_CLIP_DATA>(data, arg1), unk_38(D_013657B4), savedWindParameter(true), initialized(false) {
    const char* position = reinterpret_cast<const char*>(Get_Clip_Data()) + sizeof(WINDPARAM_CLIP_DATA);
    drawEnvironmentName = position;
    position += strnlen(position, 64) + 1;
    s32 entry_count = *reinterpret_cast<const s32*>(position);
    position += sizeof(s32);
    for (s32 index = 0; index < entry_count; ++index) {
        const char* name = position + sizeof(s32);
        s32 key = *reinterpret_cast<const s32*>(position);
        WindEntry entry = {name, 0};
        windEntries[key] = entry;
        position = name + strlen(name) + 1;
    }
}

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX
