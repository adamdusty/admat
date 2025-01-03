cmake_minimum_required(VERSION 3.27)

project(
    admat
    VERSION 0.1.0
    DESCRIPTION "A short description"
    LANGUAGES CXX
)

# Include utilities
include(cmake/options.cmake)
include(cmake/warning-guard.cmake)
include(cmake/compile-options.cmake)
include(cmake/dependencies.cmake)

# Declare library
add_library(admat_admat INTERFACE)
add_library(admat::admat ALIAS admat_admat)

# Add sources
target_sources(admat_admat
    PUBLIC
        FILE_SET    admat_headers
        TYPE        HEADERS
        BASE_DIRS   include
        FILES
            "include/admat/mat.hpp"
            "include/admat/vec.hpp"
)

# Include and link dependencies
# target_link_libraries(admat_admat)

# Install rules
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# Build benchmarks
if(ADMAT_BUILD_BENCH)
    add_subdirectory(benchmarks)
endif()

# Enable testing
if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(tests)
endif()