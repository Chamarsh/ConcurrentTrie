cmake_minimum_required(VERSION 3.10)  # Set the minimum version of CMake

project(TrieProject)  # Set your project's name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the src directory
include_directories(src)

# Add source files
set(SOURCES
    src/main.cpp
    src/Trie.cpp
    src/TrieNode.cpp
)

# Define the executable
add_executable(TrieExecutable ${SOURCES})

# Link any necessary libraries here
# For example: target_link_libraries(TrieExecutable some_library)
