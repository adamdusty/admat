#pragma once

#include <adizzle/assert.hpp>
#include <array>
#include <cstddef>
#include <span>

namespace admat {

class mat4 {
    std::array<float, 16> data;

public:
    constexpr mat4() : data{} {}
    constexpr mat4(const std::array<float, 16>& values) : data(values) {}

    constexpr auto operator()(size_t row, size_t col) const -> float {
        ADIZZLE_ASSERT(row < 4 && col < 4, "Out of bounds matrix access.");

        size_t idx = row + (4 * col);
        return data.at(idx);
    }

    constexpr auto operator()(size_t row, size_t col) -> float& {
        ADIZZLE_ASSERT(row < 4 && col < 4, "Out of bounds matrix access.");

        size_t idx = row + (4 * col);
        return data.at(idx);
    }

    constexpr auto get() const -> std::span<const float, 16> { return std::span{data}; }

    constexpr auto row(size_t index) const -> std::array<float, 4> {
        ADIZZLE_ASSERT(index < 4, "Row index greater than row count.");
        auto result = std::array<float, 4>{};

        for(size_t i = 0; i < 4; ++i) {
            result.at(i) = data.at((i * 4) + index);
        }

        return result;
    }

    constexpr auto col(size_t index) const -> std::array<float, 4> {
        ADIZZLE_ASSERT(index < 4, "Col index greater than col count.");
        auto result = std::array<float, 4>{};

        for(size_t i = 0; i < 4; ++i) {
            result.at(i) = data.at((4 * index) + i);
        }

        return result;
    }

    constexpr auto set_row(size_t index, const std::array<float, 4>& values) {
        ADIZZLE_ASSERT(index < 4, "Row index greater than row count.");

        for(size_t i = 0; i < 4; ++i) {
            data.at((4 * i) + index) = values.at(i);
        }
    }

    constexpr auto set_col(size_t index, const std::array<float, 4>& values) {
        ADIZZLE_ASSERT(index < 4, "Col index greater than col count.");

        for(size_t i = 0; i < 4; ++i) {
            data.at((4 * index) + i) = values.at(i);
        }
    }

    static constexpr auto identity() -> mat4 {
        auto mat = mat4{};

        for(size_t i = 0; i < 4; ++i) {
            for(size_t j = 0; j < 4; ++j) {
                if(i == j) {
                    mat(i, j) = 1.0f;
                }
            }
        }

        return mat;
    }

    static consteval auto from_row_major(const std::array<float, 16>& data) -> mat4 {
        auto mat = mat4{};

        for(size_t i = 0; i < 4; ++i) {
            for(size_t j = 0; j < 4; ++j) {
                auto data_idx = j + (4 * i);
                mat(i, j)     = data.at(data_idx);
            }
        }

        return mat;
    }
};

} // namespace admat