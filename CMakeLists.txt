cmake_minimum_required(VERSION 3.10)
project(MA2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA2 main.cpp)

target_link_libraries(MA2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testInOrderTraversal COMMAND MA2 InOrderTraversal)
