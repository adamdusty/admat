#pragma once

#include "admat/vector/operations.hpp"
#include "admat/vector/types.hpp"
#include <cmath>
#include <cstdint>

namespace admat {

template<typename T, size_t N>
constexpr auto distance(const vec<T, N>& a, const vec<T, N>& b) -> T {
    auto x = (b.at(0) - a.at(0)) * (b.at(0) - a.at(0));
    auto y = (b.at(1) - a.at(1)) * (b.at(1) - a.at(1));
    auto z = (b.at(2) - a.at(2)) * (b.at(2) - a.at(2));

    return std::sqrt(x + y + z);
}

template<typename T, size_t N>
constexpr auto reflect(const vec<T, N>& incident, const vec<T, N>& normal) -> vec<T, N> {
    return incident - (static_cast<T>(2.0) * dot(normal, incident) * normal);
}

template<typename T, size_t N>
constexpr auto refract(const vec<T, N>& incident, const vec<T, N>& normal, T ratio) -> vec<T, N> {
    auto constant =
        static_cast<T>(1.0) - ratio * ratio * (static_cast<T>(1.0) - dot(normal, incident) * dot(normal, incident));
    if(constant < static_cast<T>(0.0)) {
        return vec<T, N>{};
    }

    return ratio * incident - (ratio * dot(normal, incident) + std::sqrt(constant)) * normal;
}

} // namespace admat