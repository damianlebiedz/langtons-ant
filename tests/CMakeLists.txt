add_executable(unit_tests
        AntTest.cpp
        GridTest.cpp
)

target_link_libraries(unit_tests
        PRIVATE
        gtest_main
        gmock_main
        sfml-graphics
        sfml-window
        sfml-system
)

target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(unit_tests)