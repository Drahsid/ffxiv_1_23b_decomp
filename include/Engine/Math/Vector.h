#ifndef ENGINE_MATH_VECTOR_H
#define ENGINE_MATH_VECTOR_H

#include "types.h"
#include <string.h>
#include <xmmintrin.h>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Math {

class Vector {
public:
    Vector() {
    }

    Vector(f32 x, f32 y, f32 z, f32 w) {
        __m128 value = _mm_setr_ps(x, y, z, w);
        memcpy(this, &value, sizeof(*this));
    }

    void Set(f32 x, f32 y, f32 z, f32 w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vector& operator=(const Vector& other) {
        memcpy(this, &other, sizeof(*this));
        return *this;
    }

    Vector operator+(const Vector& other) const {
        __m128 first = _mm_setr_ps(x, y, z, w);
        __m128 second = _mm_setr_ps(other.x, other.y, other.z, other.w);
        __m128 value = _mm_add_ps(first, second);
        Vector result;
        result.x = value.m128_f32[0];
        result.y = value.m128_f32[1];
        result.z = value.m128_f32[2];
        result.w = value.m128_f32[3];
        return result;
    }

    union {
        struct {
            f32 x;
            f32 y;
            f32 z;
            f32 w;
        };
        f32 values[4];
    };
};

} // namespace Math
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
