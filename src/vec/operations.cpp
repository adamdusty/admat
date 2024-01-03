#include "admat/vec/operations.hpp"

namespace admat {

auto abs(const vec2& vec) -> vec2 {
    return vec2{
        std::abs(vec.x),
        std::abs(vec.y),
    };
}

auto abs(const vec3& vec) -> vec3 {
    return vec3{
        std::abs(vec.x),
        std::abs(vec.y),
        std::abs(vec.z),
    };
}

auto abs(const vec4& vec) -> vec4 {
    return vec4{
        std::abs(vec.w),
        std::abs(vec.x),
        std::abs(vec.y),
        std::abs(vec.z),
    };
}

auto distance(const vec2& lhs, const vec2& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);

    return std::sqrt(x + y);
}

auto distance(const vec3& lhs, const vec3& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return std::sqrt(x + y + z);
}

auto distance(const vec4& lhs, const vec4& rhs) -> float {
    auto w = (rhs.w - lhs.w) * (rhs.w - lhs.w);
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return std::sqrt(w + x + y + z);
}

} // namespace admat