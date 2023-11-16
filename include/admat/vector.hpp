#pragma once

#include <cstdint>

#include "admat/vector/operations.hpp"
#include "admat/vector/types.hpp"

namespace admat {

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;

using vec2i = vec<std::int32_t, 2>;
using vec3i = vec<std::int32_t, 3>;
using vec4i = vec<std::int32_t, 4>;

using vec2u = vec<std::uint32_t, 2>;
using vec3u = vec<std::uint32_t, 3>;
using vec4u = vec<std::uint32_t, 4>;

} // namespace admat