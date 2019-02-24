cmake_minimum_required(VERSION 3.13)
project(agenda C)

set(CMAKE_C_STANDARD 99)

file(GLOB agenda_SRC
    "*.h"
    "*.c"
)

add_executable(agenda ${agenda_SRC})