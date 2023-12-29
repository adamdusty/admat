#pragma once

#include <array>
#include <type_traits>

namespace admat {

struct vec2 {
    float x;
    float y;

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 2>() { return {x, y}; }

    static constexpr auto from_array(const std::array<float, 2>& data) -> vec2 {
        return vec2{
            data.at(0),
            data.at(1),
        };
    }
};

struct vec3 {
    float x;
    float y;
    float z;

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 3>() { return {x, y, z}; }

    static constexpr auto from_array(const std::array<float, 3>& data) -> vec3 {
        return vec3{
            data.at(0),
            data.at(1),
            data.at(2),
        };
    }
};

struct vec4 {
    float w;
    float x;
    float y;
    float z;

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 4>() { return {w, x, y, z}; }

    static constexpr auto from_array(const std::array<float, 4>& data) -> vec4 {
        return vec4{
            data.at(0),
            data.at(1),
            data.at(2),
            data.at(3),
        };
    }
};

static_assert(std::is_standard_layout_v<vec2> && std::is_trivial_v<vec2>, "vec2 not pod");
static_assert(std::is_standard_layout_v<vec3> && std::is_trivial_v<vec3>, "vec3 not pod");
static_assert(std::is_standard_layout_v<vec4> && std::is_trivial_v<vec4>, "vec4 not pod");

constexpr auto operator+(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

constexpr auto operator-(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x - rhs.x, lhs.y - rhs.y};
}

constexpr auto operator-(const vec2& vec) -> vec2 {
    return vec2{-vec.x, -vec.y};
}

constexpr auto operator*(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x * rhs.x, lhs.y * rhs.y};
}

constexpr auto operator/(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x / rhs.x, lhs.y / rhs.y};
}

constexpr auto operator+(const vec3& lhs, const vec3& rhs) -> vec3 {
    return vec3{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

constexpr auto operator-(const vec3& lhs, const vec3& rhs) -> vec3 {
    return vec3{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

constexpr auto operator-(const vec3& vec) -> vec3 {
    return vec3{-vec.x, -vec.y, -vec.z};
}

constexpr auto operator*(const vec3& lhs, const vec3& rhs) -> vec3 {
    return vec3{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

constexpr auto operator/(const vec3& lhs, const vec3& rhs) -> vec3 {
    return vec3{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

constexpr auto operator+(const vec4& lhs, const vec4& rhs) -> vec4 {
    return vec4{lhs.w + rhs.w, lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

constexpr auto operator-(const vec4& lhs, const vec4& rhs) -> vec4 {
    return vec4{lhs.w - rhs.w, lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

constexpr auto operator-(const vec4& vec) -> vec4 {
    return vec4{-vec.w, -vec.x, -vec.y, -vec.z};
}

constexpr auto operator*(const vec4& lhs, const vec4& rhs) -> vec4 {
    return vec4{lhs.w * rhs.w, lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

constexpr auto operator/(const vec4& lhs, const vec4& rhs) -> vec4 {
    return vec4{lhs.w / rhs.w, lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

constexpr auto operator+(const vec2& lhs, float scalar) -> vec2 {
    return vec2{lhs.x + scalar, lhs.y + scalar};
}

constexpr auto operator+(float scalar, const vec2& vec) -> vec2 {
    return vec + scalar;
}

constexpr auto operator+(const vec3& lhs, float scalar) -> vec3 {
    return vec3{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
}
constexpr auto operator+(float scalar, const vec3& vec) -> vec3 {
    return vec + scalar;
}

constexpr auto operator+(const vec4& lhs, float scalar) -> vec4 {
    return vec4{lhs.w + scalar, lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
}

constexpr auto operator+(float scalar, const vec4& vec) -> vec4 {
    return vec + scalar;
}

constexpr auto operator-(const vec2& lhs, float scalar) -> vec2 {
    return vec2{lhs.x - scalar, lhs.y - scalar};
}
constexpr auto operator-(float scalar, const vec2& vec) -> vec2 {
    return vec - scalar;
}

constexpr auto operator-(const vec3& lhs, float scalar) -> vec3 {
    return vec3{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};
}

constexpr auto operator-(float scalar, const vec3& vec) -> vec3 {
    return vec - scalar;
}

constexpr auto operator-(const vec4& lhs, float scalar) -> vec4 {
    return vec4{lhs.w - scalar, lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};
}

constexpr auto operator-(float scalar, const vec4& vec) -> vec4 {
    return vec - scalar;
}

constexpr auto operator*(const vec2& lhs, float scalar) -> vec2 {
    return vec2{lhs.x * scalar, lhs.y * scalar};
}

constexpr auto operator*(float scalar, const vec2& vec) -> vec2 {
    return vec * scalar;
}

constexpr auto operator*(const vec3& lhs, float scalar) -> vec3 {
    return vec3{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar};
}

constexpr auto operator*(float scalar, const vec3& vec) -> vec3 {
    return vec * scalar;
}

constexpr auto operator*(const vec4& lhs, float scalar) -> vec4 {
    return vec4{lhs.w * scalar, lhs.x * scalar, lhs.y * scalar, lhs.z * scalar};
}

constexpr auto operator*(float scalar, const vec4& vec) -> vec4 {
    return vec * scalar;
}

constexpr auto operator/(const vec2& lhs, float scalar) -> vec2 {
    return vec2{lhs.x / scalar, lhs.y / scalar};
}

constexpr auto operator/(float scalar, const vec2& vec) -> vec2 {
    return vec / scalar;
}

constexpr auto operator/(const vec3& lhs, float scalar) -> vec3 {
    return vec3{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
}

constexpr auto operator/(float scalar, const vec3& vec) -> vec3 {
    return vec / scalar;
}

constexpr auto operator/(const vec4& lhs, float scalar) -> vec4 {
    return vec4{lhs.w / scalar, lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
}

constexpr auto operator/(float scalar, const vec4& vec) -> vec4 {
    return vec / scalar;
}

} // namespace admat