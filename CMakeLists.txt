cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp Array.h Queue.h Stack.h ArrayStack.h ArrayQueue.h LoopQueue.h)

add_executable(Test Test.cpp)


add_executable(TestClass TestClass.cpp)

add_executable(vaild_parent Valid-Parentheses.cpp)