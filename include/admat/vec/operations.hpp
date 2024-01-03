#pragma once

#include "admat/vec/vec.hpp"
#include <adizzle/math.hpp>

#include <cmath>

namespace admat {

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

constexpr auto abs(const vec2& vec) -> vec2 {
    return vec2{
        adizzle::abs(vec.x),
        adizzle::abs(vec.y),
    };
}

constexpr auto abs(const vec3& vec) -> vec3 {
    return vec3{
        adizzle::abs(vec.x),
        adizzle::abs(vec.y),
        adizzle::abs(vec.z),
    };
}

constexpr auto abs(const vec4& vec) -> vec4 {
    return vec4{
        adizzle::abs(vec.w),
        adizzle::abs(vec.x),
        adizzle::abs(vec.y),
        adizzle::abs(vec.z),
    };
}

constexpr auto clamp(const vec2& vec, float min, float max) -> vec2 {
    return vec2{
        std::min(std::max(vec.x, min), max),
        std::min(std::max(vec.y, min), max),
    };
}

constexpr auto clamp(const vec3& vec, float min, float max) -> vec3 {
    return vec3{
        std::min(std::max(vec.x, min), max),
        std::min(std::max(vec.y, min), max),
        std::min(std::max(vec.z, min), max),
    };
}

constexpr auto clamp(const vec4& vec, float min, float max) -> vec4 {
    return vec4{
        std::min(std::max(vec.w, min), max),
        std::min(std::max(vec.x, min), max),
        std::min(std::max(vec.y, min), max),
        std::min(std::max(vec.z, min), max),
    };
}

constexpr auto distance(const vec2& lhs, const vec2& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);

    return adizzle::sqrt(x + y);
}

constexpr auto distance(const vec3& lhs, const vec3& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return adizzle::sqrt(x + y + z);
}

constexpr auto distance(const vec4& lhs, const vec4& rhs) -> float {
    auto w = (rhs.w - lhs.w) * (rhs.w - lhs.w);
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return adizzle::sqrt(w + x + y + z);
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
constexpr auto magnitude(const T& vec) -> float {
    return adizzle::sqrt(dot(vec, vec));
}

template<typename T>
constexpr auto normalize(const T& vec) -> T {
    return vec / magnitude(vec);
}

template<typename T>
constexpr auto reflect(const T& incident, const T& normal) -> T {
    return incident - (normal * 2.0 * dot(normal, incident));
}

template<typename T>
constexpr auto refract(const T& incident, const T& normal, float ratio) -> T {
    auto constant = 1.0f - (ratio * ratio) * (1.0f - (dot(normal, incident) * dot(normal, incident)));
    if(constant < 0.0f) {
        return T{};
    }

    return (incident * ratio) - (ratio * dot(normal, incident) + adizzle::sqrt(constant)) * normal;
}

} // namespace admat