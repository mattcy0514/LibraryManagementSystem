cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Include directories
include_directories(inc)

# Check if sources were found
if(NOT SOURCES)
    message(FATAL_ERROR "No source files (*.cpp) found in src/ directory!")
endif()

# Add executable target
add_executable(library_management ${SOURCES})

# Set output directory for executables
set_target_properties(library_management
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)
