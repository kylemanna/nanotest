#.rst:
# FindNanoTest
# ---------
#
# Locate the Nano Testing Framework.
#
# Defines the following variables:
#
# ::
#
#    NANOTEST_FOUND - Found the Nano Testing framework
#    NANOTEST_INCLUDE_DIR - Include directories
#    NANOTEST_MAIN_SRC - Implementation of main()
#
#
# Example Usage:
#
# ::
#
#     enable_testing()
#     find_package(NanoTest REQUIRED)
#     include_directories(${CMAKE_CURRENT_BINARY_DIR} ${NANOTEST_INCLUDE_DIR})
#
#
# ::
#
#     generate_nanotest_header(foo.c)
#     add_executable(foo foo.c ${NANOTEST_MAIN_SRC})
#
#
# ::
#
#     add_test(AllTestsInFoo foo)


set(NANOTEST_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

find_path(NANOTEST_INCLUDE_DIR nanotest.h HINTS ${NANOTEST_ROOT})
find_file(NANOTEST_MAIN_SRC nanotest_main.c HINTS ${NANOTEST_ROOT})

function(generate_nanotest_header)
    set(GEN ${NANOTEST_ROOT}/generate_nanotest_header.py)
    set(DST autogen_tests.h)
    
    foreach(FIL ${ARGN})
        get_filename_component(ABS_FILE ${FIL} ABSOLUTE)
        list(APPEND SOURCES ${ABS_FILE})
    endforeach()

    add_custom_command(
        DEPENDS ${SOURCES} ${GEN}
        OUTPUT  ${DST}
        COMMAND ${PYTHON_EXECUTABLE}
        ARGS    ${GEN} --output ${DST} ${SOURCES}
        COMMENT "Running header generator for ${DST}"
        VERBATIM )
endfunction()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NanoTest DEFAULT_MSG NANOTEST_INCLUDE_DIR NANOTEST_MAIN_SRC)
