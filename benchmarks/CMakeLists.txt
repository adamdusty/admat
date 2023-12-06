cmake_minimum_required(VERSION 3.27)

project(
    admatBench
    LANGUAGES CXX
)

if(PROJECT_IS_TOP_LEVEL)
    find_package(admat REQUIRED)
endif()

include(FetchContent)
FetchContent_Declare(
    nanobench
    GIT_REPOSITORY https://github.com/martinus/nanobench.git
    GIT_TAG        v4.3.11
    GIT_SHALLOW    TRUE
    SYSTEM
    FIND_PACKAGE_ARGS
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        586a402
    SYSTEM
)
FetchContent_MakeAvailable(nanobench glm)

add_executable(vector_bench
    src/vector.cpp
)

add_executable(matrix_bench
    src/matrix.cpp
)

target_link_libraries(vector_bench PRIVATE admat::admat glm::glm nanobench::nanobench)
target_link_libraries(matrix_bench PRIVATE admat::admat glm::glm nanobench::nanobench)