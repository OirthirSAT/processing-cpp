# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(MarchingSquares LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Collect all source files in the src directory
file(GLOB SRC_FILES src/*.cpp)

# Collect all header files in the include directory (.h and .hpp)
file(GLOB HEADER_FILES include/*.h include/*.hpp)

# Add the executable with all sources
add_executable(MarchingSquares main.cpp ${SRC_FILES} ${HEADER_FILES})