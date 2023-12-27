// #define GLM_FORCE_PURE

// #include <admat/matrix.hpp>
// #include <glm/ext.hpp>
// #include <glm/glm.hpp>
// #include <nanobench.h>
// #include <random>

// using namespace admat;
// using namespace ankerl;

// template<typename T, size_t R, size_t C>
// auto randomize(column_major_matrix<T, R, C> mat) {
//     auto dev  = std::random_device{};
//     auto gen  = std::mt19937(dev());
//     auto dist = std::uniform_real_distribution{0.0f, 5.0f};

//     for(size_t i = 0; i < R; ++i) {
//         for(size_t j = 0; j < C; ++j) {
//             mat.at(i, j) = dist(gen);
//         }
//     }
// }

// auto random_glm() -> glm::mat4 {
//     auto dev  = std::random_device{};
//     auto gen  = std::mt19937(dev());
//     auto dist = std::uniform_real_distribution{0.0f, 100.0f};
//     return {dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen),
//             dist(gen)};
// }

// auto inverse() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     auto bench = nanobench::Bench().title("inverse").relative(true);
//     bench.run("admat inverse", [&] { nanobench::doNotOptimizeAway(inverse(m1)); });
//     bench.run("glm inverse", [&] { nanobench::doNotOptimizeAway(glm::inverse(m2)); });
// }

// auto addition() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     auto bench = nanobench::Bench().title("addition").relative(true);
//     bench.run("admat addition", [&] { nanobench::doNotOptimizeAway(m1 + m1); });
//     bench.run("glm addition", [&] { nanobench::doNotOptimizeAway(m2 + m2); });
// }

// auto multiplication() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     auto bench = nanobench::Bench().title("multiplication").relative(true);
//     bench.run("admat multiplication", [&] { nanobench::doNotOptimizeAway(m1 * m1); });
//     bench.run("glm multiplication", [&] { nanobench::doNotOptimizeAway(m2 * m2); });
// }

// auto determinant() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     auto bench = nanobench::Bench().title("determinant").relative(true);
//     bench.run("admat determinant", [&] { nanobench::doNotOptimizeAway(determinant_mat4(m1)); });
//     bench.run("glm determinant", [&] { nanobench::doNotOptimizeAway(glm::determinant(m2)); });
// }

// auto transpose() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     auto bench = nanobench::Bench().title("transpose").relative(true);
//     bench.run("admat transpose", [&] { nanobench::doNotOptimizeAway(transpose(m1)); });
//     bench.run("glm transpose", [&] { nanobench::doNotOptimizeAway(glm::transpose(m2)); });
// }

// auto rotation() {
//     auto m1 = mat4{};
//     auto m2 = random_glm();
//     randomize(m1);

//     // TODO: Not equivalent rotation calculations
//     auto bench = nanobench::Bench().title("rotation").relative(true);
//     bench.run("admat rotate", [&] { nanobench::doNotOptimizeAway(rotate(m1, {30.0f, 60.0f, 90.0f})); });
//     bench.run("glm rotate", [&] { nanobench::doNotOptimizeAway(glm::rotate(m2, 50.0f, {1.0f, 0.0f, 0.0f})); });
// }

// auto create_perspective() {
//     auto bench = nanobench::Bench().title("perspective").relative(true);
//     bench.run("admat perspective",
//               [&] { nanobench::doNotOptimizeAway(perspective(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f)); });
//     bench.run("glm perspective",
//               [&] { nanobench::doNotOptimizeAway(glm::perspective(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f)); });
// }

// auto create_orthographic() {
//     auto bench = nanobench::Bench().title("orthographic").relative(true);
//     bench.run("admat orthographic",
//               [&] { nanobench::doNotOptimizeAway(orthographic(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f)); });
//     bench.run("glm orthographic",
//               [&] { nanobench::doNotOptimizeAway(glm::ortho(0.523599f, 1280.0f / 720.0f, 1.5f, 1000.0f)); });
// }

auto main() -> int {
    // inverse();
    // addition();
    // multiplication();
    // determinant();
    // transpose();
    // rotation();
    // create_perspective();
    // create_orthographic();
    return 0;
}