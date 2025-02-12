cmake_minimum_required(VERSION 3.10)
project(langtons-ant)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(langtons-ant
        src/Ant.cpp
        src/Grid.cpp
        src/main.cpp
        src/Renderer.cpp
        include/Ant.h
        include/Renderer.h
        include/Grid.h
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(langtons-ant PRIVATE sfml-graphics sfml-window sfml-system)