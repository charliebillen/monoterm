cmake_minimum_required(VERSION 3.27)
project(monoterm C)

set(CMAKE_C_STANDARD 11)

add_library(term src/term.c src/term.h)
add_library(colour src/colour.c src/colour.h)

add_executable(monoterm src/main.c)
target_link_libraries(monoterm PRIVATE term)
target_link_libraries(monoterm PRIVATE colour)

add_executable(colour_tests test/colour_tests.c)
target_link_libraries(colour_tests PRIVATE colour)

add_executable(term_tests test/term_tests.c)
target_link_libraries(term_tests PRIVATE term)
target_link_libraries(term_tests PRIVATE colour)

enable_testing()

add_test(
    NAME colour_tests
    COMMAND $<TARGET_FILE:colour_tests>
)

add_test(
    NAME term_tests
    COMMAND $<TARGET_FILE:term_tests>
)
