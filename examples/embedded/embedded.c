#include <string.h>

#include <nanotest.h>

NANOTEST(Embedded, ARMv7HelloWorld)
{
    EXPECT_EQ(11, strlen("Hello World"));
}
