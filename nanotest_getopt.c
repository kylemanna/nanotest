#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <string.h>

#include <nanotest.h>

#include <autogen_tests.h>

/* Global pointers to test state.  Neither are thread safe in this case
 * and there is a race condition on callees corrupting them if they should
 * crash during test.
 *
 * FIXME: Not thread safe.
 */
struct nanotest_fail g_nanotest_fail;
jmp_buf g_nanotest_jmpbuf;

/* Declared as global to prevent clobbering by setjmp/longjmp() */
static struct nanotest_unit** ptr = autogen_tests;
static struct nanotest_unit* test;
static int tests_run = 0;
static int tests_failed = 0;

struct test_args {
    char *suite;
    char *name;
};

static int parse_args(struct test_args* args, int argc, char* argv[])
{
    int c;

    while ((c = getopt (argc, argv, "s:n:")) != -1) {
        switch (c)
        {
            case 's':
                args->suite = optarg;
                break;
            case 'n':
                args->name = optarg;
                break;
            default:
                assert(0);
                break;
        }
    }

    return 0;
}

int main(int argc, char* argv[])
{
    struct test_args args;
    memset(&args, 0, sizeof(args));

    parse_args(&args, argc, argv);

    /* Iterate until the end of array NULL pointer is encountered */
    while ((test = *ptr++)) {

        /* Skip all but the specified tests */
        if ((args.suite && strncmp(args.suite, test->suite, strlen(args.suite))) ||
            (args.name  && strncmp(args.name,  test->name,  strlen(args.name)))) {
            printf("[Skipping      ] %s::%s\n", test->suite, test->name);
            continue;
        }
        printf("[Running       ] %s::%s\n", test->suite, test->name);

        /* Jump back to this point if a test fails */
        int ret = setjmp(g_nanotest_jmpbuf);

        if (!ret) {

            test->func(test);

            /* Only gets to this line if longjmp() isn't called first */
            printf("[          Done] %s::%s\n", test->suite, test->name);

        } else {

            printf("[        FAILED] %s::%s %s:%u\n", test->suite, test->name,
                                                      g_nanotest_fail.file,
                                                      g_nanotest_fail.line);

            printf("[           MSG] %s::%s assert( %s )\n", test->suite, test->name,
                                                             g_nanotest_fail.expr);

            tests_failed += 1;
        }

        tests_run += 1;
    }
    printf("=========================================\n");
    printf("Tests run: %d\n",tests_run);
    printf("Tests failed: %d\n", tests_failed);

    return (tests_failed ? 1 : 0);
}
