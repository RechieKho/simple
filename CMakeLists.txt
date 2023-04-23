cmake_minimum_required(VERSION 3.18)

project(
    simple
    LANGUAGES C
    VERSION 0.0.1
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TYPES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/types)
set(MACROS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/macros)

file(GLOB_RECURSE ${TYPES_DIR}/*.c TYPES_SRCS)
file(GLOB_RECURSE ${MACROS_DIR}/*.c MACROS_SRCS)

add_library(
    simple 
    ${TYPES_SRCS} ${MACROS_SRCS}
)

target_include_directories(
    simple PRIVATE ${TYPES_DIR} ${MACROS_DIR}
)
