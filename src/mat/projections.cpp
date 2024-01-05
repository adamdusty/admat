#include "admat/mat/projections.hpp"

#include <adizzle/assert.hpp>
#include <cmath>
#include <numbers>

namespace admat {

auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4 {
    auto direction = target - position;

    auto z       = normalize(-direction);
    auto x       = normalize(cross(up, z));
    auto y       = cross(z, x);
    auto neg_pos = -position;

    return mat4{
        {x.x, y.x, z.x, 0.0f},
        {x.y, y.y, z.y, 0.0f},
        {x.z, y.z, z.z, 0.0f},
        {dot(x, neg_pos), dot(y, neg_pos), dot(z, neg_pos), 1.0f},
    };
}

auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4 {
    ADIZZLE_ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ADIZZLE_ASSERT(near_plane > 0.0f, "Near plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > near_plane, "Far plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > 0.0f, "Far plane distance less than near plane.");

    float y_scale = 1.0f / std::tan(fov * 0.5f);
    float x_scale = y_scale / aspect;

    return mat4{
        {x_scale, 0, 0, 0},
        {0, y_scale, 0, 0},
        {0, 0, far_plane / (near_plane - far_plane), -1},
        {0, 0, (far_plane * near_plane) / (near_plane - far_plane), 0},
    };
}

} // namespace admat