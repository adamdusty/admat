#include "admat/mat/projections.hpp"

#include <adizzle/assert.hpp>
#include <cmath>
#include <numbers>

namespace admat {

auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4 {
    auto direction = target - position;

    auto look    = normalize(-direction);
    auto right   = normalize(cross(up, look));
    auto y       = cross(look, right);
    auto neg_pos = -position;

    return mat4{
        {right.x, y.x, look.x, 0.0f},
        {right.y, y.y, look.y, 0.0f},
        {right.z, y.z, look.z, 0.0f},
        {dot(right, neg_pos), dot(y, neg_pos), dot(look, neg_pos), 1.0f},
    };
}

auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4 {
    ADIZZLE_ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ADIZZLE_ASSERT(near_plane > 0.0f, "Near plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > near_plane, "Far plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > 0.0f, "Far plane distance less than near plane.");

    float focal   = 1.0f / std::tan(fov * 0.5f);
    float x_scale = focal / aspect;

    return mat4{
        {x_scale, 0, 0, 0},
        {0, -focal, 0, 0},
        {0, 0, near_plane / (far_plane - near_plane), (near_plane * far_plane) / (far_plane - near_plane)},
        {0, 0, -1, 0},
    };
}

} // namespace admat