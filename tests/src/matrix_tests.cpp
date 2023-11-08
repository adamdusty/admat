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

TEST_CASE("Matrix access") {
    auto ident = mat3::identity();

    CHECK(ident.at(1, 1) == 1);
    CHECK(ident.at(1, 2) == 0);
    CHECK(ident.at(1, 3) == 0);
    CHECK(ident.at(2, 1) == 0);
    CHECK(ident.at(2, 2) == 1);
    CHECK(ident.at(2, 3) == 0);
    CHECK(ident.at(3, 1) == 0);
    CHECK(ident.at(3, 2) == 0);
    CHECK(ident.at(3, 3) == 1);
}

TEST_CASE("Matrix addition") {
    auto m1       = mat3::identity();
    auto m2       = mat3::identity();
    auto expected = mat3{{2, 0, 0, 0, 2, 0, 0, 0, 2}};

    CHECK(m1 + m2 == expected);
}