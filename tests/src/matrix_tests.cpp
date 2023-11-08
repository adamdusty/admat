#include <adizzle/float.hpp>
#include <admat/matrix.hpp>
#include <snitch/snitch.hpp>

#include <cmath>

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
    auto m1 = matrix::column_major_matrix<float, 2, 3>::from_row_major({
        1, 2, 3,
        4, 5, 6,
    });
    // clang-format on

    auto expected = matrix::column_major_matrix<float, 2, 3>{{1, 4, 2, 5, 3, 6}};

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
    auto mat = matrix::column_major_matrix<float, 2, 3>{{1, 4, 2, 5, 3, 6}};

    CHECK(adizzle::almost_equal(mat.at(0, 0), 1.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 1), 2.0f));
    CHECK(adizzle::almost_equal(mat.at(0, 2), 3.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 0), 4.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 1), 5.0f));
    CHECK(adizzle::almost_equal(mat.at(1, 2), 6.0f));
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
    auto m1 = matrix::column_major_matrix<float, 3, 2>::from_row_major({
        1, 2,
        3, 4,
        5, 6,
    });

    auto m2 = matrix::column_major_matrix<float, 2, 3>::from_row_major({
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