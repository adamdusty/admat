#include <adizzle/float.hpp>
#include <admat/matrix.hpp>
#include <admat/vector.hpp>
#include <snitch/snitch.hpp>

using namespace admat;

TEST_CASE("Matrix initialization") {
    auto mat = mat4{};

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CHECK(adizzle::almost_equal(mat.at(i, j), 0.0f));
        }
    }
}

TEST_CASE("mat4 identity") {
    auto ident    = mat4::identity();
    auto expected = mat4{{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    CHECK(ident == expected);
}

TEST_CASE("Matrix from row major array") {
    // clang-format off
    auto m1 = mat3::from_row_major({
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    });
    // clang-format on

    auto expected = mat3{{1, 4, 7, 2, 5, 8, 3, 6, 9}};

    CHECK(m1 == expected);
}

TEST_CASE("Matrix from row major array non-square") {
    // clang-format off
    auto m1 = column_major_matrix<float, 2, 3>::from_row_major({
        1, 2, 3,
        4, 5, 6,
    });
    // clang-format on

    auto expected = column_major_matrix<float, 2, 3>{{1, 4, 2, 5, 3, 6}};

    CHECK(m1 == expected);
}

TEST_CASE("mat3 identity") {
    auto ident    = mat3::identity();
    auto expected = mat3{{1, 0, 0, 0, 1, 0, 0, 0, 1}};

    CHECK(ident == expected);
}

TEST_CASE("Matrix access") {
    auto mat = mat3{{1, 4, 7, 2, 5, 8, 3, 6, 9}};

    CHECK(adizzle::almost_equal(mat.at(0, 0), 1.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 1), 2.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 2), 3.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 0), 4.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 1), 5.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 2), 6.0f));
    CHECK(adizzle::almost_equal(mat.at(2, 0), 7.0f));
    CHECK(adizzle::almost_equal(mat.at(2, 1), 8.0f));
    CHECK(adizzle::almost_equal(mat.at(2, 2), 9.0f));
}

TEST_CASE("Matrix access non-square") {
    auto mat = column_major_matrix<float, 2, 3>{{1, 4, 2, 5, 3, 6}};

    CHECK(adizzle::almost_equal(mat.at(0, 0), 1.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 1), 2.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 2), 3.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 0), 4.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 1), 5.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 2), 6.0f));
}

TEST_CASE("Matrix get row") {
    auto mat = mat3::identity();

    CHECK(mat.row(0) == std::array<float, 3>{1, 0, 0});
    CHECK(mat.row(1) == std::array<float, 3>{0, 1, 0});
    CHECK(mat.row(2) == std::array<float, 3>{0, 0, 1});
}

TEST_CASE("Matrix get column") {
    // clang-format off
    auto mat = column_major_matrix<float, 2, 3>::from_row_major({
        2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f,
    });
    // clang-format on

    CHECK(mat.col(0) == std::array<float, 2>{2.0f, 5.0f});
    CHECK(mat.col(1) == std::array<float, 2>{3.0f, 6.0f});
    CHECK(mat.col(2) == std::array<float, 2>{4.0f, 7.0f});
}

TEST_CASE("Matrix set row") {
    auto mat = mat3::identity();
    mat.set_row(0, {1, 1, 1});

    CHECK(mat.row(0) == std::array<float, 3>{1, 1, 1});
    CHECK(mat.row(1) == std::array<float, 3>{0, 1, 0});
    CHECK(mat.row(2) == std::array<float, 3>{0, 0, 1});
}

TEST_CASE("Matrix set col") {
    auto mat = mat3::identity();
    mat.set_col(0, {1, 1, 1});

    CHECK(mat.col(0) == std::array<float, 3>{1, 1, 1});
    CHECK(mat.col(1) == std::array<float, 3>{0, 1, 0});
    CHECK(mat.col(2) == std::array<float, 3>{0, 0, 1});
}

