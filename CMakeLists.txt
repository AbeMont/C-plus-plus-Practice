cmake_minimum_required(VERSION 3.10)

# Project name
project(SoldierProject)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)

