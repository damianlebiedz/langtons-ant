# Langton's ant
Implementation of Langton's ant cellular automaton in C++ using SFML library.
https://en.wikipedia.org/wiki/Langton%27s_ant

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Contents
- [Technologies](#technologies)
- [Installation](#installation)
- [View](#view)
- [Contact](#contact)

## Technologies
- C++
- SFML
- CMake

## Installation
Make sure that you have installed:
- C++ compiler compatible with C++17 or later (MinGW recommended: https://www.mingw-w64.org/getting-started/msys2)
- CMake v.3.10 or later (https://cmake.org/download)
- SFML v.2.5 or later (https://www.sfml-dev.org/download)

Type in Command Prompt:
```bash
git clone https://github.com/damianlebiedz/langtons-ant
cd langtons-ant
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
langtons-ant.exe
```
IMPORTANT:
```bash
cmake-G "MinGW Makefiles"
```
for MinGW compiler.
Building with Visual Studio MSVC compiler may encounter errors - to be clatified why...

## View
![cpp-langtons-ant](https://github.com/user-attachments/assets/9b71c99d-df5e-4b80-b68b-0046e1f5defd)

## Contact
Damian Lebiedź | 
https://damianlebiedz.github.io
