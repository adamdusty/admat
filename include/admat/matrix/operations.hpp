#pragma once

#include <algorithm>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <format>
// #include <iostream>
#include <tuple>

#include <adizzle/assert.hpp>
#include <adizzle/cast.hpp>
#include <adizzle/float.hpp>

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

// https://johnfoster.pge.utexas.edu/numerical-methods-book/LinearAlgebra_LU.html
template<typename T, size_t N>
constexpr auto decompose(const column_major_matrix<T, N, N>& mat)
    -> std::tuple<column_major_matrix<T, N, N>, column_major_matrix<T, N, N>> {
    auto lower = column_major_matrix<T, N, N>::identity();
    auto upper = column_major_matrix<T, N, N>{};

    for(size_t k = 0; k < N; ++k) {

        for(size_t j = k; j < N; ++j) {
            T sum = 0;
            for(size_t m = 0; m < k; ++m) {
                sum += lower.at(k, m) * upper.at(m, j);
            }

            upper.at(k, j) = mat.at(k, j) - sum;
        }

        for(size_t i = k; i < N; ++i) {

            T sum = 0;
            for(size_t m = 0; m < k; ++m) {
                sum += lower.at(i, m) * upper.at(m, k);
            }

            lower.at(i, k) = (mat.at(i, k) - sum) / upper.at(k, k);
        }
    }

    return {lower, upper};
}

template<typename T, size_t N>
constexpr auto plu_decompose(const column_major_matrix<T, N, N>& mat)
    -> std::tuple<column_major_matrix<T, N, N>, column_major_matrix<T, N, N>, column_major_matrix<T, N, N>> {
    auto perm = column_major_matrix<T, N, N>::identity();

    for(size_t i = 0; i < N; ++i) {
        T max_val = 0;
        for(size_t k = i; k < N; ++k) {
            auto current_val = std::abs(mat.at(perm.at(k, k), i));
            if(current_val > max_val) {
                max_val = current_val;
                perm.swap_rows(i, k);
            }
        }
    }

    auto [lower, upper] = decompose(mat);

    return {lower, upper, perm};
}

template<typename T>
constexpr auto invert_mat2(const column_major_matrix<T, 2, 2>& mat) -> column_major_matrix<T, 2, 2> {
    auto det = determinant(mat);
    det      = 1 / det;

    auto inverted     = column_major_matrix<T, 2, 2>{};
    inverted.at(0, 0) = mat.at(1, 1) * det;
    inverted.at(0, 1) = -mat.at(0, 1) * det;
    inverted.at(1, 0) = -mat.at(1, 0) * det;
    inverted.at(1, 1) = mat.at(0, 0) * det;

    return inverted;
}

