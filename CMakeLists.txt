cmake_minimum_required(VERSION 3.10)
project(PBL_GNU C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(PBL_GNU main.c Types.h)


target_link_libraries(PBL_GNU m)