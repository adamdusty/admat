set windows-shell := ["pwsh.exe", "-NoLogo", "-Command"]

configure-dev:
    cmake --preset dev -GNinja

configure-bench:
    cmake --preset bench -GNinja

build-dev:
    cmake --build --preset dev

build-bench:
    cmake --build --preset bench

test: build-dev
    ctest --preset dev

bench: build-bench
    build/bench/benchmarks/matrix_bench.exe

clean:
    @rm ./build -Recurse -Force