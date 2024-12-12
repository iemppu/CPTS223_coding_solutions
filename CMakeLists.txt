cmake_minimum_required(VERSION 3.16)
project(CPTS_223_MA4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include") # make sure this directory is valid in your system
    set(OpenMP_CXX_LIB_NAMES "omp")
    set(OpenMP_CXX_LIBRARIES "/opt/homebrew/opt/libomp/lib/libomp.dylib")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/opt/libomp/lib -lomp")
  endif()
elseif (UNIX AND NOT APPLE) # Linux is included in this case
  find_package(OpenMP REQUIRED)
else () # Windows system
  find_package(OpenMP REQUIRED)
endif()

add_executable(MA4 main.cpp)
target_link_libraries(MA4 PUBLIC ${OpenMP_CXX_LIBRARIES})
