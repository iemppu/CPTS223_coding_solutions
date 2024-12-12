cmake_minimum_required(VERSION 3.16)

project(CPTS223_MA4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
#  if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
    set(OpenMP_CXX_LIB_NAMES "omp")
    set(OpenMP_CXX_LIBRARIES "/opt/homebrew/opt/libomp/lib/libomp.dylib")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/opt/libomp/lib -lomp")
#  elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  else ()
    set(OpenMP_CXX_FLAGS "-fopenmp")
    set(OpenMP_CXX_LIB_NAMES "gomp")
    set(OpenMP_CXX_LIBRARIES "/opt/homebrew/lib/gcc/14/libgomp.dylib") # 替换 XX 为具体 GCC 版本号
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/lib/gcc/14 -lgomp")
  endif()
elseif (UNIX AND NOT APPLE)
  find_package(OpenMP REQUIRED)
else ()
  find_package(OpenMP REQUIRED)
endif()

# 定义可执行目标
add_executable(MA4 main.cpp)
target_link_libraries(MA4 PUBLIC ${OpenMP_CXX_LIBRARIES})