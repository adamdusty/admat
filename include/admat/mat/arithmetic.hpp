#pragma once

#include "admat/mat/mat.hpp"
#include "admat/vec.hpp"
#include <algorithm>
#include <ranges>

namespace rg = std::ranges;

namespace admat {

constexpr auto operator+(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto result = std::array<float, 16>{};

    rg::transform(lhs.get(), rhs.get(), result.begin(), std::plus{});

    return mat4{result};
}

constexpr auto operator-(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto result = std::array<float, 16>{};

    rg::transform(lhs.get(), rhs.get(), result.begin(), std::minus{});

    return mat4{result};
}

constexpr auto operator*(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto m0 = vec4::from_array(lhs.col(0));
    auto m1 = vec4::from_array(lhs.col(1));
    auto m2 = vec4::from_array(lhs.col(2));
    auto m3 = vec4::from_array(lhs.col(3));

    auto n0 = vec4::from_array(rhs.col(0));
    auto n1 = vec4::from_array(rhs.col(1));
    auto n2 = vec4::from_array(rhs.col(2));
    auto n3 = vec4::from_array(rhs.col(3));

    auto r0 = (m0 * n0.w + m1 * n0.x + m2 * n0.y + m3 * n0.z);
    auto r1 = (m0 * n1.w + m1 * n1.x + m2 * n1.y + m3 * n1.z);
    auto r2 = (m0 * n2.w + m1 * n2.x + m2 * n2.y + m3 * n2.z);
    auto r3 = (m0 * n3.w + m1 * n3.x + m2 * n3.y + m3 * n3.z);

    auto result = mat4{};

    result.set_col(0, r0);
    result.set_col(1, r1);
    result.set_col(2, r2);
    result.set_col(3, r3);

    return result;
}

constexpr auto operator*(const mat4& lhs, float scalar) -> mat4 {
    auto result = std::array<float, 16>{};

    rg::transform(lhs.get(), result.begin(), [scalar](const auto x) { return x * scalar; });

    return mat4{result};
}

constexpr auto operator*(float scalar, mat4 rhs) -> mat4 {
    return rhs * scalar;
}

constexpr auto operator*(const mat4& mat, const vec4& vec) -> vec4 {
    return vec4{
        .w = mat(0, 0) * vec.w + mat(0, 1) * vec.x + mat(0, 2) * vec.y + mat(0, 3) * vec.z,
        .x = mat(1, 0) * vec.w + mat(1, 1) * vec.x + mat(1, 2) * vec.y + mat(1, 3) * vec.z,
        .y = mat(2, 0) * vec.w + mat(2, 1) * vec.x + mat(2, 2) * vec.y + mat(2, 3) * vec.z,
        .z = mat(3, 0) * vec.w + mat(3, 1) * vec.x + mat(3, 2) * vec.y + mat(3, 3) * vec.z,
    };
}

constexpr auto operator*(const vec4& vec, const mat4& mat) -> vec4 {
    return mat * vec;
}

} // namespace admat