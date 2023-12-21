#include <stdio.h>

#include "colour.h"
#include "term.h"

/*
Useful information on escape/colour codes:
- https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
- https://github.com/webdiscus/ansis
*/

/**
Sets the terminal background colour to the colour provided
*/
void set_background(const colour_t *colour)
{
    printf("\x1b[48;2;%d;%d;%dm", colour->red, colour->green, colour->blue);
}

/**
Resets the terminal
*/
void reset_background()
{
    printf("\x1b[49m");
}

/**
Prints one colour row, name and hexcode
*/
void print_colour_row(const char *name, const colour_t *colour)
{
    printf("%-17s\t", name);
    set_background(colour);
    printf(" #%02x%02x%02x \t", colour->red, colour->green, colour->blue);
    reset_background();
    puts("");
}

/**
Prints the name and a computed hexcode value for every colour defined in names,
based on their corresponding scale entry
*/
void print_colour_table(const char *min_str, const char *max_str)
{
    colour_t min, max;
    colour_from_hex_string(min_str, &min);
    colour_from_hex_string(max_str, &max);

    for (int i = 0; i < NUM_COLOURS; i++)
    {
        float scale = scales[i];
        char *name = names[i];

        colour_t interpolated;
        interpolate_colour(&min, &max, scale, &interpolated);
        print_colour_row(name, &interpolated);
    }
}

void parse_args(const int argc, char *argv[], args_t *args)
{
    char *min_colour = DEFAULT_MIN;
    char *max_colour = DEFAULT_MAX;

    switch (argc)
    {
    case 2:
        min_colour = argv[1];
        max_colour = DEFAULT_MAX;
        break;
    case 3:
        min_colour = argv[1];
        max_colour = argv[2];
        break;
    }

    args->min_colour = min_colour;
    args->max_colour = max_colour;
}
