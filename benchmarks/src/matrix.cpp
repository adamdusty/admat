#define GLM_FORCE_PURE

#include <admat/matrix.hpp>
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <nanobench.h>
#include <random>

using namespace admat;
using namespace ankerl;

template<typename T, size_t R, size_t C>
auto randomize(matrix::column_major_matrix<T, R, C> mat) {
    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 5.0f};

    for(size_t i = 0; i < R; ++i) {
        for(size_t j = 0; j < C; ++j) {
            mat.at(i, j) = dist(gen);
        }
    }
}

auto inverse() {
    auto m1 = mat4{};
    randomize(m1);

    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 5.0f};
    auto m2   = glm::mat4(dist(gen),
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
                        dist(gen));

    auto bench = nanobench::Bench().relative(true).epochIterations(500000);
    bench.run("admat inverse", [&] { nanobench::doNotOptimizeAway(matrix::inverse(m1)); });
    bench.run("glm inverse", [&] { nanobench::doNotOptimizeAway(glm::inverse(m2)); });
}

auto main() -> int {
    inverse();
    return 0;
}