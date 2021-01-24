#ifndef HYEHEADER
#define HYEHEADER

struct Pair
{
    char c;
    int n;
};

struct Encoded
{
    int length;
    struct Pair *arr;
};

int size = 1;

struct Encoded *encode();
char *decode();

#include "rle.c"
#endif