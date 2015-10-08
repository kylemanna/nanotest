# Cross Compiled Embedded System Test Example

Runs an extremely simple that can be optionally compiled for the native host or for a microcontroller such as a Cortex-M3.

## Requirements

To build and run the following packages are required (package names for Arch Linux given):
* arm-none-eabi-gcc
* arm-none-eabi-newlib
* qemu
* qemu-arch-extra

## Build for ARM Cortex-M3

Drop the `-DCMAKE_TOOLCHAIN_FILE=gcc_stm32.cmake` argument to `cmake` to build for native host.

    mkdir build
    cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=gcc_stm32.cmake ..
    make
    make test ARGS=-V

## Approximate Output

    ❯ cmake -DCMAKE_TOOLCHAIN_FILE=gcc_stm32.cmake .. && make && make test ARGS=-V
    -- Found NanoTest: /nanotest  
    -- No TOOLCHAIN_PREFIX specified, using default: /usr
    -- No TARGET_TRIPLET specified, using default: arm-none-eabi
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /nanotest/examples/embedded/build
    [ 25%] Running header generator for autogen_tests.h
    Scanning dependencies of target embedded
    [ 75%] Building C object CMakeFiles/embedded.dir/embedded.c.obj
    [ 75%] Building C object CMakeFiles/embedded.dir/nanotest/nanotest_main.c.obj
    [100%] Linking C executable embedded
    [100%] Built target embedded
    Running tests...
    UpdateCTestConfiguration  from :/nanotest/examples/embedded/build/DartConfiguration.tcl
    UpdateCTestConfiguration  from :/nanotest/examples/embedded/build/DartConfiguration.tcl
    Test project /nanotest/examples/embedded/build
    Constructing a list of tests
    Done constructing a list of tests
    Checking test dependency graph...
    Checking test dependency graph end
    test 1
        Start 1: embedded

    1: Test command: /usr/bin/qemu-arm "embedded"
    1: Test timeout computed to be: 9.99988e+06
    1: [Running       ] Embedded::ARMv7HelloWorld
    1: [          Done] Embedded::ARMv7HelloWorld
    1: =========================================
    1: Tests run: 1
    1: Tests failed: 0
    1/1 Test #1: embedded .........................   Passed    0.00 sec

    100% tests passed, 0 tests failed out of 1

    Total Test time (real) =   0.01 sec
