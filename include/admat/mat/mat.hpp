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

    constexpr auto operator()(std::size_t row, std::size_t col) const -> float {
        ADIZZLE_ASSERT(row < 4 && col < 4, "Out of bounds matrix access");

        std::size_t index = row * 4 + col;
        return *(&(w.w) + index);
    }

    static auto consteval identity() -> mat4 {
        return mat4{
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        };
    }
};

} // namespace admat