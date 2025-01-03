#include <admat/vec.hpp>
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <nanobench.h>
#include <random>

using namespace admat;
using namespace ankerl;

auto random_vec4() -> vec4 {
    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 500.0f};

    return vec4{dist(gen), dist(gen), dist(gen), dist(gen)};
}

auto random_glm() -> glm::vec4 {
    auto dev  = std::random_device{};
    auto gen  = std::mt19937(dev());
    auto dist = std::uniform_real_distribution{0.0f, 100.0f};
    return {dist(gen), dist(gen), dist(gen), dist(gen)};
}

auto vec4_ops() {
    auto av1 = random_vec4();
    auto av2 = random_vec4();
    auto gv1 = random_glm();
    auto gv2 = random_glm();

    auto bench_add = nanobench::Bench().title("addition").relative(true);
    bench_add.run("admat addition", [&] { nanobench::doNotOptimizeAway(av1 + av2); });
    bench_add.run("glm addition", [&] { nanobench::doNotOptimizeAway(gv1 + gv2); });
    
    auto bench_sub = nanobench::Bench().title("addition").relative(true);
    bench_sub.run("admat subtraction", [&] { nanobench::doNotOptimizeAway(av1 - av2); });
    bench_sub.run("glm subtraction", [&] { nanobench::doNotOptimizeAway(gv1 - gv2); });
    
    auto bench_mul = nanobench::Bench().title("addition").relative(true);
    bench_mul.run("admat multiplication", [&] { nanobench::doNotOptimizeAway(av1 * av2); });
    bench_mul.run("glm multiplication", [&] { nanobench::doNotOptimizeAway(gv1 * gv2); });
    
    auto bench_div = nanobench::Bench().title("addition").relative(true);
    bench_div.run("admat division", [&] { nanobench::doNotOptimizeAway(av1 / av2); });
    bench_div.run("glm division", [&] { nanobench::doNotOptimizeAway(gv1 / gv2); });
}

auto main() -> int {
    vec4_ops();
    return 0;
}