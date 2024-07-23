#include <stdio.h>

int my_atoi(const char []);

int main()
{
    char str[20];
    
    printf("Enter a numeric string : ");
    scanf(" %s", str);
    
    printf("String to integer is %d\n", my_atoi(str));
}

int my_atoi(const char str[])
{
    //initializing flag to represent the sign of a integer
    int flag=0;//flag 0+ 1-
    //initialize variables digit and integer
    int digit,integer=0;
    //if first charecter is - sign then set flag=1 representing negative value 
    if(*str=='-')
    {
        flag=1;
        //increament str
        str++;
    }
    //if first charecter is + sign then set flag=0 representing positive value
    else if(*str=='+')
    {
        flag=0;
        //increament str
        str++;
    }
    //ren a loop that runs untill null char or within the range of 0-9 
    while(*str != '\0' && *str>= '0'&& *str < '9') 
    {
        //str has a char that is subtracted by '0' to get equivalent integer value
        digit=*str-'0';
        //integer will add the next digit to its position
        integer=integer*10+digit;
        //increament str to point next charecter
        str++;
    }
    //if flag is 1 then return negative value
    if(flag)
    return -integer;
    //if flag is 0 then return positive value
    else
    return integer;

}