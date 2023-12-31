﻿# CMakeList.txt : CMake project for TheAlgorithmDesignManual, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TheAlgorithmDesignManual")

# Add source to this project's executable.
add_executable (TheAlgorithmDesignManual "TheAlgorithmDesignManual.cpp" "TheAlgorithmDesignManual.h"  
	"src/Deque/Deque.h" "src/Deque/ArrayDeque.h" "src/Deque/LinkedListDeque.h" "src/Deque/LinkedList.h"
	"src/BinarySearchTree/BinarySearchTree.h" "src/BinarySearchTree/BinarySearchTreeImpl.h" 
	"src/Example/Point.h" 
	"src/HashTable/HashMap.h" "src/HashTable/HashMapChainingImpl.h" 
	"src/PriorityQueue/PriorityQueue.h" "src/HashTable/HashMapProbingImpl.h" "src/PriorityQueue/PriorityQueueHeapImpl.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TheAlgorithmDesignManual PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
