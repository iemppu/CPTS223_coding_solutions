cmake_minimum_required(VERSION 3.16)
project(MA3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_executable(MA3 main.cpp)

target_link_libraries(MA3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME testBuildMap COMMAND ${CMAKE_BINARY_DIR}/MA3 TestBuildMap)
add_test(NAME testPrintByUserName COMMAND ${CMAKE_BINARY_DIR}/MA3 TestPrintByUserName)

add_test(NAME testSearchByKey COMMAND ${CMAKE_BINARY_DIR}/MA3 TestSearchByKey)
set_tests_properties(testSearchByKey PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_test(NAME testDeleteByKey COMMAND ${CMAKE_BINARY_DIR}/MA3 TestDeleteByKey)
add_test(NAME testSortedKey COMMAND MA3 TestSortedKey)
add_test(NAME testPrintActiveUsers COMMAND MA3 TestPrintActiveUsers)
add_test(NAME testPrintMostPopularCategory COMMAND MA3 TestPrintMostPopularCategory)

