cmake_minimum_required(VERSION 3.0.0)
project(jce VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(run main.cpp)
target_link_libraries(run PUBLIC jce_tagsearchengine)
set_property(TARGET run PROPERTY CXX_STANDARD 20)
