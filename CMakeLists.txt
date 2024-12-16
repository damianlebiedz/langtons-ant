cmake_minimum_required(VERSION 3.10)
project(cpp-langtons-ant)

set(CMAKE_CXX_STANDARD 17)

# Dodaj katalogi z plikami nagłówkowymi
include_directories(${CMAKE_SOURCE_DIR}/include)

# Utwórz plik wykonywalny
add_executable(cpp-langtons-ant
        src/Ant.cpp
        src/Button.cpp
        src/Grid.cpp
        src/main.cpp
        src/Renderer.cpp
        include/Ant.h
        include/Button.h
        include/Grid.h
        include/Renderer.h
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(cpp-langtons-ant PRIVATE sfml-graphics sfml-window sfml-system)

