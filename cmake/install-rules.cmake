if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/admat-${PROJECT_VERSION}"
      CACHE PATH ""
  )
endif()

set(package admat)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Set up export components
install(
    TARGETS admat_admat
    EXPORT admatTargets
    RUNTIME COMPONENT admat_Runtime
    LIBRARY COMPONENT admat_Runtime
    NAMELINK_COMPONENT admat_Development
    ARCHIVE COMPONENT admat_Development
    FILE_SET admat_headers
)

# Write package file for installations
write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    admat_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(admat_INSTALL_CMAKEDIR)

# Install config file to the install directory
# Config file is used by find_package() (I assume)
install(
    FILES cmake/install-config.cmake
    DESTINATION "${admat_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT admat_Development
)

# Install ConfigVersion file
# More package install info
install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${admat_INSTALL_CMAKEDIR}"
    COMPONENT admat_Development
)

# Install the dev component from targets defined above (I think)
install(
    EXPORT admatTargets
    NAMESPACE admat::
    DESTINATION "${admat_INSTALL_CMAKEDIR}"
    COMPONENT admat_Development
)

# Include CPack
if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()