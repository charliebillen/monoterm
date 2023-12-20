#include <stdlib.h>
#include <string.h>

#include "colour.h"

colour_t *colour_from_hex_string(const char *string)
{
    colour_t *colour = malloc(sizeof(colour_t));

    int min = strtol(string, NULL, 16);
    memcpy(colour, &min, sizeof(colour_t));

    return colour;
}

/*
Uses linear interpolation to find a value such that:
- min <= value <= max
- value is min when scale is 0
- value is max when scale is 1
*/
byte_t interpolate_value(const byte_t min, const byte_t max, const float scale)
{
    return min + (max - min) * scale;
}

colour_t *interpolate_colour(
    const colour_t *min, const colour_t *max, const float scale)
{
    colour_t *interpolated = malloc(sizeof(colour_t));

    interpolated->red = interpolate_value(min->red, max->red, scale);
    interpolated->green = interpolate_value(min->green, max->green, scale);
    interpolated->blue = interpolate_value(min->blue, max->blue, scale);

    return interpolated;
}
