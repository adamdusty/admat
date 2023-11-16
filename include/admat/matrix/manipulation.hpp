#pragma once

#include "admat/matrix/types.hpp"
#include <cmath>
#include <concepts>

namespace admat {

template<std::floating_point T>
constexpr auto perspective(T fov, T aspect, T near, T far) -> column_major_matrix<T, 4, 4> {
    fov = std::tan(fov / static_cast<T>(2));

    auto mat = column_major_matrix<T, 4, 4>{};

    mat.at(0, 0) = static_cast<T>(1) / (aspect * fov);
    mat.at(1, 1) = static_cast<T>(1) / (fov);
    mat.at(2, 2) = far / (far - near);
    mat.at(2, 3) = static_cast<T>(1);
    mat.at(3, 2) = -(far * near) / (far - near);

    return mat;
}

} // namespace admat