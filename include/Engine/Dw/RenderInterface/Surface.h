#ifndef ENGINE_DW_RENDERINTERFACE_SURFACE_H
#define ENGINE_DW_RENDERINTERFACE_SURFACE_H

#include "Engine/Dw/DwMemoryObject.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {

namespace MultiSample {
enum Type {
    NumberOf = 16
};
} // namespace MultiSample

struct SurfaceDescription {
    u32 unk_00;
    u32 unk_04;
    u32 width;
    u32 height;
    u32 unk_10;
    u32 format;
    MultiSample::Type multiSample;
};

namespace D3d9 {
class ManagedResource {
public:
    virtual ~ManagedResource();
    void* unk_04;
    void* unk_08;
};

class SurfaceImp : protected ManagedResource {
public:
    SurfaceDescription description;
    void* unk_28;
    void* unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
};
} // namespace D3d9

namespace Detail {
template<class T, class M>
class Surface : public T, public M {
};
} // namespace Detail

class Surface : public Detail::Surface<D3d9::SurfaceImp, DwMemoryObject> {
};

} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
