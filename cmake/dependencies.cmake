include(FetchContent)

if(NOT TARGET adizzle::adizzle)

FetchContent_Declare(
    adizzle
    GIT_REPOSITORY https://github.com/adamdusty/adizzle.git
    GIT_TAG        main
    GIT_SHALLOW    TRUE
    SYSTEM
    FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(adizzle)

endif()