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
add_library(admat_admat)
add_library(admat::admat ALIAS admat_admat)

# Add sources
target_sources(admat_admat PRIVATE
    src/admat.cpp
)

# Add include directory
# warning_guard adds SYSTEM modifier if the project isn't top level
target_include_directories(
    admat_admat ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

# Include and link dependencies
target_link_libraries(admat_admat
    PUBLIC
        adizzle::adizzle
)

# Add compile options
add_dev_compile_opts(admat_admat)

# Generate header for export
include(GenerateExportHeader)
generate_export_header(
    admat_admat
    BASE_NAME admat
    EXPORT_FILE_NAME include/admat/export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

# Set properties
set_target_properties(
    admat_admat PROPERTIES
    CXX_VISIBILITY_PRESET "hidden"
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME admat
    OUTPUT_NAME admat
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