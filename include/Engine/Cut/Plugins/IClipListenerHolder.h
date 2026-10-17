#ifndef ENGINE_CUT_PLUGINS_I_CLIP_LISTENER_HOLDER_H
#define ENGINE_CUT_PLUGINS_I_CLIP_LISTENER_HOLDER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Cut {
namespace Plugins {

class ICutResourceListener;

class IClipListenerHolder {
public:
    virtual void* func_008D5570() = 0;
    virtual void* func_007143E0() = 0;
    virtual void* func_00CB1C80() = 0;
    virtual void* func_00A29AA0() = 0;
    virtual void* func_00C4BAE0() = 0;
    virtual void* func_00410780() = 0;
    virtual void* func_0060DE70() = 0;
    virtual void* func_00A87F40() = 0;
    virtual void* func_007CC7E0() = 0;
    virtual void* func_00B36630() = 0;
    virtual void* func_00BBEC30() = 0;
    virtual void* func_00657330() = 0;
    virtual ICutResourceListener* func_00657340() = 0;
    virtual ~IClipListenerHolder();
};

} // namespace Plugins
} // namespace Cut
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
