cmake_minimum_required(VERSION 3.27)

project(
    admatTests
    LANGUAGES CXX
)

# If test project is built independently, find the project package
if(PROJECT_IS_TOP_LEVEL)
    find_package(admat REQUIRED)
    enable_testing()
endif()

# Get the testing library
include(FetchContent)
FetchContent_Declare(
    snitch
    GIT_REPOSITORY https://github.com/snitch-org/snitch.git
    GIT_TAG        v1.2.5
    GIT_SHALLOW    TRUE
    SYSTEM
    FIND_PACKAGE_ARGS # Use system package if installed
)
FetchContent_MakeAvailable(snitch)

# Add test exe
add_executable(admat_tests)
target_compile_options(admat_tests PRIVATE ${DEV_COMPILE_OPTIONS})



# Add test sources
target_sources(admat_tests PRIVATE
    src/vector_tests.cpp
    src/matrix_tests.cpp
)

# Link libs
target_link_libraries(admat_tests PRIVATE admat::admat snitch::snitch libassert::assert)

# Add test
add_test(NAME admat_tests COMMAND admat_tests)

# Enable test binary to find the DLL if building a shared lib
if(BUILD_SHARED_LIBS)
    set(DLL_DIRS "$<TARGET_RUNTIME_DLL_DIRS:admat_tests>")
    set(ENV_OP "PATH=path_list_append:")

    set_tests_properties(admat_tests PROPERTIES
        ENVIRONMENT_MODIFICATION
            "${ENV_OP}$<JOIN:${DLL_DIRS},$<SEMICOLON>${ENV_OP}>"
    )
endif()
