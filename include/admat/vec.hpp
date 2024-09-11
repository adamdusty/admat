#pragma once

#include <libassert/assert.hpp>

#include <array>
#include <cmath>
#include <cstddef>
#include <type_traits>

namespace admat {

struct vec2 {
    float x;
    float y;

    constexpr auto operator[](std::size_t idx) const -> float {
        ASSERT(idx < 2, "vec2 index out of bounds");

        return *(&(this->x) + idx); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    }

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

    constexpr auto operator[](std::size_t idx) const -> float {
        ASSERT(idx < 3, "vec3 index out of bounds");

        return *(&(this->x) + idx); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    }

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

    constexpr auto operator[](std::size_t idx) const -> float {
        ASSERT(idx < 4, "vec4 index out of bounds");

        return *(&(this->x) + idx); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    }

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

constexpr auto abs(const vec2& vec) -> vec2 {
    return vec2{
        std::abs(vec.x),
        std::abs(vec.y),
    };
}

constexpr auto abs(const vec3& vec) -> vec3 {
    return vec3{
        std::abs(vec.x),
        std::abs(vec.y),
        std::abs(vec.z),
    };
}

constexpr auto abs(const vec4& vec) -> vec4 {
    return vec4{
        std::abs(vec.w),
        std::abs(vec.x),
        std::abs(vec.y),
        std::abs(vec.z),
    };
}

constexpr auto distance(const vec2& lhs, const vec2& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);

    return std::sqrt(x + y);
}

constexpr auto distance(const vec3& lhs, const vec3& rhs) -> float {
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return std::sqrt(x + y + z);
}

constexpr auto distance(const vec4& lhs, const vec4& rhs) -> float {
    auto w = (rhs.w - lhs.w) * (rhs.w - lhs.w);
    auto x = (rhs.x - lhs.x) * (rhs.x - lhs.x);
    auto y = (rhs.y - lhs.y) * (rhs.y - lhs.y);
    auto z = (rhs.z - lhs.z) * (rhs.z - lhs.z);

    return std::sqrt(w + x + y + z);
}

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