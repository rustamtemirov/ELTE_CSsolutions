#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rle.h"

int main()
{

    char string[255];
    scanf("%s", string);
    int counter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (islower(string[i]) || isdigit(string[i]))
            counter++;
    }
    if (counter != strlen(string))
    {
        printf("Bad Input!\n");
        exit;
    }
    else
    {
        struct Encoded *res = encode(string);
        struct Pair *headForDecode = res->arr;
        for (int i = 0; i < (res->length) - 1; i++)
        {
            printf("%d%c", (headForDecode)->n, (headForDecode)->c);
            (headForDecode)++;
        }
        printf(" -> ");

        char *decoded = decode(res);
        for (int i = 0; i < (size - 1); i++)
        {
            printf("%c", *decoded);
            decoded++;
        }
    }
}