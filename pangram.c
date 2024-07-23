#include <stdio.h>
//Function Declaration
int pangram(char[]);
int str_len(char *);
char to_lower(char ch);

int main()
{
    char str[100], flag;
    //Read a string
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[str_len(str) - 1] = '\0';
    //call pangram function
    flag = pangram(str);
    if (flag == 1)
        printf("The Entered String is a Pangram String\n");
    else
        printf("The Entered String is not a Pangram String\n");
    return 0;
}
//Function to find length of string
int str_len(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i+1;
}
//Function which converts uppercase to lower case letter
char to_lower(char ch)
{
   if(ch>='A' && ch<='Z')
   {
        return ch-26;
   }
   return ch;
}
//Function Defination
int pangram(char str[])
{
    //declare an array of size 26
    int char_check[26];
    //declare a char variable
    char ch;
    //loop runs for 26 times to make all bits zero
    for (int i = 0; i < 26; i++)
        char_check[i] = 0;
    //loop runs untill it encounter with null charecter of string    
    for (int i = 0; str[i] != '\0'; i++)
    {
        //convert the char to lower case using to_lower function
        ch = to_lower(str[i]);
        //if condition checks the char is in between a to z
        if (ch >= 'a' && ch <= 'z')
        {
            //index positon reffering to order of alphabet is made 1  
            char_check[ch - 'a'] = 1;
        }
    }
    //loop to check all elements are 1 or not
    for (int i = 0; i < 26; i++)
    {
        if (char_check[i] == 0)
        {
            return 0;
        }
    }
    // return 1 for str being pangram string
    return 1;
}