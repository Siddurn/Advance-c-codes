/*
Enter the size: 5

Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata
*/
#include <stdio.h>
#include <stdlib.h>

void sort_names(char *strings[20], int size);
int my_strcmp(char *str1, char *str2);

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
     // Clear the input buffer
    while (getchar() != '\n');
    char **strings = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        strings[i] = (char *)malloc(20 * sizeof(char));
    }
    printf("Enter the %d names of length max 20 characters in each\n", size);
    
    int j=0;
    while (scanf("%s", strings[j]) != '\n' && j < size) 
    {
        j++;
    }

    sort_names(strings, size);
    for (int i = 0; i < size; i++)
    {
        fputs(strings[i], stdout);
    }
    for (int i = 0; i < size; i++)
        free(strings[i]);
    free(strings);
    return 0;
}

int my_strcmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
}

void sort_names(char *strings[20], int size)
{
    char *temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (my_strcmp(strings[i], strings[j]) > 0)
            {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}
