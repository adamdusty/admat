#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <concepts>
#include <cstdint>

#include "admat/vector/types.hpp"

namespace admat::vector {

template<typename T, size_t N>
constexpr auto operator+(const vec<T, N>& lhs, const vec<T, N>& rhs) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) + rhs.at(i);
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator+(const vec<T, N>& lhs, const T scalar) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) + scalar;
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator-(const vec<T, N>& lhs, const vec<T, N>& rhs) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) - rhs.at(i);
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator-(const vec<T, N>& lhs, const T scalar) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) - scalar;
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator*(const vec<T, N>& lhs, const T scalar) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) * scalar;
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator*(const T scalar, const vec<T, N>& rhs) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = rhs.at(i) * scalar;
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto operator/(const vec<T, N>& lhs, const T scalar) -> vec<T, N> {
    auto result = std::array<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = lhs.at(i) / scalar;
    }

    return vec<T, N>{result};
}

template<typename T, size_t N>
constexpr auto dot(const vec<T, N>& lhs, const vec<T, N>& rhs) -> T {
    T sum = 0;

    for(size_t i = 0; i < N; ++i) {
        sum += lhs.at(i) * rhs.at(i);
    }

    return sum;
}

template<typename T>
constexpr auto cross(const vec<T, 3>& lhs, const vec<T, 3>& rhs) -> vec<T, 3> {
    return vec<T, 3>{
        (lhs.at(1) * rhs.at(2) - lhs.at(2) * rhs.at(1)),
        (lhs.at(2) * rhs.at(0) - lhs.at(0) * rhs.at(2)),
        (lhs.at(0) * rhs.at(1) - lhs.at(1) * rhs.at(0)),
    };
}

template<typename T, size_t N>
constexpr auto magnitude(const vec<T, N>& vect) -> T {
    return std::sqrt(dot(vect, vect));
}

template<typename T, size_t N>
constexpr auto normalize(const vec<T, N>& vect) -> vec<T, N> {
    auto mag = magnitude(vect);

    auto result = vec<T, N>{};
    for(size_t i = 0; i < N; ++i) {
        result.at(i) = vect.at(i) / mag;
    }

    return result;
}

} // namespace admat::vector