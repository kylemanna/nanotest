#include <string.h>

#include <nanotest.h>

NANOTEST(Basic, HelloWorld)
{
    EXPECT_EQ(11, strlen("Hello World"));
}
