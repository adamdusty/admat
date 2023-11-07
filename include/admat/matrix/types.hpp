#pragma once

#include <array>
#include <cstdint>

namespace admat::matrix {

template<typename T, size_t C, size_t R>
class column_major_matrix {
    std::array<T, C * R> _data;

public:
    constexpr column_major_matrix() = default;
    constexpr column_major_matrix(std::array<T, C * R> data) : _data(data) {}

    constexpr auto at(size_t row, size_t col) const -> const T& {
        size_t idx = row + (R * (col - 1)) - 1;
        return _data.at(idx);
    }
    constexpr auto operator==(const column_major_matrix<T, C, R>&) const -> bool = default;

    template<size_t Cols = C, size_t Rows = R, std::enable_if_t<C == R, bool> = true>
    static constexpr auto identity() -> column_major_matrix<T, C, R> {
        auto size = Cols * Rows;
        auto mat  = column_major_matrix<T, Cols, Rows>{};
        for(size_t i = 0; i < size; ++i) {
            mat._data.at(i) = i % (Cols + 1) == 0 ? 1 : 0;
        }

        return mat;
    }
};

template<typename T, size_t N>
constexpr auto identity() -> column_major_matrix<T, N, N> {
    auto mat = column_major_matrix<T, N, N>{};
    for(auto i = 0; i < (N * N); ++i) {
        if(i % N == 0) {
            mat.at(i, i) = static_cast<T>(1);
        }
    }
}

} // namespace admat::matrix