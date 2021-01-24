#include <stdio.h>

struct Encoded *encode(char enc[255])
{
    struct Encoded *Encoded;
    Encoded = (struct Encoded *)malloc(sizeof(struct Encoded));
    Encoded->length = 1;
    (Encoded->arr) = (struct Pair *)malloc((Encoded->length) * (sizeof(struct Pair)));
    struct Pair *head;
    head = (Encoded->arr);
    for (int i = 0; i < strlen(enc); i++)
    {
        if (enc[i] == enc[i + 1])
        {
            (Encoded->arr)->c = enc[i];
            ((Encoded->arr)->n)++;
        }
        else
        {
            (Encoded->arr)->c = enc[i];
            ((Encoded->arr)->n)++;
            (Encoded->length)++;
            (Encoded->arr) = (struct Pair *)realloc(head, (Encoded->length) * sizeof(struct Pair));
            (Encoded->arr) = (Encoded->arr) + ((Encoded->length) - 1);
        }
    }

    (Encoded->arr) = head;
    return Encoded;
}

char *decode(struct Encoded *Encoded)
{
    char *decode;
    decode = (char *)malloc(size * sizeof(char));
    char *head = decode;
    for (int i = 0; i < (Encoded->length) - 1; i++)
    {
        int j = 0;
        while (j < ((Encoded->arr)->n))
        {
            *decode = (Encoded->arr)->c;
            size++;
            decode = (char *)realloc(head, size * sizeof(char));
            decode = decode + (size - 1);
            j++;
        }
        (Encoded->arr)++;
    }
    decode = head;
    return decode;
}
