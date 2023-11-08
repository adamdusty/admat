#pragma once

#include "admat/matrix/types.hpp"

namespace admat::matrix {

template<typename T, size_t R, size_t C>
auto operator+(const column_major_matrix<T, R, C>& lhs, const column_major_matrix<T, R, C>& rhs)
    -> column_major_matrix<T, R, C> {

    auto mat = column_major_matrix<T, R, C>{};

    for(size_t i = 0; i < C; ++i) {
        for(size_t j = 0; j < R; ++j) {
            mat.at(i, j) = lhs.at(i, j) + rhs.at(i, j);
        }
    }

    return mat;
}

template<typename T, size_t R, size_t C>
auto operator-(const column_major_matrix<T, R, C>& lhs, const column_major_matrix<T, R, C>& rhs)
    -> column_major_matrix<T, R, C> {

    auto mat = column_major_matrix<T, R, C>{};

    for(size_t i = 0; i < C; ++i) {
        for(size_t j = 0; j < R; ++j) {
            mat.at(i, j) = lhs.at(i, j) - rhs.at(i, j);
        }
    }

    return mat;
}

template<typename T, size_t M, size_t N, size_t P>
auto operator*(const column_major_matrix<T, M, N>& lhs, const column_major_matrix<T, N, P>& rhs)
    -> column_major_matrix<T, M, P> {

    auto mat = column_major_matrix<T, M, P>{};

    for(size_t i = 0; i < M; ++i) {
        for(size_t j = 0; j < P; ++j) {
            for(size_t k = 0; k < N; ++k) {
                mat.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
            }
        }
    }

    return mat;
}

template<typename T>
auto determinant(const column_major_matrix<T, 2, 2>& mat) -> T {
    return mat.at(0, 0) * mat.at(1, 1) - mat.at(1, 0) * mat.at(0, 1);
}

template<typename T>
auto determinant(const column_major_matrix<T, 3, 3>& mat) -> T {
    // clang-format off
    return 
        + mat.at(0, 0) * (mat.at(1, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(1, 2))
        - mat.at(1, 0) * (mat.at(0, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(0, 2))
        + mat.at(2, 0) * (mat.at(0, 1) * mat.at(1, 2) - mat.at(1, 1) * mat.at(0, 2));
    // clang-format on
}

template<typename T>
auto determinant(const column_major_matrix<T, 4, 4>& mat) -> T {
    // clang-format off
    return 
         mat.at(0,3) * mat.at(1,2) * mat.at(2,1) * mat.at(3,0) - mat.at(0,2) * mat.at(1,3) * mat.at(2,1) * mat.at(3,0) -
         mat.at(0,3) * mat.at(1,1) * mat.at(2,2) * mat.at(3,0) + mat.at(0,1) * mat.at(1,3) * mat.at(2,2) * mat.at(3,0) +
         mat.at(0,2) * mat.at(1,1) * mat.at(2,3) * mat.at(3,0) - mat.at(0,1) * mat.at(1,2) * mat.at(2,3) * mat.at(3,0) -
         mat.at(0,3) * mat.at(1,2) * mat.at(2,0) * mat.at(3,1) + mat.at(0,2) * mat.at(1,3) * mat.at(2,0) * mat.at(3,1) +
         mat.at(0,3) * mat.at(1,0) * mat.at(2,2) * mat.at(3,1) - mat.at(0,0) * mat.at(1,3) * mat.at(2,2) * mat.at(3,1) -
         mat.at(0,2) * mat.at(1,0) * mat.at(2,3) * mat.at(3,1) + mat.at(0,0) * mat.at(1,2) * mat.at(2,3) * mat.at(3,1) +
         mat.at(0,3) * mat.at(1,1) * mat.at(2,0) * mat.at(3,2) - mat.at(0,1) * mat.at(1,3) * mat.at(2,0) * mat.at(3,2) -
         mat.at(0,3) * mat.at(1,0) * mat.at(2,1) * mat.at(3,2) + mat.at(0,0) * mat.at(1,3) * mat.at(2,1) * mat.at(3,2) +
         mat.at(0,1) * mat.at(1,0) * mat.at(2,3) * mat.at(3,2) - mat.at(0,0) * mat.at(1,1) * mat.at(2,3) * mat.at(3,2) -
         mat.at(0,2) * mat.at(1,1) * mat.at(2,0) * mat.at(3,3) + mat.at(0,1) * mat.at(1,2) * mat.at(2,0) * mat.at(3,3) +
         mat.at(0,2) * mat.at(1,0) * mat.at(2,1) * mat.at(3,3) - mat.at(0,0) * mat.at(1,2) * mat.at(2,1) * mat.at(3,3) -
         mat.at(0,1) * mat.at(1,0) * mat.at(2,2) * mat.at(3,3) + mat.at(0,0) * mat.at(1,1) * mat.at(2,2) * mat.at(3,3);
    // clang-format on
}

} // namespace admat::matrix