cmake_minimum_required(VERSION 3.5)

include_directories(../include ~/glad/include ./)
if (POLICY CMP0072)
  set(OpenGL_GL_PREFERENCE LEGACY)
endif()

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL)

aux_source_directory(. SOURCE_DIR)
 
add_executable(engine ${SOURCE_DIR})

target_link_libraries(engine glfw3 GL m Xrandr Xi X11 Xxf86vm pthread dl Xinerama Xcursor)
