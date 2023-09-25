# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date Dec 22 2022
# @brief CMakeLists.txt for the Automaton class 
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(Automaton # Mandatory
    VERSION 1.0
    DESCRIPTION "Automaton"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -pedantic  -Weffc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "vector_main" to be built from the source files listed in the command invocation.
add_executable(automatons
    src/automaton.cc
    src/automaton.h
    src/state.h
    src/transition.h
    src/automatons.cc)

# Add compile options to a target.
target_compile_options(automatons PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
