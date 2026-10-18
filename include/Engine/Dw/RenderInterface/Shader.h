#ifndef ENGINE_DW_RENDERINTERFACE_SHADER_H
#define ENGINE_DW_RENDERINTERFACE_SHADER_H

#include "types.h"

struct IDirect3DPixelShader9;

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
class DwMemoryObject;

namespace RenderInterface {

namespace D3d9 {
template<class T>
class ShaderImp;
} // namespace D3d9

namespace Detail {
struct ShaderParameterEntry {
    u32 hash;
    u32 registerIndex;
};

class ShaderParameterTable {
public:
    u32 func_00420900(u32 arg0, const char* name);

    u32 Get_Register_Index(u32 handle) {
        if (handle <= 0) {
            return 0xFFFF;
        }
        return unk_00[handle - 1].registerIndex;
    }

    ShaderParameterEntry* unk_00;
    u32 unk_04;
};

template<class T, class M>
class Shader {
public:
    void SetFloatArray(u32 handle, const f32* values, u32 count);
};
} // namespace Detail

typedef Detail::Shader<D3d9::ShaderImp<IDirect3DPixelShader9>, DwMemoryObject> PixelShaderInterface;

class PixelShader {
public:
    u32 Get_Parameter_Handle(const char* name) {
        return parameters.func_00420900(0, name);
    }

    u32 Get_Parameter_Register(u32 handle) {
        return parameters.Get_Register_Index(handle);
    }

    u32 unk_00;
    u32 unk_04;
    Detail::ShaderParameterTable parameters;
};

class VertexShader {
public:
    u32 unk_00;
    u32 unk_04;
    Detail::ShaderParameterTable parameters;
};

extern "C" bool func_00C23A80(u32 handle, const f32* values, u32 count);

} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

extern "C" SQEX::CDev::Engine::Dw::RenderInterface::PixelShaderInterface* D_01374E50;

#endif
