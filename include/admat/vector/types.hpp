#pragma once

#include <array>
#include <concepts>
#include <cstdint>

namespace admat::vector {

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

} // namespace admat::vector