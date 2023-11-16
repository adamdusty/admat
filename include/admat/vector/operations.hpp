#pragma once

#include <adizzle/assert.hpp>
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

    return vect / mag;

    // auto result = vec<T, N>{};
    // for(size_t i = 0; i < N; ++i) {
    //     result.at(i) = vect.at(i) / mag;
    // }

    // return result;
}

template<typename T, size_t N>
constexpr auto abs(const vec<T, N>& vect) -> vec<T, N> {
    auto result = vec<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = std::abs(vect.at(i));
    }

    return result;
}

template<typename T, size_t N>
constexpr auto acos(const vec<T, N>& vect) -> vec<T, N> {
    auto result = vec<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        adizzle::assert(std::abs(vect.at(i)) <= 1.0f, "acos of value outside [-1, 1] is not meaningful.");
        result.at(i) = std::acos(vect.at(i));
    }

    return result;
}

template<typename T, size_t N>
constexpr auto clamp(const vec<T, N>& vect, T low, T high) -> vec<T, N> {
    auto result = vec<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        result.at(i) = std::min(std::max(vect.at(i), low), high);
    }

    return result;
}

template<typename T, size_t N>
constexpr auto smoothstep(const vec<T, N>& low, const vec<T, N>& high, const vec<T, N>& x) -> vec<T, N> {
    auto result = vec<T, N>{};

    for(size_t i = 0; i < N; ++i) {
        auto interp  = std::clamp((x.at(i) - low) / (high - low), 0, 1);
        result.at(i) = interp * interp * (3 - 2 * interp);
    }

    return result;
}

} // namespace admat::vector