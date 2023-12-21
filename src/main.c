#include "term.h"

int main(int argc, char *argv[])
{
    /*
        TODO:
        - Support from 12 bit values, e.g #fff vs #ffffff
    */
    args_t args = {0, 0};
    parse_args(argc, argv, &args);

    print_colour_table(args.min_colour, args.max_colour);

    return 0;
}
