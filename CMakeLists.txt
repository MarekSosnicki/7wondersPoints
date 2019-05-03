cmake_minimum_required(VERSION 3.8)
project(ExampleProject)
add_definitions(-std=gnu++17)

set(testDataPath ${CMAKE_CURRENT_SOURCE_DIR}/testData)
message(Test data path:  ${testDataPath})
add_definitions( -DTEST_DATA_PATH="${testDataPath}")

add_subdirectory(test)
add_subdirectory(src)
include_directories(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_src)
