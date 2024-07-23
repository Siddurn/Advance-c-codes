#include <stdio.h>

int str_len(char *str);
void reverse_recursive(char str[], int ind, int len);

int main()
{
    char str[30];
    int length;
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    length=str_len(str); 
    reverse_recursive(str,0 ,length );
    
    printf("Reversed string is %s\n", str);
}

void reverse_recursive(char str[], int ind, int len)
{

}

int str_len(char *str)
{
    int length=0;
    while(str++)
    {
        length++;
    }
    return length;
}