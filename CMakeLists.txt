cmake_minimum_required(VERSION 3.14)
project("Sorting")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_C_FLAGS "-g -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g3 -fsanitize=address,undefined")
set(CMAKE_C_FLAGS_RELEASE "-O3 -flto")

file(GLOB MAIN_SOURCES 
    source/*.c
    source/sorting/*.c
    source/files/*.c
    source/strings/*.c
)
add_executable(Main ${MAIN_SOURCES})

target_include_directories(Main PUBLIC
    source/
    source/sorting
    source/files
    source/strings
)

