cmake_minimum_required(VERSION 2.8)

# Set appropriately in top level project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

project(basic)

find_package(NanoTest)

set(SRCS "basic.c")

generate_nanotest_header(${SRCS})

add_executable(basic ${SRCS} ${NANOTEST_MAIN_SRC} "autogen_tests.h")
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${NANOTEST_INCLUDE_DIR})

enable_testing()
add_test(basic basic)

if (UNIX)
    add_test(NAME basic_memcheck
             COMMAND valgrind --error-exitcode=1 ${CMAKE_CURRENT_BINARY_DIR}/basic)
endif()
