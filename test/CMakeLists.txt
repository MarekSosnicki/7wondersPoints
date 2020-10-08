cmake_minimum_required(VERSION 3.2)

project(${CMAKE_PROJECT_NAME}_test)

include_directories(./doctest)
include_directories(../src)

file(GLOB_RECURSE ${PROJECT_NAME}_files  *.cpp *.h)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_files})

target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME}_src)


add_custom_target(run_tests
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)