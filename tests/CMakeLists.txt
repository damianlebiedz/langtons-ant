cmake_minimum_required(VERSION 3.14)

include(GoogleTest)

add_executable(unit_tests
        AntTest.cpp
        GridTest.cpp)

target_include_directories(unit_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(unit_tests PRIVATE langtons-ant-lib gtest_main gmock sfml-graphics sfml-window sfml-system)

gtest_discover_tests(unit_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests)