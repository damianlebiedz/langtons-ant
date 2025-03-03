cmake_minimum_required(VERSION 3.10)
project(langtons-ant)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(langtons-ant
        src/Ant.cpp
        src/Grid.cpp
        src/main.cpp
        src/Renderer.cpp
        include/Grid.h
        include/Renderer.h
        include/Ant.h
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(langtons-ant PRIVATE sfml-graphics sfml-window sfml-system)

enable_testing()

add_subdirectory(gtest)

add_executable(unit_tests
        tests/AntTest.cpp
        tests/GridTest.cpp
)

target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(unit_tests PRIVATE gtest_main sfml-graphics sfml-window sfml-system)

add_test(NAME unit_tests COMMAND unit_tests)