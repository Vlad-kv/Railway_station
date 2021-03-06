cmake_minimum_required(VERSION 2.9)
project(railway_station)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)
add_subdirectory(Freeglut/freeglut/freeglut)

include_directories(glfw/include)
include_directories(glm)
include_directories(Freeglut/freeglut/freeglut/include)

include_directories(Freeglut/freeglut/freeglut/src)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -std=c++11 -lGLEW -lGLU -lGL")

set(SOURCE_FILES src/main.cpp
                 src/binary_tree.cpp
                 src/binary_tree_impl.cpp
                 src/railway_station.cpp
                 src/train_data.cpp
                 src/binary_tree.h
                 src/railway_station.h
                 src/train_data.h
                 src/drawing_tree.h
                 src/drawing_tree.cpp
                 src/layout.h
                 src/layout.cpp)

add_executable(railway_station ${SOURCE_FILES})

target_link_libraries(railway_station
  glfw freeglut ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
