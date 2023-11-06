#pragma once

#include <array>
#include <cstdint>

namespace admat {

template<typename T, size_t N>
class vec {
    std::array<T, N> _data;

public:
    template<typename... Ts>
    vec(Ts... args) : _data{args...} {}

    constexpr auto at(size_t idx) -> T& { return _data.at(idx); }
    constexpr auto at(size_t idx) const -> const T& { return _data.at(idx); }
    constexpr auto operator==(const vec<T, N>&) const -> bool = default;
};

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;

} // namespace admat