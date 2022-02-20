cmake_minimum_required(VERSION 3.14)
project("Sorting")

set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -flto")

file(GLOB MAIN_SOURCES source/*.c)
add_executable(Main ${MAIN_SOURCES})

target_include_directories(Main PUBLIC
    source/
)

