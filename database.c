#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Person
{
    char name[30];
    unsigned age;
    char job[30];
};

struct Person **iterator;

int size = 10;
int change = 5;
int current = 0;

int isValidChar(char note[30])
{
    int counter = 0;
    for(int i=0; i<strlen(note); i++)
    {
        if(isalpha(note[i]))
           counter++;
    }
    if(counter==strlen(note) && strlen(note)<30)
        return 1;
    else
        return 0;
}



void addition(char n[30],  unsigned a,  char j[30])
{

    printf("Name: ");
    scanf("%s", n);
    while(isValidChar(n) == 0 )
    {
        printf("Please enter again!\n");
        printf("Name: ");
        scanf("%s", n);
    }

    printf("Age: ");
    scanf("%u", &a);

    printf("Job: ");
    scanf("%s", j);
    while(isValidChar(j) == 0)
    {
        printf("Please enter again!\n");
        printf("Job: ");
        scanf("%s", j);
    }

    if (current == size)
    {
    size = size + change;
    iterator = (struct Person **)realloc(iterator, size * sizeof(struct Person*));
    }

    struct Person* guy;
    guy=(struct Person *)malloc(sizeof(struct Person));
    strcpy(guy->name, n);
    guy->age = a;
    strcpy(guy->job, j);
    iterator[current] = guy;
    current++;

}

void listing()
{
    for (int i = 0; i <current; ++i)
    {
    printf("Name: %s Age: %u Job: %s\n", iterator[i]->name, iterator[i]->age, iterator[i]->job);

    }
}
void dealloc()
{
    for (int i = 0; i <current; ++i)
    {
    free(iterator[i]);
    iterator[i] = NULL;
    }
}
int main()
{
    iterator = (struct Person **) malloc(size*sizeof(struct Person*));

    char n[30];
    unsigned a=0;
    char j[30];
    char key;

     while(key!='x')
    {

        printf("Please choose one!\n");
        printf("Press 'a' to add new person to the database\n");
        printf("Press 'l' to list the whole database!\n");
        printf("Press 'x' to  exit from the program.!\n");


        scanf("%c", &key);
        if(key=='x')
        {
           dealloc();
           continue;
        }
        else if (key=='a')
        {
              addition(n, a, j);
        }

        else if (key=='l')
            listing();
        else
            printf("Please enter valid character from given list!\n");

        getchar();
    }

    return 0;
}
