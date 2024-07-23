#include <stdio.h>

int getword(char str[]);

int main()
{
        int len = 0;
	    char str[100];

		printf("Enter the string : ");
		scanf(" %[^\n]", str);

		len = getword(str);

        printf("You entered %s and the length is %d\n", str, len);
}

int getword(char str[])
{
    //initialize a count variable with zero
    int count=0;
    //reun loop untill a space or null charecter
    while(*str != ' ' && *str !='\0')
    {
        //increament the count and str by 1
       count++;
       str++;
    }
    //replace the space with null charecter
    *str='\0';
    //return the count value representing length of word
    return count;
}