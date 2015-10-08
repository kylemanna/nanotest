cmake_minimum_required(VERSION 3.1)

# Set appropriately in top level project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake")
set(CMAKE_TOOLCHAIN_FILE "gcc_stm32.cmake")

# Keep find_package outside the project so that the toolchain doesn't mess up
# the find package rooth path.
find_package(NanoTest)

project(embedded)

# Link to the semihosting remote debug interface, note this requires newlib:
# /usr/arm-none-eabi/lib/{rdimon.specs, nano.specs}
set(CMAKE_EXE_LINKER_FLAGS "--specs=rdimon.specs -lrdimon --specs=nano.specs")

set(SRCS "embedded.c")

generate_nanotest_header(${SRCS})

add_executable(embedded ${SRCS} ${NANOTEST_MAIN_SRC} "autogen_tests.h")
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${NANOTEST_INCLUDE_DIR})

enable_testing()

# Note that the qemu-arm emulator is required
add_test(embedded qemu-arm embedded)
