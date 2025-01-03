#pragma once

#include "admat/vec.hpp"

#include <cassert>
#include <cstddef>

namespace admat {

struct mat4 {
    vec4 w;
    vec4 x;
    vec4 y;
    vec4 z;

    constexpr mat4() = default;
    constexpr mat4(const vec4& r1, const vec4& r2, const vec4& r3, const vec4& r4) : w{}, x{}, y{}, z{} {
        w = {r1.w, r2.w, r3.w, r4.w};
        x = {r1.x, r2.x, r3.x, r4.x};
        y = {r1.y, r2.y, r3.y, r4.y};
        z = {r1.z, r2.z, r3.z, r4.z};
    }

    constexpr auto operator[](std::size_t row, std::size_t col) const -> float {
        assert(row < 4 && col < 4);

        std::size_t index = col * 4 + row;
        return *(&(w.w) + index); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    }

    static constexpr auto from_cols(const vec4& c1, const vec4& c2, const vec4& c3, const vec4& c4) -> mat4 {
        return mat4{
            {c1.w, c2.w, c3.w, c4.w},
            {c1.x, c2.x, c3.x, c4.x},
            {c1.y, c2.y, c3.y, c4.y},
            {c1.z, c2.z, c3.z, c4.z},
        };
    }

    static consteval auto identity() -> mat4 {
        return mat4{
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        };
    }
};

static_assert(std::is_standard_layout_v<mat4> && std::is_trivial_v<mat4>, "mat4 not pod");

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

constexpr auto rotation(const vec3& axis, float radians) -> mat4 {
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

constexpr auto determinant(const mat4& mat) -> float {
    float sub_00 = mat[2, 2] * mat[3, 3] - mat[3, 2] * mat[2, 3];
    float sub_01 = mat[2, 1] * mat[3, 3] - mat[3, 1] * mat[2, 3];
    float sub_02 = mat[2, 1] * mat[3, 2] - mat[3, 1] * mat[2, 2];
    float sub_03 = mat[2, 0] * mat[3, 3] - mat[3, 0] * mat[2, 3];
    float sub_04 = mat[2, 0] * mat[3, 2] - mat[3, 0] * mat[2, 2];
    float sub_05 = mat[2, 0] * mat[3, 1] - mat[3, 0] * mat[2, 1];

    auto coeff = vec4{
        +(mat[1, 1] * sub_00 - mat[1, 2] * sub_01 + mat[1, 3] * sub_02),
        -(mat[1, 0] * sub_00 - mat[1, 2] * sub_03 + mat[1, 3] * sub_04),
        +(mat[1, 0] * sub_01 - mat[1, 1] * sub_03 + mat[1, 3] * sub_05),
        -(mat[1, 0] * sub_02 - mat[1, 1] * sub_04 + mat[1, 2] * sub_05),
    };

    return mat[0, 0] * coeff.w + mat[0, 1] * coeff.x + mat[0, 2] * coeff.y + mat[0, 3] * coeff.z;
}

constexpr auto inverse(const mat4& mat) -> mat4 {

    auto A2323 = mat[2, 2] * mat[3, 3] - mat[2, 3] * mat[3, 2];
    auto A1323 = mat[2, 1] * mat[3, 3] - mat[2, 3] * mat[3, 1];
    auto A1223 = mat[2, 1] * mat[3, 2] - mat[2, 2] * mat[3, 1];
    auto A0323 = mat[2, 0] * mat[3, 3] - mat[2, 3] * mat[3, 0];
    auto A0223 = mat[2, 0] * mat[3, 2] - mat[2, 2] * mat[3, 0];
    auto A0123 = mat[2, 0] * mat[3, 1] - mat[2, 1] * mat[3, 0];
    auto A2313 = mat[1, 2] * mat[3, 3] - mat[1, 3] * mat[3, 2];
    auto A1313 = mat[1, 1] * mat[3, 3] - mat[1, 3] * mat[3, 1];
    auto A1213 = mat[1, 1] * mat[3, 2] - mat[1, 2] * mat[3, 1];
    auto A2312 = mat[1, 2] * mat[2, 3] - mat[1, 3] * mat[2, 2];
    auto A1312 = mat[1, 1] * mat[2, 3] - mat[1, 3] * mat[2, 1];
    auto A1212 = mat[1, 1] * mat[2, 2] - mat[1, 2] * mat[2, 1];
    auto A0313 = mat[1, 0] * mat[3, 3] - mat[1, 3] * mat[3, 0];
    auto A0213 = mat[1, 0] * mat[3, 2] - mat[1, 2] * mat[3, 0];
    auto A0312 = mat[1, 0] * mat[2, 3] - mat[1, 3] * mat[2, 0];
    auto A0212 = mat[1, 0] * mat[2, 2] - mat[1, 2] * mat[2, 0];
    auto A0113 = mat[1, 0] * mat[3, 1] - mat[1, 1] * mat[3, 0];
    auto A0112 = mat[1, 0] * mat[2, 1] - mat[1, 1] * mat[2, 0];

    auto det = determinant(mat);
    det      = 1 / det;

    return det * mat4{
                     {
                         (mat[1, 1] * A2323 - mat[1, 2] * A1323 + mat[1, 3] * A1223),
                         -(mat[0, 1] * A2323 - mat[0, 2] * A1323 + mat[0, 3] * A1223),
                         (mat[0, 1] * A2313 - mat[0, 2] * A1313 + mat[0, 3] * A1213),
                         -(mat[0, 1] * A2312 - mat[0, 2] * A1312 + mat[0, 3] * A1212),
                     },
                     {
                         -(mat[1, 0] * A2323 - mat[1, 2] * A0323 + mat[1, 3] * A0223),
                         (mat[0, 0] * A2323 - mat[0, 2] * A0323 + mat[0, 3] * A0223),
                         -(mat[0, 0] * A2313 - mat[0, 2] * A0313 + mat[0, 3] * A0213),
                         (mat[0, 0] * A2312 - mat[0, 2] * A0312 + mat[0, 3] * A0212),
                     },
                     {
                         (mat[1, 0] * A1323 - mat[1, 1] * A0323 + mat[1, 3] * A0123),
                         -(mat[0, 0] * A1323 - mat[0, 1] * A0323 + mat[0, 3] * A0123),
                         (mat[0, 0] * A1313 - mat[0, 1] * A0313 + mat[0, 3] * A0113),
                         -(mat[0, 0] * A1312 - mat[0, 1] * A0312 + mat[0, 3] * A0112),
                     },
                     {
                         -(mat[1, 0] * A1223 - mat[1, 1] * A0223 + mat[1, 2] * A0123),
                         (mat[0, 0] * A1223 - mat[0, 1] * A0223 + mat[0, 2] * A0123),
                         -(mat[0, 0] * A1213 - mat[0, 1] * A0213 + mat[0, 2] * A0113),
                         (mat[0, 0] * A1212 - mat[0, 1] * A0212 + mat[0, 2] * A0112),
                     },
                 };
}

constexpr auto transpose(const mat4& mat) -> mat4 {
    return mat4{
        {mat.w},
        {mat.x},
        {mat.y},
        {mat.z},
    };
}

constexpr auto translation(float x, float y, float z) -> mat4 {
    return mat4{
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1},
    };
}

constexpr auto translation(const vec3& translation) -> mat4 {
    return admat::translation(translation.x, translation.y, translation.z);
}

constexpr auto scaling(float x, float y, float z) -> mat4 {
    return mat4{
        {x, 0, 0, 0},
        {0, y, 0, 0},
        {0, 0, z, 0},
        {0, 0, 0, 1},
    };
}

constexpr auto scaling(const vec3& scale) -> mat4 {
    return scaling(scale.x, scale.y, scale.z);
}

constexpr auto orthographic(float width, float height, float near_plane, float far_plane) -> mat4 {
    float range = 1.0f / (near_plane - far_plane);

    return mat4{
        {2.0f / width, 0, 0, 0},
        {0, 2.0f / height, 0, 0},
        {0, 0, range, 0},
        {0, 0, range * near_plane, 1},
    };
}

constexpr auto look_at(const vec3& position, const vec3& target, const vec3& up) -> mat4 {
    auto look  = normalize(target - position);
    auto right = normalize(cross(look, up));
    auto y     = cross(right, look);

    return mat4{
        {right.x, right.y, right.z, -dot(right, position)},
        {y.x, y.y, y.z, -dot(y, position)},
        {-look.x, -look.y, -look.z, dot(look, position)},
        {0, 0, 0, 1},
    };
}

// Right-handed, zero to one depth, projection matrix
constexpr auto perspective(float fov, float aspect, float near_plane, float far_plane) -> mat4 {
    assert(fov > 0.0f && fov < static_cast<float>(std::numbers::pi));
    assert(near_plane > 0.0f);
    assert(far_plane > near_plane);
    assert(far_plane > 0.0f);

    float focal   = 1.0f / std::tan(fov * 0.5f);
    float x_scale = focal / aspect;

    return mat4{
        {x_scale, 0, 0, 0},
        {0, focal, 0, 0},
        {0, 0, far_plane / (near_plane - far_plane), (far_plane * near_plane) / (near_plane - far_plane)},
        {0, 0, -1, 0},
    };
}

} // namespace admat