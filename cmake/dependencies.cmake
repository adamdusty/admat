include(FetchContent)

FetchContent_Declare(
    adizzle
    GIT_REPOSITORY https://github.com/adamdusty/adizzle.git
    GIT_TAG        origin/main
    GIT_SHALLOW    TRUE
    SYSTEM
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(adizzle)