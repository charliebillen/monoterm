#ifndef __COLOUR_H
#define __COLOUR_H

/**
Avoid unexpected signed char issues
*/
typedef unsigned char byte_t;

/**
Colours are backwards because it's used a dirty way and is therefore
subject to the little-endian nature of my machine
*/
typedef struct
{
    byte_t blue;
    byte_t green;
    byte_t red;
} colour_t;

/**
Generates a colour_t representing a given hex colour string

@param string: a string representing a hex colour, e.g. "ff0012"
@param colour: a (colour_t *) such that given the above param
- red = 0xff
- green = 0x00
- blue = 0x12
*/
void colour_from_hex_string(const char *string, colour_t *colour);

/**
Uses linear interpolation to finds a colour between min and max using scale

@param min: the minimum colour
@param max: the maxiumum colour
@param scale: the scale used to find the colour between min and max
@param interpolated: a (colour_t *) representing the interpolated colour
*/
void interpolate_colour(const colour_t *min,
    const colour_t *max,
    const float scale,
    colour_t *interpolated);

#endif // __COLOUR_H