template<typename T>
constexpr auto invert_mat3(const column_major_matrix<T, 3, 3>& mat) -> column_major_matrix<T, 3, 3> {
    auto det = determinant(mat);
    det      = 1 / det;

    column_major_matrix<T, 3, 3> inverted{};
    inverted.at(0, 0) = (mat.at(1, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(1, 2)) * det;
    inverted.at(0, 1) = (mat.at(0, 2) * mat.at(2, 1) - mat.at(0, 1) * mat.at(2, 2)) * det;
    inverted.at(0, 2) = (mat.at(0, 1) * mat.at(1, 2) - mat.at(0, 2) * mat.at(1, 1)) * det;
    inverted.at(1, 0) = (mat.at(1, 2) * mat.at(2, 0) - mat.at(1, 0) * mat.at(2, 2)) * det;
    inverted.at(1, 1) = (mat.at(0, 0) * mat.at(2, 2) - mat.at(0, 2) * mat.at(2, 0)) * det;
    inverted.at(1, 2) = (mat.at(1, 0) * mat.at(0, 2) - mat.at(0, 0) * mat.at(1, 2)) * det;
    inverted.at(2, 0) = (mat.at(1, 0) * mat.at(2, 1) - mat.at(2, 0) * mat.at(1, 1)) * det;
    inverted.at(2, 1) = (mat.at(2, 0) * mat.at(0, 1) - mat.at(0, 0) * mat.at(2, 1)) * det;
    inverted.at(2, 2) = (mat.at(0, 0) * mat.at(1, 1) - mat.at(1, 0) * mat.at(0, 1)) * det;

    return inverted;
}

template<typename T>
constexpr auto invert_mat4(const column_major_matrix<T, 4, 4>& mat) -> column_major_matrix<T, 4, 4> {
    auto inverted = column_major_matrix<T, 4, 4>{};

    auto A2323 = mat.at(2, 2) * mat.at(3, 3) - mat.at(2, 3) * mat.at(3, 2);
    auto A1323 = mat.at(2, 1) * mat.at(3, 3) - mat.at(2, 3) * mat.at(3, 1);
    auto A1223 = mat.at(2, 1) * mat.at(3, 2) - mat.at(2, 2) * mat.at(3, 1);
    auto A0323 = mat.at(2, 0) * mat.at(3, 3) - mat.at(2, 3) * mat.at(3, 0);
    auto A0223 = mat.at(2, 0) * mat.at(3, 2) - mat.at(2, 2) * mat.at(3, 0);
    auto A0123 = mat.at(2, 0) * mat.at(3, 1) - mat.at(2, 1) * mat.at(3, 0);
    auto A2313 = mat.at(1, 2) * mat.at(3, 3) - mat.at(1, 3) * mat.at(3, 2);
    auto A1313 = mat.at(1, 1) * mat.at(3, 3) - mat.at(1, 3) * mat.at(3, 1);
    auto A1213 = mat.at(1, 1) * mat.at(3, 2) - mat.at(1, 2) * mat.at(3, 1);
    auto A2312 = mat.at(1, 2) * mat.at(2, 3) - mat.at(1, 3) * mat.at(2, 2);
    auto A1312 = mat.at(1, 1) * mat.at(2, 3) - mat.at(1, 3) * mat.at(2, 1);
    auto A1212 = mat.at(1, 1) * mat.at(2, 2) - mat.at(1, 2) * mat.at(2, 1);
    auto A0313 = mat.at(1, 0) * mat.at(3, 3) - mat.at(1, 3) * mat.at(3, 0);
    auto A0213 = mat.at(1, 0) * mat.at(3, 2) - mat.at(1, 2) * mat.at(3, 0);
    auto A0312 = mat.at(1, 0) * mat.at(2, 3) - mat.at(1, 3) * mat.at(2, 0);
    auto A0212 = mat.at(1, 0) * mat.at(2, 2) - mat.at(1, 2) * mat.at(2, 0);
    auto A0113 = mat.at(1, 0) * mat.at(3, 1) - mat.at(1, 1) * mat.at(3, 0);
    auto A0112 = mat.at(1, 0) * mat.at(2, 1) - mat.at(1, 1) * mat.at(2, 0);

    auto det = determinant(mat);
    det      = 1 / det;

    inverted.at(0, 0) = det * (mat.at(1, 1) * A2323 - mat.at(1, 2) * A1323 + mat.at(1, 3) * A1223);
    inverted.at(0, 1) = det * -(mat.at(0, 1) * A2323 - mat.at(0, 2) * A1323 + mat.at(0, 3) * A1223);
    inverted.at(0, 2) = det * (mat.at(0, 1) * A2313 - mat.at(0, 2) * A1313 + mat.at(0, 3) * A1213);
    inverted.at(0, 3) = det * -(mat.at(0, 1) * A2312 - mat.at(0, 2) * A1312 + mat.at(0, 3) * A1212);
    inverted.at(1, 0) = det * -(mat.at(1, 0) * A2323 - mat.at(1, 2) * A0323 + mat.at(1, 3) * A0223);
    inverted.at(1, 1) = det * (mat.at(0, 0) * A2323 - mat.at(0, 2) * A0323 + mat.at(0, 3) * A0223);
    inverted.at(1, 2) = det * -(mat.at(0, 0) * A2313 - mat.at(0, 2) * A0313 + mat.at(0, 3) * A0213);
    inverted.at(1, 3) = det * (mat.at(0, 0) * A2312 - mat.at(0, 2) * A0312 + mat.at(0, 3) * A0212);
    inverted.at(2, 0) = det * (mat.at(1, 0) * A1323 - mat.at(1, 1) * A0323 + mat.at(1, 3) * A0123);
    inverted.at(2, 1) = det * -(mat.at(0, 0) * A1323 - mat.at(0, 1) * A0323 + mat.at(0, 3) * A0123);
    inverted.at(2, 2) = det * (mat.at(0, 0) * A1313 - mat.at(0, 1) * A0313 + mat.at(0, 3) * A0113);
    inverted.at(2, 3) = det * -(mat.at(0, 0) * A1312 - mat.at(0, 1) * A0312 + mat.at(0, 3) * A0112);
    inverted.at(3, 0) = det * -(mat.at(1, 0) * A1223 - mat.at(1, 1) * A0223 + mat.at(1, 2) * A0123);
    inverted.at(3, 1) = det * (mat.at(0, 0) * A1223 - mat.at(0, 1) * A0223 + mat.at(0, 2) * A0123);
    inverted.at(3, 2) = det * -(mat.at(0, 0) * A1213 - mat.at(0, 1) * A0213 + mat.at(0, 2) * A0113);
    inverted.at(3, 3) = det * (mat.at(0, 0) * A1212 - mat.at(0, 1) * A0212 + mat.at(0, 2) * A0112);

    return inverted;
}

template<typename T, size_t N>
constexpr auto inverse(const column_major_matrix<T, N, N>& mat) -> column_major_matrix<T, N, N> {
    adizzle::assert(std::abs(determinant(mat)) > 0, std::format("Matrix not invertible: {}", determinant(mat)));

    if constexpr(N == 2) {
        return invert_mat2(mat);
    } else if constexpr(N == 3) {
        return invert_mat3(mat);
    } else if constexpr(N == 4) {
        return invert_mat4(mat);
    }
}

} // namespace admat::matrix