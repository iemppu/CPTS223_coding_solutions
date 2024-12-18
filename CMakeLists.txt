cmake_minimum_required(VERSION 3.10)
project(MA1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA1 main.cpp test_queue.cpp my_queue.cpp)
target_link_libraries(MA1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testSize COMMAND MA1 TestSize_QSC)
add_test(NAME testEmpty COMMAND MA1 TestEmpty_EQC)
add_test(NAME testFull COMMAND MA1 TestFull_FQC)
add_test(NAME testEnqueue COMMAND MA1 TestEnqueue_ENC1)
add_test(NAME testEnqueueFull COMMAND MA1 TestEnqueueFull_ENC2)
add_test(NAME testDequeue COMMAND MA1 TestDequeue_DQC1)
add_test(NAME testDequeueEmpty COMMAND MA1 TestDequeueEmpty_DQC2)
add_test(NAME testPeek COMMAND MA1 TestPeekPQC1)
add_test(NAME testPeekEmpty COMMAND MA1 TestPeekEmpty_PQC2)

set_tests_properties(testSize testEmpty testFull testEnqueue testEnqueueFull testDequeue testDequeueEmpty testPeek testPeekEmpty PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
