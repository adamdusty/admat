#define GLM_FORCE_PURE

#include <admat/matrix.hpp>
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <nanobench.h>
#include <random>

using namespace admat;
using namespace ankerl;

template<typename T, size_t R, size_t C>
auto randomize(column_major_matrix<T, R, C> mat) {
    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 5.0f};

    for(size_t i = 0; i < R; ++i) {
        for(size_t j = 0; j < C; ++j) {
            mat.at(i, j) = dist(gen);
        }
    }
}

auto random_glm() -> glm::mat4 {
    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 100.0f};
    return {dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen),
            dist(gen)};
}

auto inverse() {
    auto m1 = mat4{};
    auto m2 = random_glm();
    randomize(m1);

    auto bench = nanobench::Bench().title("inverse").relative(true);
    bench.run("admat inverse", [&] { nanobench::doNotOptimizeAway(inverse(m1)); });
    bench.run("glm inverse", [&] { nanobench::doNotOptimizeAway(glm::inverse(m2)); });
}

auto addition() {
    auto m1 = mat4{};
    auto m2 = random_glm();
    randomize(m1);

    auto bench = nanobench::Bench().title("addition").relative(true);
    bench.run("admat addition", [&] { nanobench::doNotOptimizeAway(m1 + m1); });
    bench.run("glm addition", [&] { nanobench::doNotOptimizeAway(m2 + m2); });
}

auto multiplication() {
    auto m1 = mat4{};
    auto m2 = random_glm();
    randomize(m1);

    auto bench = nanobench::Bench().title("multiplication").relative(true);
    bench.run("admat multiplication", [&] { nanobench::doNotOptimizeAway(m1 * m1); });
    bench.run("glm multiplication", [&] { nanobench::doNotOptimizeAway(m2 * m2); });
}

auto determinant() {
    auto m1 = mat4{};
    auto m2 = random_glm();
    randomize(m1);

    auto bench = nanobench::Bench().title("determinant").relative(true);
    bench.run("admat determinant", [&] { nanobench::doNotOptimizeAway(determinant_mat4(m1)); });
    bench.run("glm determinant", [&] { nanobench::doNotOptimizeAway(glm::determinant(m2)); });
}

auto transpose() {
    auto m1 = mat4{};
    auto m2 = random_glm();
    randomize(m1);

    glm::perspective(1.f, 1.f, 1.f, 1.f);

    auto bench = nanobench::Bench().title("transpose").relative(true);
    bench.run("admat transpose", [&] { nanobench::doNotOptimizeAway(transpose(m1)); });
    bench.run("glm transpose", [&] { nanobench::doNotOptimizeAway(glm::transpose(m2)); });
}

auto main() -> int {
    inverse();
    addition();
    multiplication();
    determinant();
    transpose();
    return 0;
}