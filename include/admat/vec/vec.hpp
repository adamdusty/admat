#pragma once

#include <array>

namespace admat {

struct vec2 {
    float x = 0.0f;
    float y = 0.0f;

    constexpr vec2() = default;
    constexpr vec2(float x_val, float y_val) : x{x_val}, y{y_val} {}
    constexpr vec2(const std::array<float, 2>& data) : x{data.at(0)}, y{data.at(1)} {}

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 2>() { return {x, y}; }
};

struct vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    constexpr vec3() = default;
    constexpr vec3(float x_val, float y_val, float z_val) : x{x_val}, y{y_val}, z{z_val} {}
    constexpr vec3(const std::array<float, 4>& data) : x{data.at(0)}, y{data.at(1)}, z{data.at(2)} {}

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 3>() { return {x, y, z}; }
};

struct vec4 {
    float w = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    constexpr vec4() = default;
    constexpr vec4(float w_val, float x_val, float y_val, float z_val) : w{w_val}, x{x_val}, y{y_val}, z{z_val} {}
    constexpr vec4(const std::array<float, 4>& data) : w{data.at(0)}, x{data.at(1)}, y{data.at(2)}, z{data.at(3)} {}

    // Enable implicit conversion to array. Not sure I like this?
    constexpr operator std::array<float, 4>() { return {w, x, y, z}; }
};

constexpr auto operator+(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

constexpr auto operator-(const vec2& lhs, const vec2& rhs) -> vec2 {
    return vec2{lhs.x - rhs.x, lhs.y - rhs.y};
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