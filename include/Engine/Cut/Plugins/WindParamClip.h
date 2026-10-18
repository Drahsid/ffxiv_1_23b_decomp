#ifndef ENGINE_CUT_PLUGINS_WIND_PARAM_CLIP_H
#define ENGINE_CUT_PLUGINS_WIND_PARAM_CLIP_H

#include "Engine/Common/cdev_allocator.h"
#include "Engine/Cut/Scheduler/BaseClipImpl.h"
#include "Engine/Dw/Renderer/WindParameter.h"
#include <map>
#include <set>

namespace SQEX {
namespace CDev {
namespace Engine {

namespace Lay {

namespace Stella {
namespace Layout {
class IWindBaseObject;
} // namespace Layout
} // namespace Stella

namespace Default {
namespace External {
namespace Dw {
namespace DrawEnv {
class LayoutDrawEnvObject;
} // namespace DrawEnv
} // namespace Dw
} // namespace External
} // namespace Default
} // namespace Lay

namespace Cut {
namespace Plugins {

struct WINDPARAM_CLIP_DATA : Scheduler::ClipData {
    u32 unk_10;
    u32 unk_14;
};

class WindParamClip : public Scheduler::BaseClipImpl<WINDPARAM_CLIP_DATA> {
public:
    WindParamClip(const Scheduler::ClipData* data, void* arg1);
    virtual ~WindParamClip();
    virtual void OnEnter(Scheduler::ClipParameter* parameter);
    virtual void func_00A20F90(Scheduler::ClipParameter* parameter);
    virtual void func_00A21000(u32 arg0);
    virtual void func_00A21010(u32 arg0);
    virtual u32 func_00A21080();
    void Init();
    void SetWindParameter(Lay::Default::External::Dw::DrawEnv::LayoutDrawEnvObject* arg0, Lay::Stella::Layout::IWindBaseObject* arg1);
    void Leap(Lay::Stella::Layout::IWindBaseObject* to, Lay::Stella::Layout::IWindBaseObject* from, f32 k);
    void func_00DF9E80();
    bool func_00DF9EB0();
    void SaveWindParameter();
    Lay::Stella::Layout::IWindBaseObject* GetWindBaseObject(const char* name);

private:
    void* unk_38;
    const char* drawEnvironmentName;
    typedef Lay::Default::External::Dw::DrawEnv::LayoutDrawEnvObject DrawEnvObject;
    typedef std::set<DrawEnvObject*, std::less<DrawEnvObject*>, CDev_Allocator<DrawEnvObject*> > DrawEnvSet;
    DrawEnvSet drawEnvironments;
    u32 unk_4C;
    Dw::Renderer::WindParameter savedWindParameter;
    struct WindEntry {
        const char* name;
        Lay::Stella::Layout::IWindBaseObject* object;
    };
    typedef std::map<s32, WindEntry, std::less<s32>, CDev_Allocator<std::pair<const s32, WindEntry> > > WindMap;
    WindMap windEntries;
    u32 unk_8C;
    bool initialized;
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
