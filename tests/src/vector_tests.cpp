#include <admat/vector.hpp>
#include <snitch/snitch.hpp>

#include <cmath>

using namespace admat;

TEST_CASE("vec comparison", "[greeting]") {
    auto v1 = vec4{32.0f, 64.0f, 128.0f, 256.0f};
    auto v2 = vec4{32.0f, 64.0f, 128.0f, 256.0f};
    CHECK(v1 == v2);

    auto v3 = vec4{0.0f, 0.0f, 0.0f, 0.0f};
    auto v4 = vec4{0.0f, 0.0f, 1.0f, 0.0f};
    CHECK(v3 != v4);
}

TEST_CASE("vec + vec", "[operator+]") {
    auto v1 = vec4{1.0f, 1.0f, 1.0f, 1.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 + v2;

    CHECK(result == expected);
}

TEST_CASE("vec + scalar", "[operator+]") {
    auto v1     = vec4{1.0f, 1.0f, 1.0f, 1.0f};
    auto scalar = 1.0f;

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 + scalar;

    CHECK(result == expected);
}

TEST_CASE("vec - vec", "[operator-]") {
    auto v1 = vec4{3.0f, 3.0f, 3.0f, 3.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 - v2;

    CHECK(result == expected);
}

TEST_CASE("vec - scalar", "[operator-]") {
    auto v1 = vec4{3.0f, 3.0f, 3.0f, 3.0f};
    auto v2 = 1.0f;

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 - v2;

    CHECK(result == expected);
}

TEST_CASE("vec * scalar", "[operator-]") {
    auto v1 = vec4{3.0f, 3.0f, 3.0f, 3.0f};
    auto v2 = 2.0f;

    auto expected = vec4{6.0f, 6.0f, 6.0f, 6.0f};

    auto result = v1 * v2;
    CHECK(result == expected);

    result = v2 * v1;
    CHECK(result == expected);
}

TEST_CASE("vec / scalar", "[operator-]") {
    auto v1 = vec4{12.0f, 12.0f, 12.0f, 12.0f};
    auto v2 = 2.0f;

    auto expected = vec4{6.0f, 6.0f, 6.0f, 6.0f};

    auto result = v1 / v2;
    CHECK(result == expected);
}

TEST_CASE("vec dot product", "[dot]") {
    auto v1 = vec4{2.0f, -2.0f, 10.0f, 10.0f};
    auto v2 = vec4{10.0f, 5.0f, 2.0f, 1.0f};

    auto result = vector::dot(v1, v2);
    CHECK(result == 40);
}

TEST_CASE("vec cross product", "[cross]") {
    auto v1 = vec3{3.0f, 0.0f, 2.0f};
    auto v2 = vec3{-1.0f, 4.0f, 2.0f};

    auto expected = vec3{-8.0f, -8.0f, 12.0f};
    auto result   = vector::cross(v1, v2);

    CHECK(result == expected);
}

TEST_CASE("vec normalize") {
    auto v2 = vec2{10.0f, -10.0f};
    auto v3 = vec3{3.0f, 4.0f, 5.0f};
    auto v4 = vec4{5.0f, 10.0f, 15.0f, 20.0f};

    auto len2 = std::sqrt(10.0f * 10.0f + -10.0f * -10.0f);
    auto len3 = std::sqrt(3.0f * 3.0f + 4.0f * 4.0f + 5.0f * 5.0f);
    auto len4 = std::sqrt(5.0f * 5.0f + 10.0f * 10.0f + 15.0f * 15.0f + 20.0f * 20.0f);

    auto exp2 = vec2{v2.at(0) / len2, v2.at(1) / len2};
    auto exp3 = vec3{v3.at(0) / len3, v3.at(1) / len3, v3.at(2) / len3};
    auto exp4 = vec4{v4.at(0) / len4, v4.at(1) / len4, v4.at(2) / len4, v4.at(3) / len4};

    CHECK(vector::normalize(v2) == exp2);
    CHECK(vector::normalize(v3) == exp3);
    CHECK(vector::normalize(v4) == exp4);
}