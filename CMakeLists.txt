cmake_minimum_required (VERSION 3.6)
project (peaProject1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

file(GLOB_RECURSE BENCHMARK_SRC_FILES ${PROJECT_SOURCE_DIR}/benchmark/src/**/*.cpp)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/**/*.cpp)

# Main
add_executable(main src/main ${SRC_FILES})
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

#Benchmark
add_executable(benchmark benchmark/src/benchmark ${BENCHMARK_SRC_FILES} ${SRC_FILES})
target_include_directories(benchmark PUBLIC ${PROJECT_SOURCE_DIR}/benchmark/include)
target_include_directories(benchmark PUBLIC ${PROJECT_SOURCE_DIR}/include)
