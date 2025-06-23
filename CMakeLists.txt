# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.25)

project(
    beman.indices_view # CMake Project Name, which is also the name of the top-level
    # targets (e.g., library, executable, etc.).
    DESCRIPTION "An implementation of std::views::indices "
    LANGUAGES CXX
    VERSION 0.0.1
)

# [CMAKE.SKIP_TESTS]
option(
    BEMAN_INDICES_VIEW_BUILD_TESTS
    "Enable building tests and test infrastructure. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

# [CMAKE.SKIP_EXAMPLES]
option(
    BEMAN_INDICES_VIEW_BUILD_EXAMPLES
    "Enable building examples. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

option(
    BEMAN_INDICES_VIEW_INSTALL_CONFIG_FILE_PACKAGE
    "Enable creating and installing a CMake config-file package. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

include(GNUInstallDirs)

add_library(beman.indices_view INTERFACE)
add_library(beman::indices_view ALIAS beman.indices_view)

target_sources(
    beman.indices_view
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/include include
        FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/beman/indices_view/indices.hpp
)

set_target_properties(
    beman.indices_view
    PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON EXPORT_NAME indices_view
)

install(
    TARGETS beman.indices_view COMPONENT beman.indices_view
    EXPORT beman.indices_view
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}$<$<CONFIG:Debug>:/debug>
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}$<$<CONFIG:Debug>:/debug>
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(BEMAN_INDICES_VIEW_INSTALL_CONFIG_FILE_PACKAGE)
    include(CMakePackageConfigHelpers)

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/beman.indices_view-config-version.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY ExactVersion
    )

    install(
        FILES
            "${CMAKE_CURRENT_BINARY_DIR}/beman.indices_view-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/beman.indices_view-config-version.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/beman.indices_view"
        COMPONENT beman.indices_view
    )

    install(
        EXPORT beman.indices_view
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/beman.indices_view"
        NAMESPACE beman::
        FILE beman.indices_view-targets.cmake
        COMPONENT beman.indices_view
    )
endif()

include(CTest)

if(BEMAN_INDICES_VIEW_BUILD_TESTS)
    add_subdirectory(tests/beman/indices_view)
endif()

if(BEMAN_INDICES_VIEW_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
