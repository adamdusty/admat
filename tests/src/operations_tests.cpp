// #include <adizzle/float.hpp>
// #include <admat/matrix.hpp>
// #include <admat/operations.hpp>
// #include <admat/vector.hpp>
// #include <snitch/snitch.hpp>

// #include <cmath>

// using namespace admat;

// TEST_CASE("Multiply vector by matrix") {
//     auto vec = vec3{5.0f, 6.0f, 7.0f};

//     // clang-format off
//     auto mat = mat3::from_row_major({
//         1, 2, 3,
//         4, 5, 6,
//         7, 8, 9,
//     });
//     // clang-format on

//     auto expected = vec3{30.0f, 90.0f, 168.0f};

//     auto result = vec * mat;

//     CHECK(result == expected);
// }

// TEST_CASE("Multiply vector by non-square matrix") {
//     auto vec = vec3{5.0f, 6.0f, 7.0f};

//     // clang-format off
//     auto mat = column_major_matrix<float, 2, 3>::from_row_major({
//         1, 2, 3,
//         4, 5, 6,
//     });
//     // clang-format on

//     auto expected = vec2{30.0f, 90.0f};

//     auto result = vec * mat;

//     CHECK(result == expected);
// }

// TEST_CASE("Multiply matrix by vector") {
//     auto vec = vec3{5.0f, 6.0f, 7.0f};

//     // clang-format off
//     auto mat = mat3::from_row_major({
//         1, 2, 3,
//         4, 5, 6,
//         7, 8, 9,
//     });
//     // clang-format on

//     auto expected = vec3{30.0f, 90.0f, 168.0f};

//     auto result = mat * vec;

//     CHECK(result == expected);
// }