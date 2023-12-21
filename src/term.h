#ifndef __TERM_H
#define __TERM_H

#define DEFAULT_MIN "000000"
#define DEFAULT_MAX "ffffff"

#define NUM_COLOURS 20

/*
The colour values to return
*/
static char *names[] = {
    // Normal ANSI colours
    "Black",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magenta",
    "Cyan",
    "White",

    // Bright ANSI colours
    "Bright Black",
    "Bright Red",
    "Bright Green",
    "Bright Yellow",
    "Bright Blue",
    "Bright Magenta",
    "Bright Cyan",
    "Bright White",

    // Terminal background and foreground
    "Background",
    "Foreground",

    // Cursor background and foreground
    "Cursor Background",
    "Cursor Foreground"};

/*
The scale for each colour value between the provided min and max
Taken almost verbatim from
https://github.com/anotherglitchinthematrix/monochrome
*/
static float scales[] = {
    // Normal ANSI colours
    0,
    0.55,
    0.35,
    0.75,
    0.25,
    0.65,
    0.45,
    0.8,

    // Bright ANSI colours
    0.1,
    0.7,
    0.5,
    0.9,
    0.4,
    0.8,
    0.6,
    1,

    // Terminal background and foreground
    0,
    0.8,

    // Cursor background and foreground
    0.9,
    0};

/**
Prints colour table given a min and max hex colour

@param min_colour: a hex string representing the minimum colour, e.g. "000000"
@param max_colour: a hex string representing the maximum colour, e.g. "ffffff"
*/
void print_colour_table(const char *min_colour, const char *max_colour);

/**
Holds the parsed command arguments
*/
typedef struct
{
    char *min_colour;
    char *max_colour;
} args_t;

/**
Parses the command arguments into an (args_t *), providing default values if
necessary

@param argc: the argument count
@param argv: the argument list
@param args: the (args_t *) to populate
*/
void parse_args(const int argc, char *argv[], args_t *args);

#endif // __TERM_H
