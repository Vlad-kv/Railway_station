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
