// #pragma once

// #include "admat/vector/operations.hpp"
// #include "admat/vector/types.hpp"
// #include <cmath>
// #include <cstdint>

// namespace admat {

// template<typename T, size_t N>
// constexpr auto refract(const vec<T, N>& incident, const vec<T, N>& normal, T ratio) -> vec<T, N> {
//     auto constant =
//         static_cast<T>(1.0) - ratio * ratio * (static_cast<T>(1.0) - dot(normal, incident) * dot(normal, incident));
//     if(constant < static_cast<T>(0.0)) {
//         return vec<T, N>{};
//     }

//     return ratio * incident - (ratio * dot(normal, incident) + std::sqrt(constant)) * normal;
// }

// template<typename T, size_t N>
// constexpr auto lerp(vec<T, N> from, const vec<T, N>& to, float delta) -> vec<T, N> {
//     for(size_t i = 0; i < N; ++i) {
//         from.at(i) = std::lerp(from.at(i), to.at(i), delta);
//     }

//     return from;
// }

// template<typename T, size_t N>
// constexpr auto lerp(vec<T, N> from, const vec<T, N>& to, double delta) -> vec<T, N> {
//     for(size_t i = 0; i < N; ++i) {
//         from.at(i) = std::lerp(from.at(i), to.at(i), delta);
//     }

//     return from;
// }

// } // namespace admat