# Specify minimum version of CMake
cmake_minimum_required(VERSION 3.31)

# Specify CXX standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the binary dir and source dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set project name
project(tte)

# Set the source files for the project
set(SOURCES
    src/tte.c
    # src/terminal.c
    # src/rawIO.c
)

# Create static libraries for the tte program
add_library(terminal STATIC src/terminal.c)
target_include_directories(terminal PUBLIC ${INCLUDE_DIR})

add_library(rawIO STATIC src/rawIO.c)
target_include_directories(rawIO PUBLIC ${INCLUDE_DIR})

add_library(textEditor STATIC src/textEditor.c)
target_include_directories(textEditor PUBLIC ${INCLUDE_DIR})

# Add the program executable file
add_executable(tte ${SOURCES})

# Add include directories
target_include_directories(tte PUBLIC ${INCLUDE_DIR})

# Set C Compiler Flags
target_compile_options(tte PRIVATE -Wall) # Add -Werror

# Add link to static libraries
target_link_libraries(tte PRIVATE terminal rawIO textEditor)
