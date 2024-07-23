/*
Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB

Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412


*/
#include <stdio.h>

void big_endian(char *, int);

int main()
{
    int num_hex, size;
    char *ptr;
    printf("Enter the size: ");
    scanf("%d", &size);
    printf("Enter any number in Hexadecimal: ");
    scanf("%x", &num_hex);
    ptr = &num_hex;
    big_endian(ptr, size);
    printf("After conversion %X", num_hex);
}

//Function Defination
void big_endian(char *ptr, int size)
{
    //Declare a temp variable of char type
    char temp = 0;
    //For pointer arithematic i and j are defined
    int i = 0, j = size - 1;    
    while (i < j)   //check condition i is less than j
    {
        //swap the bytes pointer is pointing
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
        //increament i and decreament j by 1
        i++;
        j--;
    }
}