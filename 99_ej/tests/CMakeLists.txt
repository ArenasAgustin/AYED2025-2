add_executable(99_ej_tests 
    node_tests.cpp 
    list_tests.cpp 
    list_base_tests.cpp
    stack_tests.cpp
    ../lists.cpp 
    ../list_base.cpp
)
target_link_libraries(99_ej_tests PRIVATE gtest gtest_main)
target_include_directories(99_ej_tests PRIVATE ..)

add_test(NAME 99_ej_tests COMMAND 99_ej_tests)