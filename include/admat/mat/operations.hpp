#pragma once

#include "admat/mat/arithmetic.hpp"
#include "admat/mat/mat.hpp"
#include "admat/vec/vec.hpp"
#include "admat/export.hpp"

namespace admat {

// // Can't be constexpr due to cmath
ADMAT_EXPORT auto rotation(const vec3& axis, float radians) -> mat4;

constexpr auto determinant(const mat4& mat) -> float {
    float sub_00 = mat(2, 2) * mat(3, 3) - mat(3, 2) * mat(2, 3);
    float sub_01 = mat(2, 1) * mat(3, 3) - mat(3, 1) * mat(2, 3);
    float sub_02 = mat(2, 1) * mat(3, 2) - mat(3, 1) * mat(2, 2);
    float sub_03 = mat(2, 0) * mat(3, 3) - mat(3, 0) * mat(2, 3);
    float sub_04 = mat(2, 0) * mat(3, 2) - mat(3, 0) * mat(2, 2);
    float sub_05 = mat(2, 0) * mat(3, 1) - mat(3, 0) * mat(2, 1);

    auto coeff = vec4{
        +(mat(1, 1) * sub_00 - mat(1, 2) * sub_01 + mat(1, 3) * sub_02),
        -(mat(1, 0) * sub_00 - mat(1, 2) * sub_03 + mat(1, 3) * sub_04),
        +(mat(1, 0) * sub_01 - mat(1, 1) * sub_03 + mat(1, 3) * sub_05),
        -(mat(1, 0) * sub_02 - mat(1, 1) * sub_04 + mat(1, 2) * sub_05),
    };

    return mat(0, 0) * coeff.w + mat(0, 1) * coeff.x + mat(0, 2) * coeff.y + mat(0, 3) * coeff.z;
}

constexpr auto inverse(const mat4& mat) -> mat4 {

    auto A2323 = mat(2, 2) * mat(3, 3) - mat(2, 3) * mat(3, 2);
    auto A1323 = mat(2, 1) * mat(3, 3) - mat(2, 3) * mat(3, 1);
    auto A1223 = mat(2, 1) * mat(3, 2) - mat(2, 2) * mat(3, 1);
    auto A0323 = mat(2, 0) * mat(3, 3) - mat(2, 3) * mat(3, 0);
    auto A0223 = mat(2, 0) * mat(3, 2) - mat(2, 2) * mat(3, 0);
    auto A0123 = mat(2, 0) * mat(3, 1) - mat(2, 1) * mat(3, 0);
    auto A2313 = mat(1, 2) * mat(3, 3) - mat(1, 3) * mat(3, 2);
    auto A1313 = mat(1, 1) * mat(3, 3) - mat(1, 3) * mat(3, 1);
    auto A1213 = mat(1, 1) * mat(3, 2) - mat(1, 2) * mat(3, 1);
    auto A2312 = mat(1, 2) * mat(2, 3) - mat(1, 3) * mat(2, 2);
    auto A1312 = mat(1, 1) * mat(2, 3) - mat(1, 3) * mat(2, 1);
    auto A1212 = mat(1, 1) * mat(2, 2) - mat(1, 2) * mat(2, 1);
    auto A0313 = mat(1, 0) * mat(3, 3) - mat(1, 3) * mat(3, 0);
    auto A0213 = mat(1, 0) * mat(3, 2) - mat(1, 2) * mat(3, 0);
    auto A0312 = mat(1, 0) * mat(2, 3) - mat(1, 3) * mat(2, 0);
    auto A0212 = mat(1, 0) * mat(2, 2) - mat(1, 2) * mat(2, 0);
    auto A0113 = mat(1, 0) * mat(3, 1) - mat(1, 1) * mat(3, 0);
    auto A0112 = mat(1, 0) * mat(2, 1) - mat(1, 1) * mat(2, 0);

    auto det = determinant(mat);
    det      = 1 / det;

    return det * mat4{
                     {
                         (mat(1, 1) * A2323 - mat(1, 2) * A1323 + mat(1, 3) * A1223),
                         -(mat(0, 1) * A2323 - mat(0, 2) * A1323 + mat(0, 3) * A1223),
                         (mat(0, 1) * A2313 - mat(0, 2) * A1313 + mat(0, 3) * A1213),
                         -(mat(0, 1) * A2312 - mat(0, 2) * A1312 + mat(0, 3) * A1212),
                     },
                     {
                         -(mat(1, 0) * A2323 - mat(1, 2) * A0323 + mat(1, 3) * A0223),
                         (mat(0, 0) * A2323 - mat(0, 2) * A0323 + mat(0, 3) * A0223),
                         -(mat(0, 0) * A2313 - mat(0, 2) * A0313 + mat(0, 3) * A0213),
                         (mat(0, 0) * A2312 - mat(0, 2) * A0312 + mat(0, 3) * A0212),
                     },
                     {
                         (mat(1, 0) * A1323 - mat(1, 1) * A0323 + mat(1, 3) * A0123),
                         -(mat(0, 0) * A1323 - mat(0, 1) * A0323 + mat(0, 3) * A0123),
                         (mat(0, 0) * A1313 - mat(0, 1) * A0313 + mat(0, 3) * A0113),
                         -(mat(0, 0) * A1312 - mat(0, 1) * A0312 + mat(0, 3) * A0112),
                     },
                     {
                         -(mat(1, 0) * A1223 - mat(1, 1) * A0223 + mat(1, 2) * A0123),
                         (mat(0, 0) * A1223 - mat(0, 1) * A0223 + mat(0, 2) * A0123),
                         -(mat(0, 0) * A1213 - mat(0, 1) * A0213 + mat(0, 2) * A0113),
                         (mat(0, 0) * A1212 - mat(0, 1) * A0212 + mat(0, 2) * A0112),
                     },
                 };
}

constexpr auto transpose(const mat4& mat) -> mat4 {
    return mat4{
        {mat.w},
        {mat.x},
        {mat.y},
        {mat.z},
    };
}

constexpr auto translation(float x, float y, float z) -> mat4 {
    return mat4{
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1},
    };
}

constexpr auto translation(const vec3& translation) -> mat4 {
    return admat::translation(translation.x, translation.y, translation.z);
}

constexpr auto scaling(float x, float y, float z) -> mat4 {
    return mat4{
        {x, 0, 0, 0},
        {0, y, 0, 0},
        {0, 0, z, 0},
        {0, 0, 0, 1},
    };
}

constexpr auto scaling(const vec3& scale) -> mat4 {
    return scaling(scale.x, scale.y, scale.z);
}

} // namespace admat
