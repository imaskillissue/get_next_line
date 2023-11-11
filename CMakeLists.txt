cmake_minimum_required(VERSION 3.25)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D BUFFER_SIZE=42")

include_directories(includes)

add_executable(get_next_line main.c includes/get_next_line.h src/get_next_line.c src/get_next_line_utils.c)
