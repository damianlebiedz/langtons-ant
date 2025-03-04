cmake_minimum_required(VERSION 3.14)
project(langtons-ant)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(langtons-ant-lib
        src/Ant.cpp
        src/Grid.cpp
        src/Renderer.cpp
)

target_include_directories(langtons-ant-lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(langtons-ant-lib PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(langtons-ant src/main.cpp)
target_link_libraries(langtons-ant PRIVATE langtons-ant-lib)

enable_testing()
add_subdirectory(tests)
