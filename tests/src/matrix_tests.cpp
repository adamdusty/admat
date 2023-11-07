#include <admat/matrix.hpp>
#include <snitch/snitch.hpp>

#include <cmath>

using namespace admat;

TEST_CASE("mat4 identity") {
    auto ident    = mat4::identity();
    auto expected = mat4{{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};

    CHECK(ident == expected);
}

TEST_CASE("mat3 identity") {
    auto ident    = mat3::identity();
    auto expected = mat3{{1, 0, 0, 0, 1, 0, 0, 0, 1}};

    CHECK(ident == expected);
}