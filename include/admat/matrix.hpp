#pragma once

#include "admat/matrix/operations.hpp"
#include "admat/matrix/types.hpp"

namespace admat {

using mat3 = matrix::column_major_matrix<float, 3, 3>;
using mat4 = matrix::column_major_matrix<float, 4, 4>;

} // namespace admat