/*
 * NanoTest header to include in all unit test files
 *
 * Author: Kyle Manna <kyle[at]kylemanna[d0t]com>
 */
#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

struct nanotest_unit;

typedef void (nanotest_func)(struct nanotest_unit* nanotest_local_ctx);

struct nanotest_fail {
    unsigned int line;
    const char *func;
    char *file;
    char *expr;
};

struct nanotest_unit {
    char* suite;
    char* name;
    nanotest_func* func;
};

/*
 * Usage: NANOTEST(suite, name) { ... }
 */
#define NANOTEST(s,n) void s##_##n(struct nanotest_unit*); \
        struct nanotest_unit test_##s##_##n = { \
            .suite = #s, \
            .name = #n, \
            .func = s##_##n, \
        }; \
        void s##_##n(__attribute__((unused)) struct nanotest_unit* nanotest_local_ctx)

#define TEST_ASSERT(test) do { if (!(test)) { \
                                    g_nanotest_fail.line = __LINE__; \
                                    g_nanotest_fail.func = __func__; \
                                    g_nanotest_fail.file = __FILE__; \
                                    g_nanotest_fail.expr  = #test; \
                                    longjmp(g_nanotest_jmpbuf, 1); \
                                } } while (0)

/* Shared globals */
extern struct nanotest_fail g_nanotest_fail;
extern jmp_buf g_nanotest_jmpbuf;

#define EXPECT_TRUE(x)  TEST_ASSERT( x)
#define EXPECT_FALSE(x) TEST_ASSERT(!x)
#define EXPECT_EQ(x, y) TEST_ASSERT((x) == (y))
#define EXPECT_NE(x, y) TEST_ASSERT((x) != (y))
