/*
Name: Siddhalingesh Neeralagi
Date:11/04/2024
Description:Squeeze the character in s1 that matches any character in the string s2
Sample input:
Enter s1 : Dennis Ritchie
Enter s2 : Linux
Sample Output:
After squeeze s1 : Des Rtche

*/
#include <stdio.h>

void squeeze(char [], char []);

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf("%[^\n]", str1);
    getchar();

    printf("Enter string2:");
    scanf("%[^\n]", str2);
    
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}

//Function Defination
void squeeze(char str1[], char str2[])
{
	//Run a loop on str1 untill it reach null char
	for(int i=0;str1[i]!='\0';i++)
	{
		//Run a loop on str2 untill it reach null char
		for(int j=0;str2[j]!='\0';j++)
		{
			//check for condition when a char of str2 exist in str1
			if(str1[i]==str2[j])
			{
				//run a loop starting from ith position to reaching null char
				for(int k=i;str1[k]!='\0';k++)
				str1[k]=str1[k+1];		//shift the string char to 1 position to previous position
				i--;					//after loop decreament i by 1
				break;					//break the inner loop
			}
		}
	}

}