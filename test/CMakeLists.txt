project(test_hello_world_cpp)
include(GoogleTest)

find_package(GTest REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "--coverage")
endif()

add_executable(
        ${PROJECT_NAME}
        test_library.cpp
        main.cpp
)

add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        GTest::GTest
        hello_world_cpp
)
