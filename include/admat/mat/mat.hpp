#pragma once

#include "admat/vec.hpp"
#include <adizzle/assert.hpp>
#include <algorithm>
#include <array>
#include <cstddef>
#include <format>
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

constexpr auto operator+(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto result = mat4{};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            result(i, j) = lhs(i, j) + rhs(i, j);
        }
    }

    return result;
}

constexpr auto operator-(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto result = mat4{};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            result(i, j) = lhs(i, j) - rhs(i, j);
        }
    }

    return result;
}

constexpr auto operator*(const mat4& lhs, const mat4& rhs) -> mat4 {
    auto m0 = vec4::from_array(lhs.col(0));
    auto m1 = vec4::from_array(lhs.col(1));
    auto m2 = vec4::from_array(lhs.col(2));
    auto m3 = vec4::from_array(lhs.col(3));

    auto n0 = vec4::from_array(rhs.col(0));
    auto n1 = vec4::from_array(rhs.col(1));
    auto n2 = vec4::from_array(rhs.col(2));
    auto n3 = vec4::from_array(rhs.col(3));

    auto r0 = (m0 * n0.w + m1 * n0.x + m2 * n0.y + m3 * n0.z);
    auto r1 = (m0 * n1.w + m1 * n1.x + m2 * n1.y + m3 * n1.z);
    auto r2 = (m0 * n2.w + m1 * n2.x + m2 * n2.y + m3 * n2.z);
    auto r3 = (m0 * n3.w + m1 * n3.x + m2 * n3.y + m3 * n3.z);

    auto result = mat4{};

    result.set_col(0, r0);
    result.set_col(1, r1);
    result.set_col(2, r2);
    result.set_col(3, r3);

    return result;
}

constexpr auto operator*(mat4 lhs, float scalar) -> mat4 {
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            lhs(i, j) *= scalar;
        }
    }

    return lhs;
}

constexpr auto operator*(float scalar, mat4 rhs) -> mat4 {
    return rhs * scalar;
}

constexpr auto operator*(const mat4& mat, const vec4& vec) -> vec4 {
    return vec4{
        .w = mat(0, 0) * vec.w + mat(0, 1) * vec.x + mat(0, 2) * vec.y + mat(0, 3) * vec.z,
        .x = mat(1, 0) * vec.w + mat(1, 1) * vec.x + mat(1, 2) * vec.y + mat(1, 3) * vec.z,
        .y = mat(2, 0) * vec.w + mat(2, 1) * vec.x + mat(2, 2) * vec.y + mat(2, 3) * vec.z,
        .z = mat(3, 0) * vec.w + mat(3, 1) * vec.x + mat(3, 2) * vec.y + mat(3, 3) * vec.z,
    };
}

constexpr auto operator*(const vec4& vec, const mat4& mat) -> vec4 {
    return mat * vec;
}

} // namespace admat