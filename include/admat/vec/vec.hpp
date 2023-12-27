#pragma once

namespace admat {

struct vec2 {
    float x = 0.0f;
    float y = 0.0f;
};

struct vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct vec4 {
    float w = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
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