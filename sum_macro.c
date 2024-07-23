#include <stdio.h>
#define SUM(num1, num2) (num1 + num2)

int main()
{
    int num1 = 10, num2 = 5;
    printf("Sum is %d\n", SUM(num1, num2));
    printf("Sum is %d\n", SUM(2, 6));
    scanf("%d", &num2);
    printf("Sum is %d\n", SUM(num1, num2));
}