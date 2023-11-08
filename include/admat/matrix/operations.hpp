#pragma once

#include "admat/matrix/types.hpp"

namespace admat::matrix {

template<typename T, size_t C, size_t R>
auto operator+(const column_major_matrix<T, C, R>& lhs, const column_major_matrix<T, C, R>& rhs)
    -> column_major_matrix<T, C, R> {

    auto mat = column_major_matrix<T, C, R>{};

    for(size_t i = 1; i <= R; ++i) {
        for(size_t j = 1; j <= C; ++j) {
            mat.at(i, j) = lhs.at(i, j) + rhs.at(i, j);
        }
    }

    return mat;
}

} // namespace admat::matrix