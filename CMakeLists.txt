cmake_minimum_required(VERSION 3.10)

project(compress-me VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(compress-me src/main.c src/compress.c src/decompress.c)

target_include_directories(compress-me PUBLIC "${PROJECT_BINARY_DIR}" src/)
