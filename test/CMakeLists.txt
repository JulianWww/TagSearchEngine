cmake_minimum_required(VERSION 3.0.0)
project(jce VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(jce_tagsearchengine REQUIRED)

add_executable(runTest main.cpp)
target_link_libraries(runTest PUBLIC jce_tagsearchengine)