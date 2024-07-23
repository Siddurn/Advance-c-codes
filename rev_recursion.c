/*
Name: Siddhalingesh Neeralagi
Date:11/04/2024
Description: 
Sample input:

Sample Output:

*/
#include <stdio.h>
int str_len(char *str);
void reverse_recursive(char str[], int ind, int len);

int main()
{
	char str[30];
	int length;

	printf("Enter any string : ");
	scanf("%[^\n]", str);
	length = str_len(str);
	reverse_recursive(str, 0, length - 1);

	printf("Reversed string is %s\n", str);
}

// Declare a functon to find length of string
int str_len(char *str)
{
	int length;
	// run a loop untill *str is equal to null char
	while (*str++ != '\0')
		length++;  // increament the length
	return length; // return length
}

// Declare a functon to reverse the string
void reverse_recursive(char str[], int ind, int len)
{

	char temp;		// declre a temp char variable
	if (ind >= len) // check for base conditon index is more then equal to length
	{
		// base condition
		return; // return nothing (exit from function)
	}
	// swapping charecters from two different position
	temp = str[ind]; // store current index char to temp variable
	str[ind] = str[len];
	str[len] = temp;
	// call recursion function with increament index and decreament length by 1
	reverse_recursive(str, ind + 1, len - 1);
}