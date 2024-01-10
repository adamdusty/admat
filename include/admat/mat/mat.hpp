#pragma once

#include <adizzle/assert.hpp>
#include <admat/vec.hpp>
#include <array>
#include <cstddef>
#include <memory>
#include <span>

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

    constexpr auto operator()(std::size_t row, std::size_t col) const -> float {
        ADIZZLE_ASSERT(row < 4 && col < 4, "Out of bounds matrix access");

        std::size_t index = col * 4 + row;
        return *(&(w.w) + index);
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

} // namespace admat