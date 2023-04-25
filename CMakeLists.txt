cmake_minimum_required(VERSION 3.0)

project(symbol_interposition_example)

# Compile libA.so
add_library(A SHARED A.c)

add_library(C SHARED C.c)

# Compile libB.so
add_library(B SHARED B.c)
target_link_libraries(B PUBLIC dl)

# Compile main and link with libA.so and libdl
add_executable(main main.c)
target_link_libraries(main PUBLIC A C dl)

# Set LD_PRELOAD for the main test
add_test(NAME main_test
         COMMAND env LD_PRELOAD=main)
