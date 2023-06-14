cmake_minimum_required(VERSION 3.23.2)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

# Place all header files into a variable
set(HEADER_FILES LinearStructures/Array.h LinearStructures/Queue.h LinearStructures/Stack.h LinearStructures/ArrayStack.h LinearStructures/ArrayQueue.h LinearStructures/LoopQueue.h LinearStructures/LinkedList.h LinearStructures/LinkedListStack.h LinearStructures/LinkedListQueue.h BST/BST.h)

# Set source files for each executable
set(DATASTRUCTURE_SRC main.cpp)

# Add executables
add_executable(DataStructure ${DATASTRUCTURE_SRC} ${HEADER_FILES})
#add_executable(DataStructure main.cpp Array.h Queue.h Stack.h ArrayStack.h ArrayQueue.h LoopQueue.h)
target_include_directories(DataStructure PRIVATE ${PROJECT_SOURCE_DIR}/LinearStructures ${PROJECT_SOURCE_DIR}/BST)
#add_executable(Test Test.cpp)
#
#
#add_executable(TestClass TestClass.cpp)
#
#add_executable(vaild_parent Valid-Parentheses.cpp)