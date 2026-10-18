#ifndef ENGINE_DW_RENDER_INTERFACE_SAMPLER_H
#define ENGINE_DW_RENDER_INTERFACE_SAMPLER_H

#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Dw {
namespace RenderInterface {

class TextureFilter {
public:
    enum {
        None = 0,
        Point = 1,
        Linear = 2
    };

    TextureFilter(u32 arg0) : value(arg0) {
    }

    TextureFilter(const TextureFilter& arg0) : value(arg0.value) {
    }

    u32 value;
};

class TextureAddressMode {
public:
    enum {
        Clamp = 2
    };

    TextureAddressMode(u32 arg0) : value(arg0) {
    }

    TextureAddressMode(const TextureAddressMode& arg0) : value(arg0.value) {
    }

    u32 value;
};

class TextureCoordinateMask {
public:
    TextureCoordinateMask(u32 arg0) : value(arg0) {
    }

    TextureCoordinateMask(const TextureCoordinateMask& arg0) : value(arg0.value) {
    }

    u32 value;
};

extern "C" void func_00418300(
    s32 index,
    TextureAddressMode address_u,
    TextureAddressMode address_v,
    TextureAddressMode address_w,
    TextureCoordinateMask coordinate_mask
);
extern "C" void func_00418380(s32 index, u32 arg1, u32 arg2, bool arg3);
extern "C" void func_004183C0(s32 index, TextureFilter min_filter, TextureFilter mag_filter, TextureFilter mip_filter, s8 lod_bias);
extern "C" void func_00418410(s32 index, void* texture);

} // namespace RenderInterface
} // namespace Dw
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
