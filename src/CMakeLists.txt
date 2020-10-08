cmake_minimum_required(VERSION 3.2)
project(${CMAKE_PROJECT_NAME}_src)
include_directories(.)

file(GLOB_RECURSE ${PROJECT_NAME}_files *.cpp *.hpp)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_files})
