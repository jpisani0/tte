# Specify minimum version of CMake
cmake_minimum_required(VERSION 3.31)

# Specify CXX standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the binary dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Set project name
project(tte)

# Set the source files for the project
set(SOURCES
    src/tte.c
    src/terminal.c
)

# Add the program executable file
add_executable(tte ${SOURCES})

# Add include directories
target_include_directories(tte PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
