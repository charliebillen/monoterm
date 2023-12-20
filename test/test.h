#ifndef __TEST_H
#define __TEST_H

#include <stdio.h>
#include <stdlib.h> // IWYU pragma: keep
#include <string.h> // IWYU pragma: keep

#define TEST(name, test)                                                      \
    do                                                                        \
    {                                                                         \
        if (!(test))                                                          \
        {                                                                     \
            fprintf(stderr, "%s failed\n", name);                             \
            exit(-1);                                                         \
        }                                                                     \
        printf("%s passed\n", name);                                          \
    } while (0)

#define EQ(i, j) (i == j)

#endif // __TEST_H
