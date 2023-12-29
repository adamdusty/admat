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
# target_sources(admat_admat)

# Add include directory
# warning_guard adds SYSTEM modifier if the project isn't top level
target_include_directories(
    admat_admat ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

# Include and link dependencies
target_link_libraries(admat_admat
    INTERFACE
        adizzle::adizzle
)

# Set properties
set_target_properties(admat_admat PROPERTIES
    EXPORT_NAME admat
)

# Install rules
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# Build benchmarks
if(ADMAT_BUILD_BENCH)
    add_subdirectory(benchmarks)
endif()

# Enable testing
if(ADMAT_BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()