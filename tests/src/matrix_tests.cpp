#include <adizzle/float.hpp>
#include <admat/mat.hpp>
#include <snitch/snitch.hpp>

#include <algorithm>
#include <ranges>

using namespace admat;

TEST_CASE("mat4 initialization") {
    auto mat = mat4{};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(mat(i, j), 0.0f, 0.000001f));
        }
    }
}

TEST_CASE("mat4 identity") {
    auto ident    = mat4::identity();
    auto expected = mat4::from_row_major({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(ident(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 from row major array") {
    // clang-format off
    auto mat = mat4::from_row_major({
        1, 2, 3, 32,
        4, 5, 6, 32,
        7, 8, 9, 32,
        7, 8, 9, 32,
    });
    // clang-format on

    auto expected = mat4{{1, 4, 7, 7, 2, 5, 8, 8, 3, 6, 9, 9, 32, 32, 32, 32}};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(mat(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("Matrix access") {
    // clang-format off
    auto mat = mat4::from_row_major({
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,
    });
    // clang-format on

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
    auto expected = mat4{{2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2}};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 subtraction") {
    auto m1 = mat4::identity();
    auto m2 = mat4{{2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2}};

    auto actual   = m2 - m1;
    auto expected = mat4{{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 multiplication") {
    // clang-format off
    auto m1 = mat4::from_row_major({
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,
    });

    auto m2 = mat4::from_row_major({
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,
        1,  2,  3,  4,
    });

    auto expected = mat4::from_row_major({
        66,  76,  86,  96,
        178, 204, 230, 256,
        290, 332, 374, 416,
        402, 460, 518, 576,
    });
    // clang-format on

    auto actual = m1 * m2;

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 * vec4") {
    auto mat = mat4::identity();
    auto vec = vec4{2.0f, 3.0f, 4.0f, 5.0f};

    auto expected = vec4{2.0f, 3.0f, 4.0f, 5.0f};

    auto actual = mat * vec;

    CHECK(adizzle::almost_equal(actual.w, expected.w, 0.000001f));
    CHECK(adizzle::almost_equal(actual.x, expected.x, 0.000001f));
    CHECK(adizzle::almost_equal(actual.y, expected.y, 0.000001f));
    CHECK(adizzle::almost_equal(actual.z, expected.z, 0.000001f));

    actual = vec * mat;

    CHECK(adizzle::almost_equal(actual.w, expected.w, 0.000001f));
    CHECK(adizzle::almost_equal(actual.x, expected.x, 0.000001f));
    CHECK(adizzle::almost_equal(actual.y, expected.y, 0.000001f));
    CHECK(adizzle::almost_equal(actual.z, expected.z, 0.000001f));
}

TEST_CASE("mat4 get row") {
    auto mat = mat4::identity();

    CHECK(mat.row(0) == std::array<float, 4>{1, 0, 0, 0});
    CHECK(mat.row(1) == std::array<float, 4>{0, 1, 0, 0});
    CHECK(mat.row(2) == std::array<float, 4>{0, 0, 1, 0});
    CHECK(mat.row(3) == std::array<float, 4>{0, 0, 0, 1});
}

TEST_CASE("mat4 get col") {
    auto mat = mat4::identity();

    CHECK(mat.col(0) == std::array<float, 4>{1, 0, 0, 0});
    CHECK(mat.col(1) == std::array<float, 4>{0, 1, 0, 0});
    CHECK(mat.col(2) == std::array<float, 4>{0, 0, 1, 0});
    CHECK(mat.col(3) == std::array<float, 4>{0, 0, 0, 1});
}

TEST_CASE("mat4 set row") {
    auto mat = mat4::identity();
    mat.set_row(0, {1, 1, 1, 1});

    CHECK(mat.row(0) == std::array<float, 4>{1, 1, 1, 1});
    CHECK(mat.row(1) == std::array<float, 4>{0, 1, 0, 0});
    CHECK(mat.row(2) == std::array<float, 4>{0, 0, 1, 0});
    CHECK(mat.row(3) == std::array<float, 4>{0, 0, 0, 1});
}

TEST_CASE("mat4 set col") {
    auto mat = mat4::identity();
    mat.set_col(0, {1, 1, 1, 1});

    CHECK(mat.col(0) == std::array<float, 4>{1, 1, 1, 1});
    CHECK(mat.col(1) == std::array<float, 4>{0, 1, 0, 0});
    CHECK(mat.col(2) == std::array<float, 4>{0, 0, 1, 0});
    CHECK(mat.col(3) == std::array<float, 4>{0, 0, 0, 1});
}

TEST_CASE("Matrix scalar multiplication") {
    auto mat = mat4::from_row_major({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

    auto expected = mat4::from_row_major({2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32});

    auto actual = 2.0f * mat;
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }

    actual = mat * 2.0f;
    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 determinant") {
    // clang-format off
    auto mat = mat4::from_row_major({
        4, 3, 2, 1,
        1, 4, 3, 2,
        2, 1, 4, 3,
        3, 2, 1, 4,
    });
    // clang-format on

    float expected = 160.0f;
    auto result    = determinant(mat);

    CAPTURE(result); // Output value on failure
    CHECK(adizzle::almost_equal(result, expected, 0.00001f));
}

TEST_CASE("mat4 inverse") {
    // clang-format off
    auto mat = mat4::from_row_major({
        1, 2, 2, 1,
        2, 3, 4, 1,
        2, 2, 1, 3,
        2, 4, 3, 2,
    });

    auto expected = (1.0f / 3.0f) * mat4::from_row_major({
        -13, 4,  1,  3,
        -2, -1, -1,  3,
         6,  0,  0, -3,
         8, -2,  1, -3,
    });
    // clang-format on

    auto actual = inverse(mat);

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("mat4 transpose") {
    // clang-format off
    auto mat = mat4::from_row_major({
        1, 2, 3, 4,
        4, 1, 3, 2,
        3, 4, 1, 2,
        2, 3, 4, 1,
    });

    auto expected =  mat4::from_row_major({
        1, 4, 3, 2,
        2, 1, 4, 3,
        3, 3, 1, 4,
        4, 2, 2, 1,
    });
    // clang-format on

    auto actual = transpose(mat);

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("translate") {
    auto mat = mat4::identity();

    auto actual = translate(mat, vec3{1.0f, 1.0f, 1.0f});
    // clang-format off
    auto expected = mat4::from_row_major({
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("scale") {
    auto mat = mat4::identity();

    auto actual = scale(mat, vec3{2.0f, 2.0f, 2.0f});
    // clang-format off
    auto expected = mat4::from_row_major({
        2.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 2.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.000001f));
        }
    }
}

TEST_CASE("rotate") {
    auto mat = mat4::identity();

    auto actual = rotate(mat, vec3{0.5236f, 0.7854f, 1.047f}, 1.0f);

    // clang-format off
    auto expected = mat4::from_row_major({
        0.603f, -.530f, 0.596f, 0.000f,
        0.720f, 0.683f, -.122f, 0.000f,
        -.342f, 0.503f, 0.794f, 0.000f,
        0.000f, 0.000f, 0.000f, 1.000f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.001f));
        }
    }
}

TEST_CASE("Perspective FOV") {
    auto actual = perspective(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f);

    // clang-format off
    auto expected = mat4::from_row_major({
        2.09928f, 0.00000f,  0.00000f,  0.000f,
        0.00000f, 3.73205f,  0.00000f,  0.000f,
        0.00000f, 0.00000f, -1.00150f, -1.000f,
        0.00000f, 0.00000f, -1.50225f,  0.000f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.00001f));
        }
    }
}

TEST_CASE("Orthographic") {
    auto actual = orthographic(100.0f, 200.0f, 1.5f, 1000.0f);

    // clang-format off
    auto expected = mat4::from_row_major({
        0.02f, 0.00f,  0.00000000f,  0.0f,
        0.00f, 0.01f,  0.00000000f,  0.0f,
        0.00f, 0.00f, -0.00100150f,  0.0f,
        0.00f, 0.00f, -0.00150225f,  1.0f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.0001f));
        }
    }
}

TEST_CASE("Look at") {
    auto actual = look_at({10.0f, 20.0f, 30.0f}, {3.0f, 2.0f, -4.0f}, {0.0f, 1.0f, 0.0f});

    // clang-format off
    auto expected = mat4::from_row_major({
         0.979457f, -0.09282680f,  0.179017f,  0.0f,
         0.000000f,  0.88774800f,  0.460329f,  0.0f,
        -0.201653f, -0.45087300f,  0.869511f,  0.0f,
        -3.744980f, -3.30051000f, -37.08210f,  1.0f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(actual(i, j), expected(i, j), 0.00001f));
        }
    }
}