# nanotest

[![Build Status](https://travis-ci.org/kylemanna/nanotest.svg)](https://travis-ci.org/kylemanna/nanotest)

The goal of this unit test framework is to run on limited resource devices like microcontrollers (Cortex-M0/M0+/M3/M4/M7, Cortex-R4/R5/R7) which have as little as 4KB of RAM and no POSIX OS features like fork(), pipe(), malloc() or signal().

The majority of the development can be done the developer's native machine (i.e. Linux) and then easily cross compiled to the target platform.  The high level code must be sufficiently abstracted away from the hardware for this approach to work.  The software can be compiled for the development machine's instruction set or for the embedded device and emulated via `qemu`.

The unit test framework is designed to work on the microcontroller to aid in both development and verification and to enable things like built in self-tests (BISTs) and power on self-tests (POSTs).  The integrated self-tests could ship with the product and provides a framework for basic diagnostics.


Continuous integration tools like [Travis-CI](https://travis-ci.org/kylemanna/nanotest) can (and should!) be employed to automate a series of tests instrumented by this framework.

## Demo

tl;dr;

    git clone https://github.com/kylemanna/nanotest.git
    mkdir nanotest/examples/build
    cd nanotest/examples/build
    cmake ..
    make
    make test ARGS=-V

## Examples

See the [examples](examples) folders and associated READMEs.
