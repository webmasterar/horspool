//License MIT 2016 Ahmad Retha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "horspool.h"

void preprocess(int ** B, const char * p, unsigned int m)
{
    int i, j;
    for (i = 0; i < CHARLIMIT; i++) {
        (* B)[i] = m;
    }
    for (i = 0, j = m - 1; i < m - 1; i++, j--) {
        (* B)[p[i]] = j;
    }
}

void search(const char * t, unsigned int n, const char * p, unsigned int m)
{
    int * B;
    B = malloc(CHARLIMIT * sizeof(int));

    preprocess(&B, p, m);

    unsigned int j, i = 0;
    while (i <= n - m)
    {
        j = m - 1;
        while (j > 0 && t[i + j] == p[j]) {
            j--;
        }
        if (j == 0) {
            printf("Match found at position: %u\n", i);
        }
        i += B[t[i + j]];
    }

    free(B);
}
