#pragma once

#include <array>
#include <cstdint>
#include <format>
#include <span>

#include <adizzle/assert.hpp>

namespace admat {

template<typename T, size_t R, size_t C>
class column_major_matrix {
    std::array<T, R * C> _data{};

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
        size_t idx = row + (R * col);
        return _data.at(idx);
    }

    constexpr auto at(size_t row, size_t col) const -> const T& {
        size_t idx = row + (R * col);
        return _data.at(idx);
    }

    constexpr auto row(size_t index) const -> std::array<T, C> {
        ADIZZLE_ASSERT(index < R, std::format("Trying to access row {}, of and {}x{} matrix", index, R, C));
        auto res = std::array<T, C>{};

        for(size_t i = 0; i < C; ++i) {
            res.at(i) = _data.at((i * R) + index);
        }

        return res;
    }

    constexpr auto col(size_t index) const -> std::array<T, R> {
        ADIZZLE_ASSERT(index < C, std::format("Trying to access column {}, of and {}x{} matrix", index, R, C));
        auto res = std::array<T, R>{};

        for(size_t i = 0; i < R; ++i) {
            res.at(i) = _data.at((R * index) + i);
        }

        return res;
    }

    constexpr auto set_row(size_t index, const std::array<T, C>& values) -> void {
        for(size_t i = 0; i < C; ++i) {
            _data.at((R * i) + index) = values.at(i);
        }
    }

    constexpr auto set_col(size_t index, const std::array<T, R>& values) -> void {
        for(size_t i = 0; i < C; ++i) {
            _data.at((R * index) + i) = values.at(i);
        }
    }

    constexpr auto swap_rows(size_t row1, size_t row2) -> void {
        auto tmp = row(row1);
        set_row(row1, row(row2));
        set_row(row2, tmp);
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

} // namespace admat