cmake_minimum_required(VERSION 3.6)
project(Lem_in)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lem_in.c lem_in.h)
add_executable(LEM_IN ${SOURCE_FILES})

target_link_libraries(LEM_IN ${CMAKE_SOURCE_DIR}/libft/libftprintf.a)