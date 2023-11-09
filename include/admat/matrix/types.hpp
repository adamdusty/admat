#pragma once

#include <array>
#include <cstdint>
#include <span>

#include <adizzle/assert.hpp>

namespace admat::matrix {

template<typename T, size_t R, size_t C>
class column_major_matrix {
    std::array<T, R * C> _data;

public:
    constexpr column_major_matrix() = default;
    constexpr column_major_matrix(std::array<T, R * C> data) : _data(data) {}

    template<typename... Ts>
    column_major_matrix(Ts... args) : _data{args...} {
        static_assert(sizeof...(Ts) <= R * C);
    }
    constexpr auto operator==(const column_major_matrix<T, R, C>&) const -> bool = default;

    constexpr auto data() const -> std::span<const T> { return _data; }

    constexpr auto at(size_t row, size_t col) -> T& {
        size_t idx = row + (R * (col));
        return _data.at(idx);
    }

    constexpr auto at(size_t row, size_t col) const -> const T& {
        size_t idx = row + (R * (col));
        return _data.at(idx);
    }

    // Template disables function for matrices that are not square
    template<size_t Col = R, size_t Row = C, std::enable_if_t<Col == Row, bool> = true>
    static constexpr auto identity() -> column_major_matrix<T, R, C> {
        auto size = R * C;
        auto mat  = column_major_matrix<T, R, C>{};
        for(size_t i = 0; i < size; ++i) {
            mat._data.at(i) = i % (R + 1) == 0 ? 1 : 0;
        }

        return mat;
    }

    static constexpr auto from_row_major(const std::array<T, C * R>& data) -> column_major_matrix<T, R, C> {
        adizzle::assert(data.size() == R * C);

        auto mat = column_major_matrix<T, R, C>{};

        for(size_t i = 0; i < R; ++i) {
            for(size_t j = 0; j < C; ++j) {
                auto data_idx = j + (C * i);
                mat.at(i, j)  = data.at(data_idx);
            }
        }

        return mat;
    }
};

} // namespace admat::matrix