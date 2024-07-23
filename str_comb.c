#include <stdio.h>

void combination(char[], int, int);
void swap_chars(char *, char *);
int my_strlen(char[]);

int main()

{
        char str[100];
        int n;
        int res;
        printf("Enter a string: ");
        scanf("%100[^\n]", str);
        n = my_strlen(str);
        printf("All possible combinations of given string :");
        combination(str, 0, n - 1);
        return 0;
}
int my_strlen(char str[])
{
        int count = 0;
        while (*str != '\0')
        {
                count++;
                str++;
        }
        return count;
}

void swap_chars(char *ch1, char *ch2)
{
        char tmp;
        tmp = *ch1;
        *ch1 = *ch2;
        *ch2 = tmp;
}

void combination(char str[], int index, int length)
{
        if (index == length)
        {
                str[index + 1] = '\0';
                printf("%s\n", str);
                return;
        }
        for (int i = index; i <= length; i++)
        {
                swap_chars((str + index), (str + i));
                combination(str, index + 1, length);
                swap_chars((str + index), (str + i));
        }
}
