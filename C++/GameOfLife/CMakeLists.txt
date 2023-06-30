cmake_minimum_required (VERSION 3.8)

project ("GameOfLife")


# Add source to this project's executable.
add_executable (GameOfLife "game.cpp" "Headers/GameOfLife.h" "Headers/Matrix.h")

target_link_libraries(GameOfLife PRIVATE stdc++fs)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 17)


# Enable debug flags for GDB and disable optimization
target_compile_options(GameOfLife PRIVATE -g -O0 -Wall)

# TODO: Add tests and install targets if needed.
