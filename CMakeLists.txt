cmake_minimum_required(VERSION 3.10)
project(cpp-langtons-ant)

set(CMAKE_CXX_STANDARD 17)

# Dodaj katalogi z plikami nagłówkowymi
include_directories(include)

# Utwórz plik wykonywalny
add_executable(cpp-langtons-ant
        src/main.cpp
        src/Ant.cpp
        src/Grid.cpp
        src/Renderer.cpp
)

# W razie potrzeby dodaj biblioteki (SFML w tym przypadku)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(cpp-langtons-ant PRIVATE sfml-graphics sfml-window sfml-system)
