#pragma once

#include "admat/matrix.hpp"
#include "admat/vector.hpp"

namespace admat {

using admat::column_major_matrix;
using admat::vec;

template<typename T, size_t M, size_t N>
auto operator*(const vec<T, N>& lhs, const column_major_matrix<T, M, N>& rhs) -> vec<T, M> {
    auto result = vec<T, M>{};

    for(size_t i = 0; i < M; ++i) {
        for(size_t j = 0; j < N; ++j) {
            result.at(i) += lhs.at(i) * rhs.at(i, j);
        }
    }

    return result;
}

template<typename T, size_t M, size_t N>
auto operator*(const column_major_matrix<T, M, N>& lhs, const vec<T, N>& rhs) -> vec<T, M> {
    return rhs * lhs;
}

} // namespace admat