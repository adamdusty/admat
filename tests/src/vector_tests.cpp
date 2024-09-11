#include "utils.hpp"
#include <admat/vec.hpp>
#include <snitch/snitch.hpp>

#include <cmath>

using namespace admat;

TEST_CASE("vec2 addition", "[operator+]") {
    auto v1 = vec2{1.0f, 1.0f};
    auto v2 = vec2{1.0f, 1.0f};

    auto expected = vec2{2.0f, 2.0f};
    auto result   = v1 + v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 addition", "[operator+]") {
    auto v1 = vec3{1.0f, 1.0f, 1.0f};
    auto v2 = vec3{1.0f, 1.0f, 1.0f};

    auto expected = vec3{2.0f, 2.0f, 2.0f};
    auto result   = v1 + v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 addition", "[operator+]") {
    auto v1 = vec4{1.0f, 1.0f, 1.0f, 1.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{2.0f, 2.0f, 2.0f, 2.0f};
    auto result   = v1 + v2;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 subtraction", "[operator-]") {
    auto v1 = vec2{5.0f, 3.0f};
    auto v2 = vec2{1.0f, 1.0f};

    auto expected = vec2{4.0f, 2.0f};
    auto result   = v1 - v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 subtraction", "[operator-]") {
    auto v1 = vec3{5.0f, 4.0f, 3.0f};
    auto v2 = vec3{1.0f, 1.0f, 1.0f};

    auto expected = vec3{4.0f, 3.0f, 2.0f};
    auto result   = v1 - v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 subtraction", "[operator-]") {
    auto v1 = vec4{9.0f, 8.0f, 7.0f, 6.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{8.0f, 7.0f, 6.0f, 5.0f};
    auto result   = v1 - v2;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 multiplication", "[operator*]") {
    auto v1 = vec2{1.0f, 2.0f};
    auto v2 = vec2{1.0f, 1.0f};

    auto expected = vec2{1.0f, 2.0f};
    auto result   = v1 * v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 multiplication", "[operator*]") {
    auto v1 = vec3{5.0f, 4.0f, 3.0f};
    auto v2 = vec3{1.0f, 1.0f, 1.0f};

    auto expected = vec3{5.0f, 4.0f, 3.0f};
    auto result   = v1 * v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 multiplication", "[operator*]") {
    auto v1 = vec4{9.0f, 8.0f, 7.0f, 6.0f};
    auto v2 = vec4{1.0f, 1.0f, 1.0f, 1.0f};

    auto expected = vec4{9.0f, 8.0f, 7.0f, 6.0f};
    auto result   = v1 * v2;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 division", "[operator/]") {
    auto v1 = vec2{8.0f, 9.0f};
    auto v2 = vec2{2.0f, 3.0f};

    auto expected = vec2{4.0f, 3.0f};
    auto result   = v1 / v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 division", "[operator/]") {
    auto v1 = vec3{12.0f, 8.0f, 5.0f};
    auto v2 = vec3{4.0f, 2.0f, 1.0f};

    auto expected = vec3{3.0f, 4.0f, 5.0f};
    auto result   = v1 / v2;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 division", "[operator/]") {
    auto v1 = vec4{9.0f, 8.0f, 7.0f, 6.0f};
    auto v2 = vec4{3.0f, 2.0f, 1.0f, 3.0f};

    auto expected = vec4{3.0f, 4.0f, 7.0f, 2.0f};
    auto result   = v1 / v2;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 + scalar", "[operator+]") {
    auto vec    = vec2{1.0f, 2.0f};
    auto scalar = 1.0f;

    auto expected = vec2{2.0f, 3.0f};
    auto result   = vec + scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 + scalar", "[operator+]") {
    auto vec    = vec3{1.0f, 2.0f, 3.0f};
    auto scalar = 1.0f;

    auto expected = vec3{2.0f, 3.0f, 4.0f};
    auto result   = vec + scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 + scalar", "[operator+]") {
    auto vec    = vec4{1.0f, 2.0f, 3.0f, 4.0f};
    auto scalar = 1.0f;

    auto expected = vec4{2.0f, 3.0f, 4.0f, 5.0f};
    auto result   = vec + scalar;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 - scalar", "[operator-]") {
    auto vec    = vec2{1.0f, 2.0f};
    auto scalar = 1.0f;

    auto expected = vec2{0.0f, 1.0f};
    auto result   = vec - scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 - scalar", "[operator-]") {
    auto vec    = vec3{1.0f, 2.0f, 3.0f};
    auto scalar = 1.0f;

    auto expected = vec3{0.0f, 1.0f, 2.0f};
    auto result   = vec - scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 - scalar", "[operator-]") {
    auto vec    = vec4{1.0f, 2.0f, 3.0f, 4.0f};
    auto scalar = 1.0f;

    auto expected = vec4{0.0f, 1.0f, 2.0f, 3.0f};
    auto result   = vec - scalar;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 * scalar", "[operator*]") {
    auto vec    = vec2{1.0f, 2.0f};
    auto scalar = 2.0f;

    auto expected = vec2{2.0f, 4.0f};
    auto result   = vec * scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 * scalar", "[operator*]") {
    auto vec    = vec3{1.0f, 2.0f, 3.0f};
    auto scalar = 2.0f;

    auto expected = vec3{2.0f, 4.0f, 6.0f};
    auto result   = vec * scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 * scalar", "[operator*]") {
    auto vec    = vec4{1.0f, 2.0f, 3.0f, 4.0f};
    auto scalar = 2.0f;

    auto expected = vec4{2.0f, 4.0f, 6.0f, 8.0f};
    auto result   = vec * scalar;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 / scalar", "[operator/]") {
    auto vec    = vec2{8.0f, 6.0f};
    auto scalar = 2.0f;

    auto expected = vec2{4.0f, 3.0f};
    auto result   = vec / scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 / scalar", "[operator/]") {
    auto vec    = vec3{8.0f, 6.0f, 4.0f};
    auto scalar = 2.0f;

    auto expected = vec3{4.0f, 3.0f, 2.0f};
    auto result   = vec / scalar;

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 / scalar", "[operator/]") {
    auto vec    = vec4{8.0f, 7.0f, 6.0f, 5.0f};
    auto scalar = 2.0f;

    auto expected = vec4{4.0f, 3.5f, 3.0f, 2.5f};
    auto result   = vec / scalar;

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 dot product", "[dot]") {
    auto v1 = vec2{2.0f, -2.0f};
    auto v2 = vec2{10.0f, 5.0f};

    auto result = dot(v1, v2);
    CHECK(almost_equal(result, 10.0f, 0.00001f));
}

TEST_CASE("vec3 dot product", "[dot]") {
    auto v1 = vec3{2.0f, -2.0f, 4.0f};
    auto v2 = vec3{10.0f, 5.0f, 3.0f};

    auto result = dot(v1, v2);
    CHECK(almost_equal(result, 22.0f, 0.00001f));
}

TEST_CASE("vec4 dot product", "[dot]") {
    auto v1 = vec4{2.0f, -2.0f, 4.0f, 2.0f};
    auto v2 = vec4{10.0f, 5.0f, 3.0f, 6.0f};

    auto result = dot(v1, v2);
    CHECK(almost_equal(result, 34.0f, 0.00001f));
}

TEST_CASE("vec3 cross product", "[cross]") {
    auto v1 = vec3{3.0f, 0.0f, 2.0f};
    auto v2 = vec3{-1.0f, 4.0f, 2.0f};

    auto expected = vec3{-8.0f, -8.0f, 12.0f};
    auto result   = cross(v1, v2);

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 magnitude", "[magnitude]") {
    auto vec = vec2{3.0f, 4.0f};

    auto result = magnitude(vec);

    CHECK(almost_equal(result, 5.0f, 0.000001f));
}

TEST_CASE("vec3 magnitude", "[magnitude]") {
    auto vec = vec3{2.0f, 4.0f, -2.0f};

    auto result = magnitude(vec);

    CHECK(almost_equal(result, 2.0f * std::sqrt(6.0f), 0.000001f));
}

TEST_CASE("vec4 magnitude", "[magnitude]") {
    auto vec = vec4{1.0f, 2.0f, 3.0f, 4.0f};

    auto result = magnitude(vec);

    CHECK(almost_equal(result, std::sqrt(30.0f), 0.000001f));
}

TEST_CASE("vec normalize") {
    auto v2 = vec2{10.0f, -10.0f};
    auto v3 = vec3{3.0f, 4.0f, 5.0f};
    auto v4 = vec4{5.0f, 10.0f, 15.0f, 20.0f};

    auto len2 = std::sqrt(10.0f * 10.0f + -10.0f * -10.0f);
    auto len3 = std::sqrt(3.0f * 3.0f + 4.0f * 4.0f + 5.0f * 5.0f);
    auto len4 = std::sqrt(5.0f * 5.0f + 10.0f * 10.0f + 15.0f * 15.0f + 20.0f * 20.0f);

    auto exp2 = vec2{v2.x / len2, v2.y / len2};
    auto exp3 = vec3{v3.x / len3, v3.y / len3, v3.z / len3};
    auto exp4 = vec4{v4.w / len4, v4.x / len4, v4.y / len4, v4.z / len4};

    auto res2 = normalize(v2);
    auto res3 = normalize(v3);
    auto res4 = normalize(v4);

    CHECK(almost_equal(res2.x, exp2.x, 0.000001f));
    CHECK(almost_equal(res2.y, exp2.y, 0.000001f));

    CHECK(almost_equal(res3.x, exp3.x, 0.000001f));
    CHECK(almost_equal(res3.y, exp3.y, 0.000001f));
    CHECK(almost_equal(res3.z, exp3.z, 0.000001f));

    CHECK(almost_equal(res4.w, exp4.w, 0.000001f));
    CHECK(almost_equal(res4.x, exp4.x, 0.000001f));
    CHECK(almost_equal(res4.y, exp4.y, 0.000001f));
    CHECK(almost_equal(res4.z, exp4.z, 0.000001f));
}

TEST_CASE("vec2 abs") {
    auto vec      = vec2{-0.3f, -15.6f};
    auto expected = vec2{0.3f, 15.6f};

    auto result = abs(vec);

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 abs") {
    auto vec      = vec3{-0.3f, -15.6f, -32.3f};
    auto expected = vec3{0.3f, 15.6f, 32.3f};

    auto result = abs(vec);

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 abs") {
    auto vec      = vec4{-0.3f, -15.6f, -32.3f, 86.9f};
    auto expected = vec4{0.3f, 15.6f, 32.3f, 86.9f};

    auto result = abs(vec);

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 clamp") {
    auto vec      = vec2{0.5f, -0.5f};
    auto expected = vec2{0.75f, -1.0f};

    auto result = clamp(vec * 100.0f, -1.0f, 0.75f);

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec3 clamp") {
    auto vec      = vec3{0.5f, 0.5f, -0.52f};
    auto expected = vec3{0.75f, 0.75f, -1.0f};

    auto result = clamp(vec * 100.0f, -1.0f, 0.75f);

    CAPTURE(vec.z);
    CAPTURE(result.z);

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec4 clamp") {
    auto vec      = vec4{0.5f, 0.5f, -0.52f, 0.0001f};
    auto expected = vec4{0.75f, 0.75f, -1.0f, 0.01f};

    auto result = clamp(vec * 100.0f, -1.0f, 0.75f);

    CHECK(almost_equal(result.w, expected.w, 0.000001f));
    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 distance") {
    auto v1 = vec2{1.0f, 2.0f};
    auto v2 = vec2{-55.0f, -73.0f};

    auto result   = distance(v1, v2);
    auto expected = 93.6002f;

    CHECK(almost_equal(result, expected, 0.0001f));
}

TEST_CASE("vec3 distance") {
    auto v1 = vec3{1.0f, 2.0f, 3.0f};
    auto v2 = vec3{-55.0f, -73.0f, 22.0f};

    auto result   = distance(v1, v2);
    auto expected = 95.5091f;

    CHECK(almost_equal(result, expected, 0.0001f));
}

TEST_CASE("vec4 distance") {
    auto v1 = vec4{1.0f, 2.0f, 3.0f, 4.0f};
    auto v2 = vec4{-55.0f, -73.0f, 22.0f, 14.0f};

    auto result   = distance(v1, v2);
    auto expected = 96.0312f;

    CHECK(almost_equal(result, expected, 0.0001f));
}

TEST_CASE("vec reflect") {
    auto inc  = vec2{1.0f, 1.0f};
    auto surf = vec2{0.0f, 1.0f};

    auto result   = reflect(inc, surf);
    auto expected = vec2{1.0f, -1.0f};

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
}

TEST_CASE("vec reflect") {
    auto inc  = vec3{1.0f, 1.0f, 0.0f};
    auto surf = vec3{0.0f, 1.0f, 0.0f};

    auto result   = reflect(inc, surf);
    auto expected = vec3{1.0f, -1.0f, 0.0f};

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec refract") {
    auto inc  = vec3{1.0f, 1.0f, 0.0f};
    auto surf = vec3{0.0f, 1.0f, 0.0f};

    auto result   = refract(inc, surf, 0.5f);
    auto expected = vec3{0.5f, -1.0f, 0.0f};

    CHECK(almost_equal(result.x, expected.x, 0.000001f));
    CHECK(almost_equal(result.y, expected.y, 0.000001f));
    CHECK(almost_equal(result.z, expected.z, 0.000001f));
}

TEST_CASE("vec2 lerp") {
    auto from = vec2{1.0f, 1.0f};
    auto to   = vec2{2.0f, 5.0f};

    auto quarter_lerp = lerp(from, to, 0.25f);
    auto half_lerp    = lerp(from, to, 0.5f);

    CHECK(almost_equal(quarter_lerp.x, 1.25f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.y, 2.00f, 0.000001f));

    CHECK(almost_equal(half_lerp.x, 1.5f, 0.000001f));
    CHECK(almost_equal(half_lerp.y, 3.0f, 0.000001f));
}

TEST_CASE("vec3 lerp") {
    auto from = vec3{1.0f, 1.0f, 1.0f};
    auto to   = vec3{2.0f, 5.0f, 9.0f};

    auto quarter_lerp = lerp(from, to, 0.25f);
    auto half_lerp    = lerp(from, to, 0.5f);

    CHECK(almost_equal(quarter_lerp.x, 1.25f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.y, 2.00f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.z, 3.00f, 0.000001f));

    CHECK(almost_equal(half_lerp.x, 1.5f, 0.000001f));
    CHECK(almost_equal(half_lerp.y, 3.0f, 0.000001f));
    CHECK(almost_equal(half_lerp.z, 5.0f, 0.000001f));
}

TEST_CASE("vec4 lerp") {
    auto from = vec4{1.0f, 1.0f, 1.0f, 1.0f};
    auto to   = vec4{2.0f, 5.0f, 9.0f, 1.0f};

    auto quarter_lerp = lerp(from, to, 0.25f);
    auto half_lerp    = lerp(from, to, 0.5f);

    CHECK(almost_equal(quarter_lerp.w, 1.25f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.x, 2.00f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.y, 3.00f, 0.000001f));
    CHECK(almost_equal(quarter_lerp.z, 1.00f, 0.000001f));

    CHECK(almost_equal(half_lerp.w, 1.5f, 0.000001f));
    CHECK(almost_equal(half_lerp.x, 3.0f, 0.000001f));
    CHECK(almost_equal(half_lerp.y, 5.0f, 0.000001f));
    CHECK(almost_equal(half_lerp.z, 1.0f, 0.000001f));
}