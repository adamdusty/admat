#pragma once

#include <array>
#include <cstdint>

#include <adizzle/assert.hpp>

namespace admat::matrix {

template<typename T, size_t C, size_t R>
class column_major_matrix {
    std::array<T, C * R> _data;

public:
    constexpr column_major_matrix() = default;
    constexpr column_major_matrix(std::array<T, C * R> data) : _data(data) {}
    constexpr auto operator==(const column_major_matrix<T, C, R>&) const -> bool = default;

    constexpr auto at(size_t row, size_t col) -> T& {
        size_t idx = row + (R * (col));
        return _data.at(idx);
    }

    constexpr auto at(size_t row, size_t col) const -> const T& {
        size_t idx = row + (R * (col));
        return _data.at(idx);
    }

    template<std::enable_if_t<C == R, bool> = true>
    static constexpr auto identity() -> column_major_matrix<T, C, R> {
        auto size = C * R;
        auto mat  = column_major_matrix<T, C, R>{};
        for(size_t i = 0; i < size; ++i) {
            mat._data.at(i) = i % (C + 1) == 0 ? 1 : 0;
        }

        return mat;
    }

    static constexpr auto from_row_major(const std::array<T, R * C>& data) -> column_major_matrix<T, C, R> {
        adizzle::assert(data.size() == R * C);

        auto mat = column_major_matrix<T, C, R>{};

        for(size_t i = 0; i < R; ++i) {
            for(size_t j = 0; j < C; ++j) {
                auto data_idx = j + (C * i);
                mat.at(i, j)  = data.at(data_idx);
            }
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