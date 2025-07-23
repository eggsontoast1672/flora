# Use at least CMake 3.20 so that we can require C++23 for std::expected
cmake_minimum_required(VERSION 3.20)
project(Flora)

add_subdirectory(lib/SFML)

add_executable(flora src/main.cpp)
target_link_libraries(flora PRIVATE sfml-graphics)

if(MSVC)
  target_compile_options(flora PRIVATE /Wall)
else()
  target_compile_options(flora PRIVATE -Wall -Wextra -pedantic)
endif()
