#include "admat/mat/operations.hpp"

#include <cmath>

namespace admat {

auto rotation(const vec3& axis, float radians) -> mat4 {
    auto ax  = normalize(axis);
    auto sin = std::sin(radians);
    auto cos = std::cos(radians);

    return mat4{
        {cos + (ax.x * ax.x) * (1 - cos),
         ax.x * ax.y * (1 - cos) - (ax.z * sin),
         ax.x * ax.z * (1 - cos) + (ax.y * sin),
         0.0f},
        {ax.y * ax.x * (1 - cos) + (ax.z * sin),
         cos + (ax.y * ax.y) * (1 - cos),
         ax.y * ax.z * (1 - cos) - (ax.x * sin),
         0.0f},
        {ax.z * ax.x * (1 - cos) - (ax.y * sin),
         ax.z * ax.y * (1 - cos) + (ax.x * sin),
         cos + (ax.z * ax.z) * (1 - cos),
         0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f},
    };
}

} // namespace admat