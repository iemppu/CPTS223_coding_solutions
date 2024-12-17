cmake_minimum_required(VERSION 3.16)
project(MA3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA3 main.cpp)

target_link_libraries(MA3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testBuildMap COMMAND MA3 testBuildMap)

