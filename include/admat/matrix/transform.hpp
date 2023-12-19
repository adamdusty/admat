#pragma once

#include "admat/matrix/operations.hpp"
#include "admat/matrix/types.hpp"
#include <adizzle/assert.hpp>
#include <cmath>
#include <numbers>

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

constexpr auto perspective(float fov, float aspect, float near, float far) -> mat4 {
    ADIZZLE_ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ADIZZLE_ASSERT(near > 0.0f, "Near plane distance less than zero.");
    ADIZZLE_ASSERT(far > near, "Far plane distance less than zero.");
    ADIZZLE_ASSERT(far > 0.0f, "Far plane distance less than near plane.");

    float y_scale = 1.0f / std::tan(fov * 0.5f);
    float x_scale = y_scale / aspect;

    auto mat = mat4{};

    mat.at(0, 0) = x_scale;
    mat.at(1, 1) = y_scale;
    mat.at(2, 2) = far / (near - far);
    mat.at(2, 3) = -1.0f;
    mat.at(3, 2) = near * far / (near - far);

    return mat;
}

constexpr auto orthographic(float width, float height, float near, float far) -> mat4 {
    float range = 1.0f / (near - far);

    auto mat = mat4{};

    mat.at(0, 0) = 2.0f / width;
    mat.at(1, 1) = 2.0f / height;
    mat.at(2, 2) = range;
    mat.at(3, 2) = range * near;
    mat.at(3, 3) = 1.0f;

    return mat;
}

} // namespace admat