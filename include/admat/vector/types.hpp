#pragma once

#include <array>
#include <concepts>
#include <cstdint>

namespace admat {

template<typename T, size_t N>
class vec {
    std::array<T, N> _data{};

public:
    template<typename... Ts>
    vec(Ts... args) : _data{args...} {
        static_assert(sizeof...(Ts) <= N);
    }

    vec(std::array<T, N> data) : _data(data) {}

    constexpr auto get() const -> std::array<T, N> { return _data; }
    constexpr auto at(size_t idx) -> T& { return _data.at(idx); }
    constexpr auto at(size_t idx) const -> const T& { return _data.at(idx); }
    constexpr auto operator==(const vec<T, N>&) const -> bool = default;
};

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;

using vec2i = vec<std::int32_t, 2>;
using vec3i = vec<std::int32_t, 3>;
using vec4i = vec<std::int32_t, 4>;

using vec2u = vec<std::uint32_t, 2>;
using vec3u = vec<std::uint32_t, 3>;
using vec4u = vec<std::uint32_t, 4>;

} // namespace admat