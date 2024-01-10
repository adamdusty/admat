#include <adizzle/float.hpp>
#include <admat/mat.hpp>
#include <snitch/snitch.hpp>

using namespace admat;

auto operator==(const vec4& lhs, const vec4& rhs) -> bool {
    return adizzle::almost_equal(lhs.w, rhs.w) && adizzle::almost_equal(lhs.x, rhs.x) &&
           adizzle::almost_equal(lhs.y, rhs.y) && adizzle::almost_equal(lhs.z, rhs.z);
}
auto operator==(const mat4& lhs, const mat4& rhs) -> bool {
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            if(!adizzle::almost_equal(lhs(i, j), rhs(i, j))) {
                return false;
            }
        }
    }

    return true;
}

TEST_CASE("mat4 initialization") {
    auto mat = mat4{};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(mat(i, j), 0.0f, 0.000001f));
        }
    }
}

TEST_CASE("mat4 identity") {
    auto ident = mat4::identity();

    auto expected = mat4{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    CHECK(ident == expected);
}

TEST_CASE("Matrix access") {
    auto mat = mat4{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    CHECK(adizzle::almost_equal(mat(0, 0), 1.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(0, 1), 2.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(0, 2), 3.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(0, 3), 4.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(1, 0), 5.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(1, 1), 6.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(1, 2), 7.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(1, 3), 8.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(2, 0), 9.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(2, 1), 10.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(2, 2), 11.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(2, 3), 12.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(3, 0), 13.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(3, 1), 14.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(3, 2), 15.0f, 0.00001f));
    CHECK(adizzle::almost_equal(mat(3, 3), 16.0f, 0.00001f));
}

TEST_CASE("mat4 addition") {
    auto m1 = mat4::identity();
    auto m2 = mat4::identity();

    auto actual   = m1 + m2;
    auto expected = mat4{
        {2, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 2},
    };

    CHECK(actual == expected);
}

TEST_CASE("mat4 subtraction") {
    auto m1 = mat4::identity();
    auto m2 = mat4{
        {2, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 2},
    };

    auto actual   = m2 - m1;
    auto expected = mat4{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    CHECK(actual == expected);
}

TEST_CASE("mat4 multiplication") {
    auto m1 = mat4{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    auto m2 = mat4{
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {1, 2, 3, 4},
    };

    auto expected = mat4{
        {66, 76, 86, 96},
        {178, 204, 230, 256},
        {290, 332, 374, 416},
        {402, 460, 518, 576},
    };

    auto actual = m1 * m2;
    CHECK(actual == expected);
}

TEST_CASE("mat4 * vec4") {
    auto mat = mat4::identity();
    auto vec = vec4{2.0f, 3.0f, 4.0f, 5.0f};

    auto expected = vec4{2.0f, 3.0f, 4.0f, 5.0f};

    auto actual = mat * vec;
    CHECK(actual == expected);

    actual = vec * mat;
    CHECK(actual == expected);
}

TEST_CASE("Matrix scalar multiplication") {
    auto mat = mat4{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    auto expected = mat4{
        {2, 4, 6, 8},
        {10, 12, 14, 16},
        {18, 20, 22, 24},
        {26, 28, 30, 32},
    };

    auto actual = 2.0f * mat;
    CHECK(actual == expected);

    actual = mat * 2.0f;
    CHECK(actual == expected);
}

TEST_CASE("mat4 determinant") {
    auto mat = mat4{
        {4, 3, 2, 1},
        {1, 4, 3, 2},
        {2, 1, 4, 3},
        {3, 2, 1, 4},
    };

    float expected = 160.0f;
    auto result    = determinant(mat);

    CHECK(adizzle::almost_equal(result, expected));
}

TEST_CASE("mat4 inverse") {
    auto mat = mat4{
        {1, 2, 2, 1},
        {2, 3, 4, 1},
        {2, 2, 1, 3},
        {2, 4, 3, 2},
    };

    auto expected = mat4{
        {-13, 4, 1, 3},
        {-2, -1, -1, 3},
        {6, 0, 0, -3},
        {8, -2, 1, -3},
    };
    expected = (1.0f / 3.0f) * expected;

    auto actual = inverse(mat);
    CHECK(actual == expected);
}

TEST_CASE("mat4 transpose") {
    auto mat = mat4{
        {1, 2, 3, 4},
        {4, 1, 3, 2},
        {3, 4, 1, 2},
        {2, 3, 4, 1},
    };

    auto expected = mat4{
        {1, 4, 3, 2},
        {2, 1, 4, 3},
        {3, 3, 1, 4},
        {4, 2, 2, 1},
    };

    auto actual = transpose(mat);
    CHECK(actual == expected);
}

TEST_CASE("translate") {
    auto expected = mat4{
        {1.0f, 0.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {0.0f, 0.0f, 1.0f, 1.0f},
        {0.0f, 0.0f, 0.0f, 1.0f},
    };

    auto actual = translation(vec3{1.0f, 1.0f, 1.0f});
    CHECK(actual == expected);

    actual = translation(1.0f, 1.0f, 1.0f);
    CHECK(actual == expected);
}

TEST_CASE("scale") {
    auto expected = mat4{
        {2.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 2.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 2.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f},
    };

    auto actual = scaling(vec3{2.0f, 2.0f, 2.0f});
    CHECK(actual == expected);
}

TEST_CASE("rotation") {
    auto expected = mat4{
        {0.603f, -.530f, 0.596f, 0.000f},
        {0.720f, 0.683f, -.122f, 0.000f},
        {-.342f, 0.503f, 0.794f, 0.000f},
        {0.000f, 0.000f, 0.000f, 1.000f},
    };

    auto actual = rotation(vec3{0.5236f, 0.7854f, 1.047f}, 1.0f);

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.001f));
        }
    }
}

TEST_CASE("Perspective FOV") {
    auto expected = mat4{
        {2.09928f, 0.00000f, 0.00000f, 0.000f},
        {0.00000f, -3.73205f, 0.00000f, 0.000f},
        {0.00000f, 0.00000f, 0.001502f, 1.50225f},
        {0.00000f, 0.00000f, -1.0f, 0.000f},
    };

    auto actual = perspective(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f);
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.0001f));
        }
    }
}

TEST_CASE("Orthographic") {
    auto expected = mat4{
        {0.02f, 0.00f, 0.00000000f, 0.0f},
        {0.00f, 0.01f, 0.00000000f, 0.0f},
        {0.00f, 0.00f, -0.00100150f, 0.0f},
        {0.00f, 0.00f, -0.00150225f, 1.0f},
    };

    auto actual = orthographic(100.0f, 200.0f, 1.5f, 1000.0f);
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.0001f));
        }
    }
}

TEST_CASE("Look at") {
    auto expected = mat4{
        {-1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, -1, -100},
        {0, 0, 0, 1},
    };

    auto actual = look_at({0, 0, -100}, {0, 0, 0}, {0, 1, 0});
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CAPTURE(i, j);
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.00001f));
        }
    }
}