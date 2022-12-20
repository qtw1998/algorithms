cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms main.cpp)
add_executable(SelectionSort Sorting/SelectionSort.cpp Sorting/Student.h Sorting/SortTestHelper.h)
