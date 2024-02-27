#pragma once

#include "admat/vec/vec.hpp"
#include "admat/export.hpp"

#include <algorithm>
#include <cmath>

namespace admat {

// can't be constexpr due to non-constexpr cmath functions
ADMAT_EXPORT auto abs(const vec2& vec) -> vec2;
ADMAT_EXPORT auto abs(const vec3& vec) -> vec3;
ADMAT_EXPORT auto abs(const vec4& vec) -> vec4;
ADMAT_EXPORT auto distance(const vec2& lhs, const vec2& rhs) -> float;
ADMAT_EXPORT auto distance(const vec3& lhs, const vec3& rhs) -> float;
ADMAT_EXPORT auto distance(const vec4& lhs, const vec4& rhs) -> float;

constexpr auto dot(const vec2& lhs, const vec2& rhs) -> float {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

constexpr auto dot(const vec3& lhs, const vec3& rhs) -> float {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

constexpr auto dot(const vec4& lhs, const vec4& rhs) -> float {
    return (lhs.w * rhs.w) + (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

constexpr auto cross(const vec3& lhs, const vec3& rhs) -> vec3 {
    return vec3{
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x,
    };
}

constexpr auto clamp(const vec2& vec, float min, float max) -> vec2 {
    return vec2{
        std::clamp(vec.x, min, max),
        std::clamp(vec.y, min, max),
    };
}

constexpr auto clamp(const vec3& vec, float min, float max) -> vec3 {
    return vec3{
        std::clamp(vec.x, min, max),
        std::clamp(vec.y, min, max),
        std::clamp(vec.z, min, max),
    };
}

constexpr auto clamp(const vec4& vec, float min, float max) -> vec4 {
    return vec4{
        std::clamp(vec.w, min, max),
        std::clamp(vec.x, min, max),
        std::clamp(vec.y, min, max),
        std::clamp(vec.z, min, max),
    };
}

constexpr auto lerp(const vec2& from, const vec2& to, float delta) -> vec2 {
    return vec2{
        std::lerp(from.x, to.x, delta),
        std::lerp(from.y, to.y, delta),
    };
}

constexpr auto lerp(const vec3& from, const vec3& to, float delta) -> vec3 {
    return vec3{
        std::lerp(from.x, to.x, delta),
        std::lerp(from.y, to.y, delta),
        std::lerp(from.z, to.z, delta),
    };
}

constexpr auto lerp(const vec4& from, const vec4& to, float delta) -> vec4 {
    return vec4{
        std::lerp(from.w, to.w, delta),
        std::lerp(from.x, to.x, delta),
        std::lerp(from.y, to.y, delta),
        std::lerp(from.z, to.z, delta),
    };
}

template<typename T>
constexpr auto reflect(const T& incident, const T& normal) -> T {
    return incident - (normal * 2.0 * dot(normal, incident));
}

template<typename T>
auto magnitude(const T& vec) -> float {
    return std::sqrt(dot(vec, vec));
}

template<typename T>
auto normalize(const T& vec) -> T {
    return vec / magnitude(vec);
}

template<typename T>
auto refract(const T& incident, const T& normal, float ratio) -> T {
    auto constant = 1.0f - (ratio * ratio) * (1.0f - (dot(normal, incident) * dot(normal, incident)));
    if(constant < 0.0f) {
        return T{};
    }

    return (incident * ratio) - (ratio * dot(normal, incident) + std::sqrt(constant)) * normal;
}

} // namespace admat