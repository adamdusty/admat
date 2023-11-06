#pragma once

#include <array>
#include <cstdint>
#include <ranges>

#include "admat/vector/types.hpp"

namespace admat {

template<typename T, size_t N>
constexpr auto operator+(const vec<T, N>& lhs, const vec<T, N>& rhs) -> vec<T, N> {
    auto result = vec<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) + rhs.at(i);
    }

    return result;
}

} // namespace admat