#pragma once

#include "admat/mat/mat.hpp"
#include "admat/vec.hpp"
#include <algorithm>
#include <ranges>

// namespace rg = std::ranges;

namespace admat {

constexpr auto operator+(const mat4& lhs, const mat4& rhs) -> mat4 {
    return mat4{
        lhs.w + rhs.w,
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
    };
}

constexpr auto operator-(const mat4& lhs, const mat4& rhs) -> mat4 {
    return mat4{
        lhs.w - rhs.w,
        lhs.x - rhs.x,
        lhs.y - rhs.y,
        lhs.z - rhs.z,
    };
}

constexpr auto operator*(const mat4& lhs, const mat4& rhs) -> mat4 {
    return mat4{
        {rhs.w * lhs.w.w + rhs.x * lhs.w.x + rhs.y * lhs.w.y + rhs.z * lhs.w.z},
        {rhs.w * lhs.x.w + rhs.x * lhs.x.x + rhs.y * lhs.x.y + rhs.z * lhs.x.z},
        {rhs.w * lhs.y.w + rhs.x * lhs.y.x + rhs.y * lhs.y.y + rhs.z * lhs.y.z},
        {rhs.w * lhs.z.w + rhs.x * lhs.z.x + rhs.y * lhs.z.y + rhs.z * lhs.z.z},
    };
}

constexpr auto operator*(const mat4& lhs, float scalar) -> mat4 {
    return mat4{
        lhs.w * scalar,
        lhs.x * scalar,
        lhs.y * scalar,
        lhs.z * scalar,
    };
}

constexpr auto operator*(float scalar, mat4 rhs) -> mat4 {
    return rhs * scalar;
}

constexpr auto operator*(const mat4& mat, const vec4& vec) -> vec4 {
    return vec4{
        dot(mat.w, vec),
        dot(mat.x, vec),
        dot(mat.y, vec),
        dot(mat.z, vec),
    };
}

constexpr auto operator*(const vec4& vec, const mat4& mat) -> vec4 {
    return mat * vec;
}

} // namespace admat