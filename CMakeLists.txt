# Use at least CMake 3.20 so that we can require C++23 for std::expected
cmake_minimum_required(VERSION 3.20)
project(Flora)

# Do not build the GLFW documentation, even if the system has a Doxygen
# installation available.
set(GLFW_BUILD_DOCS OFF)
add_subdirectory(glfw)

add_executable(flora src/main.cpp)
target_link_libraries(flora PRIVATE glfw)

if(CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
  target_compile_options(flora PRIVATE /Wall)
else()
  target_compile_options(flora PRIVATE -Wall -Wextra -pedantic)
endif()
