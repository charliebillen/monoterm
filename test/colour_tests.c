#include <stdio.h>
#include <stdlib.h>

#include "../src/colour.h"
#include "test.h"

void test_colour_from_hex_string(void)
{
    colour_t *col = colour_from_hex_string("ffee22");

    TEST("colour_from_hex_string: red byte", EQ(col->red, 0xff));
    TEST("colour_from_hex_string: green byte", EQ(col->green, 0xee));
    TEST("colour_from_hex_string: blue byte", EQ(col->blue, 0x22));

    free(col);
}

void test_interpolate_colour(void)
{
    colour_t min = {.red = 0, .green = 0, .blue = 0};
    colour_t max = {.red = 255, .green = 255, .blue = 255};

    colour_t *interpolated = NULL;

    interpolated = interpolate_colour(&min, &max, 0);

    TEST("interpolate_colour: 0 red", EQ(interpolated->red, 0));
    TEST("interpolate_colour: 0 green", EQ(interpolated->green, 0));
    TEST("interpolate_colour: 0 blue", EQ(interpolated->blue, 0));

    free(interpolated);

    interpolated = interpolate_colour(&min, &max, 0.5);

    TEST("interpolate 0.5 red", EQ(interpolated->red, 127));
    TEST("interpolate 0.5 green", EQ(interpolated->green, 127));
    TEST("interpolate 0.5 blue", EQ(interpolated->blue, 127));

    free(interpolated);

    interpolated = interpolate_colour(&min, &max, 1);

    TEST("interpolate_colour: 1 red", EQ(interpolated->red, 255));
    TEST("interpolate_colour: 1 green", EQ(interpolated->green, 255));
    TEST("interpolate_colour: 1 blue", EQ(interpolated->blue, 255));

    free(interpolated);
}

int main(void)
{
    test_colour_from_hex_string();
    test_interpolate_colour();

    return 0;
}
