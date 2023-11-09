#pragma once

#include <algorithm>
#include <concepts>
#include <cstdint>

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

template<typename T, std::convertible_to<T> U, size_t M, size_t N>
constexpr auto operator*(U scalar, const column_major_matrix<T, M, N>& rhs) -> column_major_matrix<T, M, N> {

    auto data = rhs.data();
    auto arr  = std::array<T, M * N>{};
    std::transform(data.begin(), data.end(), arr.begin(), [scalar](T x) { return scalar * x; });
    auto mat = column_major_matrix<T, M, N>{arr};
    return mat;
}

template<typename T, std::convertible_to<T> U, size_t M, size_t N>
constexpr auto operator*(const column_major_matrix<T, M, N>& rhs, U scalar) -> column_major_matrix<T, M, N> {

    auto data = rhs.data();
    auto arr  = std::array<T, M * N>{};
    std::transform(data.begin(), data.end(), arr.begin(), [scalar](T x) { return scalar * x; });
    auto mat = column_major_matrix<T, M, N>{arr};
    return mat;
}

template<typename T, size_t N>
constexpr auto determinant(const column_major_matrix<T, N, N>& mat) -> T {
    if constexpr(N == 0) {
        return 1;
    } else if constexpr(N == 1) {
        return mat.at(0, 0);
    } else if constexpr(N == 2) {
        return mat.at(0, 0) * mat.at(1, 1) - mat.at(1, 0) * mat.at(0, 1);
    } else {
        auto result = T{};
        T sign      = 1;

        for(size_t i = 0; i < N; ++i) {
            auto sub_mat = column_major_matrix<T, N - 1, N - 1>{};
            for(size_t row = 1; row < N; ++row) {
                size_t z = 0;
                for(size_t col = 0; col < N; ++col) {
                    if(col != i) {
                        sub_mat.at(row - 1, z++) = mat.at(row, col);
                    }
                }
            }

            result += sign * mat.at(0, i) * determinant(sub_mat);
            sign = -sign;
        }

        return result;
    }
}

// template<typename T>
// constexpr auto determinant(const column_major_matrix<T, 2, 2>& mat) -> T {
//     return mat.at(0, 0) * mat.at(1, 1) - mat.at(1, 0) * mat.at(0, 1);
// }

// template<typename T>
// constexpr auto determinant(const column_major_matrix<T, 3, 3>& mat) -> T {
//     // clang-format off
//     return
//         + mat.at(0, 0) * (mat.at(1, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(1, 2))
//         - mat.at(1, 0) * (mat.at(0, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(0, 2))
//         + mat.at(2, 0) * (mat.at(0, 1) * mat.at(1, 2) - mat.at(1, 1) * mat.at(0, 2));
//     // clang-format on
// }

// template<typename T>
// constexpr auto determinant(const column_major_matrix<T, 4, 4>& mat) -> T {
//     // clang-format off
//     return
//          mat.at(0,3) * mat.at(1,2) * mat.at(2,1) * mat.at(3,0) - mat.at(0,2) * mat.at(1,3) * mat.at(2,1) *
//          mat.at(3,0) - mat.at(0,3) * mat.at(1,1) * mat.at(2,2) * mat.at(3,0) + mat.at(0,1) * mat.at(1,3) *
//          mat.at(2,2) * mat.at(3,0) + mat.at(0,2) * mat.at(1,1) * mat.at(2,3) * mat.at(3,0) - mat.at(0,1) *
//          mat.at(1,2) * mat.at(2,3) * mat.at(3,0) - mat.at(0,3) * mat.at(1,2) * mat.at(2,0) * mat.at(3,1) +
//          mat.at(0,2) * mat.at(1,3) * mat.at(2,0) * mat.at(3,1) + mat.at(0,3) * mat.at(1,0) * mat.at(2,2) *
//          mat.at(3,1) - mat.at(0,0) * mat.at(1,3) * mat.at(2,2) * mat.at(3,1) - mat.at(0,2) * mat.at(1,0) *
//          mat.at(2,3) * mat.at(3,1) + mat.at(0,0) * mat.at(1,2) * mat.at(2,3) * mat.at(3,1) + mat.at(0,3) *
//          mat.at(1,1) * mat.at(2,0) * mat.at(3,2) - mat.at(0,1) * mat.at(1,3) * mat.at(2,0) * mat.at(3,2) -
//          mat.at(0,3) * mat.at(1,0) * mat.at(2,1) * mat.at(3,2) + mat.at(0,0) * mat.at(1,3) * mat.at(2,1) *
//          mat.at(3,2) + mat.at(0,1) * mat.at(1,0) * mat.at(2,3) * mat.at(3,2) - mat.at(0,0) * mat.at(1,1) *
//          mat.at(2,3) * mat.at(3,2) - mat.at(0,2) * mat.at(1,1) * mat.at(2,0) * mat.at(3,3) + mat.at(0,1) *
//          mat.at(1,2) * mat.at(2,0) * mat.at(3,3) + mat.at(0,2) * mat.at(1,0) * mat.at(2,1) * mat.at(3,3) -
//          mat.at(0,0) * mat.at(1,2) * mat.at(2,1) * mat.at(3,3) - mat.at(0,1) * mat.at(1,0) * mat.at(2,2) *
//          mat.at(3,3) + mat.at(0,0) * mat.at(1,1) * mat.at(2,2) * mat.at(3,3);
//     // clang-format on
// }

template<typename T, size_t N>
constexpr auto inverse(const column_major_matrix<T, N, N>& mat) -> column_major_matrix<T, N, N> {
    adizzle::assert(determinant(mat) != 0, "Can't take inverse of matrix");

    return {};
}

} // namespace admat::matrix