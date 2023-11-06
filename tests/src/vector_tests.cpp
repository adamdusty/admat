#include <admat/vector/operations.hpp>
#include <admat/vector/types.hpp>
#include <snitch/snitch.hpp>

using namespace admat;

TEST_CASE("Vec2 comparison", "[greeting]") {

    auto v1 = vec2{32.0f, 64.0f};
    auto v2 = vec2{32.0f, 64.0f};
    CHECK(v1 == v2);

    auto v3 = vec2{0.0f, 0.0f};
    auto v4 = vec2{1.0f, 1.0f};
    CHECK(v3 != v4);
}

TEST_CASE("Vec3 comparison", "[greeting]") {
    auto v1 = vec3{32.0f, 64.0f, 128.0f};
    auto v2 = vec3{32.0f, 64.0f, 128.0f};
    CHECK(v1 == v2);

    auto v3 = vec3{0.0f, 0.0f, 0.0f};
    auto v4 = vec3{0.0f, 0.0f, 1.0f};
    CHECK(v3 != v4);
}

TEST_CASE("Vec4 comparison", "[greeting]") {
    auto v1 = vec4{32.0f, 64.0f, 128.0f, 256.0f};
    auto v2 = vec4{32.0f, 64.0f, 128.0f, 256.0f};
    CHECK(v1 == v2);

    auto v3 = vec4{0.0f, 0.0f, 0.0f, 0.0f};
    auto v4 = vec4{0.0f, 0.0f, 1.0f, 0.0f};

    CHECK(v3 != v4);
}

TEST_CASE("Vector addition", "[operator+]") {
    auto v1 = vec4{1.0f, 1.0f, 1.0f, 1.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 + v2;

    CHECK(result == expected);
}