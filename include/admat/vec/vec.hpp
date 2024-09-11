#pragma once

#include <array>
#include <cstddef>
#include <type_traits>

namespace admat {

struct vec2 {
    float x;
    float y;

    constexpr auto operator[](std::size_t idx) const -> float {
        // ADIZZLE_ASSERT(idx < 2, "vec2 index out of bounds");

        return *(&(this->x) + idx);
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
        // ADIZZLE_ASSERT(idx < 3, "vec3 index out of bounds");

        return *(&(this->x) + idx);
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
        // ADIZZLE_ASSERT(idx < 4, "vec4 index out of bounds");

        return *(&(this->x) + idx);
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

} // namespace admat