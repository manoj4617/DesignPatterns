cmake_minimum_required (VERSION 3.1)

project ("GameOfLife")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


include_directories("/Headers" "/Libs")
include_directories("/home/manoj4617/SDL/SDL/include")

file(GLOB SOURCES "*.cpp")
file(GLOB LIBS "Libs/*")

# Add library files
add_library(gol ${LIBS})
# Add executable
add_executable(GameOfLife ${SOURCES})
# Link libs with source files
target_link_libraries(GameOfLife gol) 

set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 17)


# Enable debug flags for GDB and disable optimization
target_compile_options(GameOfLife PRIVATE -g -O0 -Wall)

# TODO: Add tests and install targets if needed.
