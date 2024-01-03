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

    auto mat = mat4{};

    mat.set_row(0, {x.x, y.x, z.x, 0.0f});
    mat.set_row(1, {x.y, y.y, z.y, 0.0f});
    mat.set_row(2, {x.z, y.z, z.z, 0.0f});
    mat.set_row(3, {dot(x, neg_pos), dot(y, neg_pos), dot(z, neg_pos), 1.0f});

    return mat;
}

auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4 {
    ADIZZLE_ASSERT(fov > 0.0f && fov < static_cast<float>(std::numbers::pi), "Invalid FOV");
    ADIZZLE_ASSERT(near_plane > 0.0f, "Near plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > near_plane, "Far plane distance less than zero.");
    ADIZZLE_ASSERT(far_plane > 0.0f, "Far plane distance less than near plane.");

    float y_scale = 1.0f / std::tan(fov * 0.5f);
    float x_scale = y_scale / aspect;

    auto mat = mat4{};

    mat(0, 0) = x_scale;
    mat(1, 1) = y_scale;
    mat(2, 2) = far_plane / (near_plane - far_plane);
    mat(2, 3) = -1.0f;
    mat(3, 2) = near_plane * far_plane / (near_plane - far_plane);

    return mat;
}
} // namespace admat