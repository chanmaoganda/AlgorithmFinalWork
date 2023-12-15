cmake_minimum_required(VERSION 3.26)
project(AlgorithmFinalWork)

set(CMAKE_CXX_STANDARD 23)


include_directories(./include)
aux_source_directory(./src ALGORITHM_SRC)

add_executable(
        AlgorithmFinalWork
        ${ALGORITHM_SRC}
        include/Timer.h
        src/Timer.cpp
        include/BenchMark.h
        src/BenchMark.cpp
)