cmake_minimum_required(VERSION 3.12)
project(HxtWheelz-Physix)

# Set up file path links do the needed directories
set(GLFW_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libraries")  

# Add the GLFW headers to the include directories
include_directories(${GLFW_INCLUDE_DIRS})

# Find and link the GLFW library
find_package(glfw3 REQUIRED)
link_directories(${GLFW_LIBRARY_DIR})

add_executable(HxtWheelz-Physix 
  src/camera.cpp
  src/glad.c 
  src/main.cpp 
)

# Link the GLFW library to your project
target_link_libraries(HxtWheelz-Physix PRIVATE glfw)