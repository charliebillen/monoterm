#ifndef __TERM_H
#define __TERM_H

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
    0.5,
    0.3,
    0.7,
    0.2,
    0.6,
    0.4,
    0.8,

    // Bright ANSI colours
    0.1,
    0.5,
    0.3,
    0.7,
    0.2,
    0.6,
    0.4,
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

#endif // __TERM_H
