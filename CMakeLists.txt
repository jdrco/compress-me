
cmake_minimum_required(VERSION 3.10)

project(rle-compression-algorithm VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(rle-compression-algorithm src/main.c src/compress.c src/decompress.c)

target_include_directories(rle-compression-algorithm PUBLIC "${PROJECT_BINARY_DIR}" src/)
