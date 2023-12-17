cmake_minimum_required(VERSION 3.26)

set(PROJECT_VERSION 1.0.0)

project(AlgorithmFinalWork
    LANGUAGES CXX C
    VERSION ${PROJECT_VERSION}
)

set(CMAKE_CXX_STANDARD 23)

#include(CMakeDependentOption)
#cmake_dependent_option(BUILD_TESTS "build your tests" ON "val1, val2" OFF)
#if(NOT BUILD_TESTS)
#    mark_as_advanced(BUILD_TESTS)
#endif()
include(CMakePrintHelpers)

MESSAGE(STATUS "test starts")
cmake_print_variables(CMAKE_CXX_STANDARD)



include_directories(./include)
aux_source_directory(./src ALGORITHM_SRC)

add_executable(
        AlgorithmFinalWork
        ${ALGORITHM_SRC}
)