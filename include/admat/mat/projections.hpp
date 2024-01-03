#pragma once

#include "admat/mat/mat.hpp"
#include "admat/vec.hpp"
#include <adizzle/assert.hpp>
#include <cmath>
#include <numbers>

namespace admat {

// Not eligible for constexpr due to sqrt in func dependency
auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4;

// windows.h includes files that define 'near' and 'far' as macros, which causes this function to error
// at compile time with difficult to understand error messages.
#pragma push_macro("near")
#pragma push_macro("far")
#undef near
#undef far

constexpr auto perspective(float fov, float aspect, float near, float far) -> mat4 {
    ADIZZLE_ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ADIZZLE_ASSERT(near > 0.0f, "Near plane distance less than zero.");
    ADIZZLE_ASSERT(far > near, "Far plane distance less than zero.");
    ADIZZLE_ASSERT(far > 0.0f, "Far plane distance less than near plane.");

    float y_scale = 1.0f / std::tan(fov * 0.5f);
    float x_scale = y_scale / aspect;

    auto mat = mat4{};

    mat(0, 0) = x_scale;
    mat(1, 1) = y_scale;
    mat(2, 2) = far / (near - far);
    mat(2, 3) = -1.0f;
    mat(3, 2) = near * far / (near - far);

    return mat;
}

constexpr auto orthographic(float width, float height, float near, float far) -> mat4 {
    float range = 1.0f / (near - far);

    auto mat = mat4{};

    mat(0, 0) = 2.0f / width;
    mat(1, 1) = 2.0f / height;
    mat(2, 2) = range;
    mat(3, 2) = range * near;
    mat(3, 3) = 1.0f;

    return mat;
}

#pragma pop_macro("far")
#pragma pop_macro("near")

} // namespace admat