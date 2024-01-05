#pragma once

#include "admat/mat/mat.hpp"
#include "admat/vec.hpp"

namespace admat {

// Not eligible for constexpr due to sqrt in func dependency
auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4;
auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4;

constexpr auto orthographic(float width, float height, float near_plane, float far_plane) -> mat4 {
    float range = 1.0f / (near_plane - far_plane);

    return mat4{
        {2.0f / width, 0, 0, 0},
        {0, 2.0f / height, 0, 0},
        {0, 0, range, 0},
        {0, 0, range * near_plane, 1},
    };
}

} // namespace admat