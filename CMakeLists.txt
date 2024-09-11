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
target_sources(admat_admat
    PUBLIC
        FILE_SET    admat_headers
        TYPE        HEADERS
        BASE_DIRS   include
        FILES
            "include/admat/export.hpp>"
            "include/admat/mat.hpp"
            "include/admat/vec.hpp"
            "include/admat/mat/mat.hpp"
            "include/admat/mat/arithmetic.hpp"
            "include/admat/mat/operations.hpp"
            "include/admat/mat/projections.hpp"
            "include/admat/vec/vec.hpp"
            "include/admat/vec/arithmetic.hpp"
            "include/admat/vec/operations.hpp"
    PRIVATE
        src/vec/operations.cpp
        src/mat/operations.cpp
        src/mat/projections.cpp
)

# Include and link dependencies
# target_link_libraries(admat_admat)

# Add compile options
target_compile_options(admat_admat PRIVATE ${DEV_COMPILE_OPTIONS})

# Generate header for export
include(GenerateExportHeader)
generate_export_header(
    admat_admat
    BASE_NAME admat
    EXPORT_FILE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/include/admat/export.hpp"
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
if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(tests)
endif()