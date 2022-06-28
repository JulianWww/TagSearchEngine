cmake_minimum_required(VERSION 3.0.0)
project(jce VERSION 0.1.0)

set(DEFAULT_BUILD_TYPE "Release")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(CTest)
enable_testing()


add_executable(run main.cpp)
target_link_libraries(run PUBLIC jce_tagsearchengine)
set_property(TARGET run PROPERTY CXX_STANDARD 20)
