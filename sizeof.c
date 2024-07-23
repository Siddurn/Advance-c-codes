/*
Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes
*/
#include <stdio.h>

//SIZEOF macro is difined
//By subtracting next address with address of actual variable we get size of variable
#define SIZEOF(x) ((char *)(&x + 1) - (char *)&x)

int main()
{
    //Declaring variables of different datatype
    int int_Num = 5;
    float float_Num = 3.2;
    double double_Num = 5.63;
    char ch_Num = 'A';
    unsigned int uint_Num = 23;
    long int lint_Num = 665;
    int *int_ptr = &int_Num;
    char *ch_ptr = &ch_Num;
    //printing size of each variable using SIZEOF macro
    printf("Size of int : %zu bytes\n", SIZEOF(int_Num));
    printf("Size of float : %zu bytes\n", SIZEOF(float_Num));
    printf("Size of double : %zu bytes\n", SIZEOF(double_Num));
    printf("Size of char : %zu bytes\n", SIZEOF(ch_Num));
    printf("Size of unsigned int : %zu bytes\n", SIZEOF(uint_Num));
    printf("Size of long int : %zu bytes\n", SIZEOF(lint_Num));
    printf("Size of int pointer : %zu bytes\n", SIZEOF(int_ptr));
    printf("Size of char pointer : %zu bytes\n", SIZEOF(ch_ptr));
    return 0;
}