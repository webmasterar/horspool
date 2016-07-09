//License MIT 2016 Ahmad Retha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "horspool.h"

int main(int argc, char ** argv)
{
    if (argc != 3) {
        fprintf(stderr, "Invalid arguments! Usage: ./horspool TEXT PATTERN\n");
        return 1;
    }
    unsigned int n = strlen(argv[1]);
    unsigned int m = strlen(argv[2]);
    if (m > n) {
        fprintf(stderr, "Error. Pattern cannot be longer than text.\n");
        return 1;
    }
    search(argv[1], n, argv[2], m);
    return 0;
}
