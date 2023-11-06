#pragma once

#include <array>
#include <cstdint>

namespace admat {

template<typename T, size_t N>
struct vec {
    std::array<T, N> data;

    constexpr auto operator==(const vec<T, N>&) const -> bool = default;
};

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;

} // namespace admat