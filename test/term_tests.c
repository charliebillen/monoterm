#include "test.h"

#include "../src/term.h"

void test_parse_args_with_min_and_max(void)
{
    char *argv[] = {"app", "001100", "010101"};

    args_t args = {0, 0};
    parse_args(3, argv, &args);

    TEST("parse_args: given min in argv, sets min_colour",
        STR_EQ(argv[1], args.min_colour));
    TEST("parse_args: given max in argv, sets max_colour",
        STR_EQ(argv[2], args.max_colour));
}

void test_parse_args_without_min_and_max(void)
{
    char *argv[] = {"app"};

    args_t args = {0, 0};
    parse_args(1, argv, &args);

    TEST("parse_args: given no min in argv, sets default min_colour",
        STR_EQ(DEFAULT_MIN, args.min_colour));
    TEST("parse_args: given no max in argv, sets default max_colour",
        STR_EQ(DEFAULT_MAX, args.max_colour));
}

int main(void)
{
    test_parse_args_with_min_and_max();
    test_parse_args_without_min_and_max();

    return 0;
}
