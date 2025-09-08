add_executable(99_ej_tests tests.cpp ../lists.cpp)
target_link_libraries(99_ej_tests PRIVATE gtest gtest_main)
target_include_directories(99_ej_tests PRIVATE ..)

add_test(NAME 99_ej_tests COMMAND 99_ej_tests)