TEST_CASE("Matrix set row") {
    auto mat = mat3::identity();
    mat.swap_rows(0, 1);

    CHECK(mat.row(0) == std::array<float, 3>{0, 1, 0});
    CHECK(mat.row(1) == std::array<float, 3>{1, 0, 0});
    CHECK(mat.row(2) == std::array<float, 3>{0, 0, 1});
}

TEST_CASE("Matrix addition") {
    auto m1       = mat3::identity();
    auto m2       = mat3::identity();
    auto expected = mat3{{2, 0, 0, 0, 2, 0, 0, 0, 2}};

    CHECK(m1 + m2 == expected);
}

TEST_CASE("Matrix subtraction") {
    auto m1       = mat3{{1, 4, 7, 2, 5, 8, 3, 6, 9}};
    auto m2       = mat3{{1, 4, 7, 2, 5, 8, 3, 6, 9}};
    auto expected = mat3{{0, 0, 0, 0, 0, 0, 0, 0, 0}};

    CHECK(m1 - m2 == expected);
}

TEST_CASE("Matrix multiplication") {
    // clang-format off
    auto m1 = mat3::from_row_major({
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    });

    auto m2 = mat3::from_row_major({
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    });

    auto expected = mat3::from_row_major({
         30,  36,  42,
         66,  81,  96,
        102, 126, 150,
    });
    // clang-format on

    auto result = m1 * m2;

    CHECK(result == expected);
}

TEST_CASE("Matrix multiplication non-square") {
    // clang-format off
    auto m1 = column_major_matrix<float, 3, 2>::from_row_major({
        1, 2,
        3, 4,
        5, 6,
    });

    auto m2 = column_major_matrix<float, 2, 3>::from_row_major({
        6, 5, 4,
        3, 2, 1,
    });

    auto expected = mat3::from_row_major({
        12,  9,  6,
        30, 23, 16,
        48, 37, 26,
    });
    // clang-format on

    auto result = m1 * m2;

    CHECK(result == expected);
}

TEST_CASE("4x4 Matrix multiplication") {
    // clang-format off
    auto m1 = mat4::from_row_major({
        1, 2, 3, 0,
        4, 5, 6, 0,
        7, 8, 9, 0,
        0, 0, 0, 0,
    });

    auto m2 = mat4::from_row_major({
        1, 2, 3, 0,
        4, 5, 6, 0,
        7, 8, 9, 0,
        0, 0, 0, 0,
    });

    auto expected = mat4::from_row_major({
         30,  36,  42, 0,
         66,  81,  96, 0,
        102, 126, 150, 0,
          0,   0,   0, 0, 
    });
    // clang-format on

    auto result = m1 * m2;

    CHECK(result == expected);
}

TEST_CASE("Matrix scalar multiplication") {
    auto mat = mat3::from_row_major({1, 2, 3, 4, 5, 6, 7, 8, 9});

    auto expected = mat3::from_row_major({2, 4, 6, 8, 10, 12, 14, 16, 18});
    auto result   = 2.0f * mat;

    CHECK(result == expected);

    result = mat * 2.0f;
    CHECK(result == expected);
}

TEST_CASE("2x2 matrix determinant") {
    // clang-format off
    auto mat = column_major_matrix<float, 2, 2>::from_row_major({
        7, 1,
        2, 4,
    });
    // clang-format on

    float expected = 26.0f;
    auto result    = determinant(mat);

    CAPTURE(result); // Output value on failure
    CHECK(adizzle::almost_equal(result, expected));
}

TEST_CASE("3x3 matrix determinant") {
    // clang-format off
    auto mat = mat3::from_row_major({
        7, 1, 3,
        2, 4, 1,
        1, 5, 1,
    });
    // clang-format on

    float expected = 10.0f;
    auto result    = determinant(mat);

    CAPTURE(result); // Output value on failure
    CHECK(adizzle::almost_equal(result, expected));
}

TEST_CASE("4x4 matrix determinant") {
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
    CHECK(adizzle::almost_equal(result, expected));
}

