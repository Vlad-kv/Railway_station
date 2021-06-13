set(CMAKE_CXX_COMPILER "c:/TDM-GCC-64/bin/g++.exe")
set(CMAKE_C_COMPILER "c:/TDM-GCC-64/bin/gcc.exe")

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
  set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}" CACHE STRING "")
endif()

cmake_minimum_required(VERSION 2.9)
project(railway_station)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(railway_station ${SOURCE_FILES})

target_link_libraries(railway_station
  glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
