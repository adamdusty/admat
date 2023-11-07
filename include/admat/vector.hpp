#pragma once

#include <cstdint>

#include "admat/vector/operations.hpp"
#include "admat/vector/types.hpp"

namespace admat {

using vec2 = vector::vec<float, 2>;
using vec3 = vector::vec<float, 3>;
using vec4 = vector::vec<float, 4>;

using vec2i = vector::vec<std::int32_t, 2>;
using vec3i = vector::vec<std::int32_t, 3>;
using vec4i = vector::vec<std::int32_t, 4>;

using vec2u = vector::vec<std::uint32_t, 2>;
using vec3u = vector::vec<std::uint32_t, 3>;
using vec4u = vector::vec<std::uint32_t, 4>;

} // namespace admat