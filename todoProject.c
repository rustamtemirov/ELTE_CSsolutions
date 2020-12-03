#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidTime(char time[5])
{
    if (time[0]=='2' && time[1]>'3')
        return 0;
    else if (time[2]!=':')
        return 0;
    else if (time[0]<'0' || time[0]>'2')
        return 0;
    else if (time[3]>='6' || time[3]<'0')
        return 0;

   else if (time[4]>='0' && time[4]<='9')
        return 1;
    else if (time[1]>='0' && time[1]<='9')
        return 1;

}

int isValidNote(char note[25])
{
for(int i=0; i<strlen(note); i++)
{
    if((note[i]>='a' && note[i]<='z')
       || (note[i]>'A' && note[i]<='Z'))
       return 1;
}
return 0;
}

int main()
{

int taskNum;
printf("How many tasks do you have for today?\n");
scanf("%d",&taskNum);
printf("Please write 'time' and 'note' of your tasks:\n");
getchar();

char str[100];         // Reading whole line of times and notes
scanf("%[^\n]s", &str);   // with scanf regex

int i = 0;
char *p = strtok (str, " ");    // Using strtok to hold time and note in separate arrays
char *lines[100];

while (p != NULL)
{
    lines[i++] = p;
    p = strtok (NULL, " ");
}


FILE *todo;
todo = fopen("todolist.txt", "w");      //

int j=0;
for(i=0; i<taskNum; i++)        // Writing to the file times and note by checking for validity
{

    if(isValidTime(lines[j]) && isValidNote(lines[j+1]))
         fprintf(todo,"%s - %s\n", lines[j], lines[j+1]);
    else
    {
        printf(" Wrong Input\n");
        break;
    }

     j+=2;
}



return 0;

}


