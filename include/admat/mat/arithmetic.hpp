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
    return mat4::from_cols({lhs.w * rhs.w.w + lhs.x * rhs.w.x + lhs.y * rhs.w.y + lhs.z * rhs.w.z},
                           {lhs.w * rhs.x.w + lhs.x * rhs.x.x + lhs.y * rhs.x.y + lhs.z * rhs.x.z},
                           {lhs.w * rhs.y.w + lhs.x * rhs.y.x + lhs.y * rhs.y.y + lhs.z * rhs.y.z},
                           {lhs.w * rhs.z.w + lhs.x * rhs.z.x + lhs.y * rhs.z.y + lhs.z * rhs.z.z});
}

constexpr auto operator*(const mat4& lhs, float scalar) -> mat4 {
    return mat4::from_cols(lhs.w * scalar, lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
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