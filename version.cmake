cmake_minimum_required(VERSION 3.0)

function(update_git_revision)
    # The find_package() command is covered later in the Finding Things chapter.
    # Here, it provides the GIT_EXECUTABLE variable after searching for the
    # git binary in some standard/well-known locations for the current platform.
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
            RESULT_VARIABLE result
            OUTPUT_VARIABLE VERSION_GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(result)
        message(FATAL_ERROR "Failed to get git hash: ${result}")
    endif()

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp @ONLY)
endfunction()