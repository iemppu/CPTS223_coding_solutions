cmake_minimum_required(VERSION 3.10)
project(MA1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA1 main.cpp test_queue.cpp queue.cpp)
target_link_libraries(MA1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testSize COMMAND MA1 QSC)
add_test(NAME testEmpty COMMAND MA1 EQC)
add_test(NAME testFull COMMAND MA1 FQC)
add_test(NAME testEnqueue COMMAND MA1 ENC1)
add_test(NAME testEnqueueFull COMMAND MA1 ENC2)
add_test(NAME testDequeue COMMAND MA1 DQC1)
add_test(NAME testDequeueEmpty COMMAND MA1 DQC2)
add_test(NAME testPeek COMMAND MA1 PQC1)
add_test(NAME testPeekEmpty COMMAND MA1 PQC2)

