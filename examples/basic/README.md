# Basic Test Example

Runs an extremely simple file from a standalone CMake project.

## Build

    mkdir build
    cd build
    cmake ..
    make
    make test ARGS=-V

## Output

Approximate output:

    ❯ cmake .. && make && make test ARGS=-V
    -- The C compiler identification is GNU 5.2.0
    -- The CXX compiler identification is GNU 5.2.0
    -- Check for working C compiler: /usr/bin/cc
    -- Check for working C compiler: /usr/bin/cc -- works
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Check for working CXX compiler: /usr/bin/c++
    -- Check for working CXX compiler: /usr/bin/c++ -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Found NanoTest: /nanotest  
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /nanotest/examples/basic/build
    [ 25%] Running header generator for autogen_tests.h
    Scanning dependencies of target basic
    [ 75%] Building C object CMakeFiles/basic.dir/basic.c.o
    [ 75%] Building C object CMakeFiles/basic.dir/nanotest/nanotest_main.c.o
    [100%] Linking C executable basic
    [100%] Built target basic
    Running tests...
    UpdateCTestConfiguration  from :/nanotest/examples/basic/build/DartConfiguration.tcl
    UpdateCTestConfiguration  from :/nanotest/examples/basic/build/DartConfiguration.tcl
    Test project /nanotest/examples/basic/build
    Constructing a list of tests
    Done constructing a list of tests
    Checking test dependency graph...
    Checking test dependency graph end
    test 1
        Start 1: basic

    1: Test command: /nanotest/examples/basic/build/basic
    1: Test timeout computed to be: 9.99988e+06
    1: [Running       ] Basic::HelloWorld
    1: [          Done] Basic::HelloWorld
    1: =========================================
    1: Tests run: 1
    1: Tests failed: 0
    1/1 Test #1: basic ............................   Passed    0.00 sec

    100% tests passed, 0 tests failed out of 1

    Total Test time (real) =   0.00 sec
