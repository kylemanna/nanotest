cmake_minimum_required(VERSION 3.1)

# Set appropriately in top level project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake")

project(basic)

find_package(NanoTest)

set(SRCS "basic.c")

generate_nanotest_header(${SRCS})

add_executable(basic ${SRCS} ${NANOTEST_MAIN_SRC} "autogen_tests.h")
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${NANOTEST_INCLUDE_DIR})

enable_testing()
add_test(basic basic)