TEST_CASE("3x3 matrix lu decomp") {
    // clang-format off
    auto mat = mat3::from_row_major({
        1,  1,  0,
        2,  1, -1,
        3, -1, -1,
    });
    
    auto expected_lower = mat3::from_row_major({
        1, 0, 0,
        2, 1, 0,
        3, 4, 1,
    });
    
    auto expected_upper = mat3::from_row_major({
        1,  1,  0,
        0, -1, -1,
        0,  0,  3,
    });
    // clang-format on

    auto [lower, upper] = decompose(mat);

    CHECK(lower == expected_lower);
    CHECK(upper == expected_upper);
}

TEST_CASE("2x2 matrix inverse") {
    // clang-format off
    auto mat = mat2::from_row_major({
        1, 2,
        3, 2,
    });

    auto expected = (1.0f / 4.0f) * mat2::from_row_major({
        -2,  2,
         3, -1,
    });
    // clang-format on

    auto result = inverse(mat);

    CHECK(result == expected);
}

TEST_CASE("3x3 matrix inverse") {
    // clang-format off
    auto mat = mat3::from_row_major({
        1, 2, 3,
        3, 2, 1,
        2, 1, 3,
    });

    auto expected = (1.0f / 12.0f) * mat3::from_row_major({
        -5,  3,  4,
         7,  3, -8,
         1, -3,  4,
    });
    // clang-format on

    auto result = inverse(mat);

    CHECK(result == expected);
}

TEST_CASE("4x4 matrix inverse") {
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

    auto result = inverse(mat);

    CHECK(result == expected);
}

TEST_CASE("2x2 matrix transpose") {
    // clang-format off
    auto mat = mat2::from_row_major({
        1, 2,
        3, 4,
    });

    auto expected = mat2::from_row_major({
        1, 3,
        2, 4,
    });
    // clang-format on

    auto result = transpose(mat);

    CHECK(result == expected);
}

TEST_CASE("3x3 matrix transpose") {
    // clang-format off
    auto mat = mat3::from_row_major({
        1, 2, 3,
        4, 1, 5,
        6, 7, 1,
    });

    auto expected = mat3::from_row_major({
        1, 4, 6,
        2, 1, 7,
        3, 5, 1,
    });
    // clang-format on

    auto result = transpose(mat);

    CHECK(result == expected);
}

TEST_CASE("4x4 matrix transpose") {
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

    auto result = transpose(mat);

    CHECK(result == expected);
}

TEST_CASE("2x3 matrix transpose") {
    // clang-format off
    auto mat = column_major_matrix<float, 2, 3>::from_row_major({
        1, 2, 3,
        4, 1, 3,
    });

    auto expected =  column_major_matrix<float, 3, 2>::from_row_major({
        1, 4, 
        2, 1,
        3, 3,
    });
    // clang-format on

    auto result = transpose(mat);

    CHECK(result == expected);
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

    CHECK(actual == expected);
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

    CHECK(actual == expected);
}

TEST_CASE("rotate") {
    // RESOURCE: https://www.cs.usfca.edu/~galles/visualization/RotateScale3D.html
    auto mat = mat4::identity();

    auto actual = rotate(mat, vec3{0.5236f, 0.7854f, 1.047f});
    // clang-format off
    auto expected = mat4::from_row_major({
        0.354f, -.573f, -.739f, 0.000f,
        0.612f, 0.739f, -.280f, 0.000f,
        0.707f, -.353f, 0.612f, 0.000f,
        0.000f, 0.000f, 0.000f, 1.000f
    });
    // clang-format on

    for(size_t i = 0; i < 4; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            CAPTURE(actual.at(i, j));
            CAPTURE(expected.at(i, j));
            CHECK(adizzle::almost_equal(actual.at(i, j), expected.at(i, j), 0.001f));
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
            CAPTURE(actual.at(i, j));
            CAPTURE(expected.at(i, j));
            CHECK(adizzle::almost_equal(actual.at(i, j), expected.at(i, j), 0.00001f));
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
            CAPTURE(actual.at(i, j));
            CAPTURE(expected.at(i, j));
            CHECK(adizzle::almost_equal(actual.at(i, j), expected.at(i, j), 0.0001f));
        }
    }
}