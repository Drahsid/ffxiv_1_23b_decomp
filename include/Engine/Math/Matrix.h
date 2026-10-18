#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

#include "Engine/Math/Vector.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Math {

class Matrix {
public:
    Matrix() {
    }

    Matrix operator*(const Matrix& other) const;

    Matrix& operator=(const Matrix& other) {
        values[0] = other.values[0];
        values[1] = other.values[1];
        values[2] = other.values[2];
        values[3] = other.values[3];
        return *this;
    }

    Vector values[4];
};

extern "C" Matrix* func_0042FEB0(Matrix* matrix, f32 rotation);
extern "C" Matrix* func_007DF590(Matrix* matrix, const Vector* position, const Vector* target, const Vector* up);
extern "C" Matrix* func_007DF8C0(Matrix* matrix, f32 field_of_view, f32 aspect_ratio, f32 near_distance, f32 far_distance);

} // namespace Math
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
