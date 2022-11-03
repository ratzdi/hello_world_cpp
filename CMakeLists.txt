cmake_minimum_required(VERSION 3.16)
project(hello_world_cpp VERSION 0.1.0 DESCRIPTION "The Hello World C++ library")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
enable_testing()

include(GNUInstallDirs)
include(version.cmake)

update_git_revision()

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME}
        PRIVATE
        src/library.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

set(public_headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/library.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        CONFIGURATIONS Release Debug
        LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        CONFIGURATIONS Release Debug
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        CONFIGURATIONS Release Debug
        PUBLIC_HEADER
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        CONFIGURATIONS Release Debug
        )

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        NAMESPACE ${PROJECT_NAME}::
        FILE ${PROJECT_NAME}Config.cmake
        )

add_subdirectory(./test)