#pragma once

#include "admat/matrix/operations.hpp"
#include "admat/matrix/types.hpp"
#include "admat/vector.hpp"
#include <cmath>

namespace admat {

template<typename T>
constexpr auto translate(const column_major_matrix<T, 4, 4>& mat, const vec<T, 3>& translation) -> mat4 {
    auto transformation     = mat4::identity();
    transformation.at(0, 3) = translation.at(0);
    transformation.at(1, 3) = translation.at(1);
    transformation.at(2, 3) = translation.at(2);

    return mat * transformation;
}

template<typename T>
constexpr auto scale(const column_major_matrix<T, 4, 4>& mat, const vec<T, 3>& scale) -> mat4 {
    auto transformation = mat4::identity();
    transformation.at(0, 0) *= scale.at(0);
    transformation.at(1, 1) *= scale.at(1);
    transformation.at(2, 2) *= scale.at(2);

    return mat * transformation;
}

template<typename T>
constexpr auto rotate(const column_major_matrix<T, 4, 4>& mat, const vec<T, 3>& angles) -> mat4 {
    auto rotation_x     = mat4::identity();
    rotation_x.at(1, 1) = std::cos(angles.at(0));
    rotation_x.at(1, 2) = std::sin(angles.at(0));
    rotation_x.at(2, 1) = -std::sin(angles.at(0));
    rotation_x.at(2, 2) = std::cos(angles.at(0));

    auto rotation_y     = mat4::identity();
    rotation_y.at(0, 0) = std::cos(angles.at(1));
    rotation_y.at(0, 2) = -std::sin(angles.at(1));
    rotation_y.at(2, 0) = std::sin(angles.at(1));
    rotation_y.at(2, 2) = std::cos(angles.at(1));

    auto rotation_z     = mat4::identity();
    rotation_z.at(0, 0) = std::cos(angles.at(2));
    rotation_z.at(0, 1) = -std::sin(angles.at(2));
    rotation_z.at(1, 0) = std::sin(angles.at(2));
    rotation_z.at(1, 1) = std::cos(angles.at(2));

    auto rotation = rotation_y * rotation_x;
    rotation      = rotation_z * rotation;
    return mat * rotation;
}

} // namespace admat