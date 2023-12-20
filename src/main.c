#include "term.h"

int main(int argc, char *argv[])
{
    /*
        TODO:
        - Input validation/sanity checking
        - Default values
        - Support from 12 bit values, e.g #fff vs #ffffff
    */
    print_colour_table(argv[1], argv[2]);

    return 0;
}
