cmake_minimum_required(VERSION 3.10)
project(MA2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA2 main.cpp)

target_link_libraries(MA2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testInOrderTraversal COMMAND MA2 InOrderTraversal)
add_test(NAME testPrintLevels COMMAND MA2 PrintLevels)
add_test(NAME testContain COMMAND MA2 TestContain)
add_test(NAME testSize COMMAND MA2 TestSize)
add_test(NAME testHeight COMMAND MA2 TestHeight)
add_test(NAME testPrintMaxPath COMMAND MA2 PrintMaxPath)
add_test(NAME testDelete COMMAND MA2 TestDelete)
  
set_tests_properties(testInOrderTraversal testPrintLevels testContain testSize testHeight testPrintMaxPath testDelete PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
