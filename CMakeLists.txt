# CMakeLists.txt for electron
# 26-01-2025 by madpl (Bogdan Kułaga)

cmake_minimum_required(VERSION 3.10)

project(electron)
add_definitions(-O3 -march=native -std=c++23)

file(GLOB_RECURSE SOURCE ./source/*)

find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME}
	sfml-system sfml-window sfml-graphics GL GLU)
