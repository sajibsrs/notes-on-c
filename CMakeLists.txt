cmake_minimum_required(VERSION 3.5.0)
project(notes VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)

add_executable(${PROJECT_NAME}
    main.c
    src/memory/dynamic/person.c
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
