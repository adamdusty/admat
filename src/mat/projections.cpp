#include "admat/mat/projections.hpp"

#include <cmath>

namespace admat {

auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4 {
    auto look  = normalize(target - position);
    auto right = normalize(cross(look, up));
    auto y     = cross(right, look);

    return mat4{
        {right.x, right.y, right.z, -dot(right, position)},
        {y.x, y.y, y.z, -dot(y, position)},
        {-look.x, -look.y, -look.z, dot(look, position)},
        {0, 0, 0, 1},
    };
}

auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4 {
    ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ASSERT(near_plane > 0.0f, "Near plane distance less than zero.");
    ASSERT(far_plane > near_plane, "Far plane distance less than zero.");
    ASSERT(far_plane > 0.0f, "Far plane distance less than near plane.");

    float focal   = 1.0f / std::tan(fov * 0.5f);
    float x_scale = focal / aspect;

    return mat4{
        {x_scale, 0, 0, 0},
        {0, focal, 0, 0},
        {0, 0, far_plane / (near_plane - far_plane), (far_plane * near_plane) / (near_plane - far_plane)},
        {0, 0, -1, 0},
    };
}

} // namespace admat