#include "admat/mat/projections.hpp"

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
} // namespace admat