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
#include <string.h>

char * str_tok(char str[], char delim[]);

int main() {
    char str[] = "HI.,/;HELLO;:,HOW!AREYOU//.";
    char delim[] = ".,/;:!";
    char *token = NULL;

    token = str_tok(str, delim);
    while (token != NULL) {
        printf("%s\n", token);
        token = str_tok(NULL, delim);
    }
    
    return 0;
}

char * str_tok(char str[], char delim[]) {
    static char *ptr;
    static int length;
    int i;

    if (str != NULL) {
        // Initialize length and set ptr to the start of the string
        length = 0;
        ptr = str;

        // Find the length of the string and replace delimiters with null characters
        for (i = 0; str[i] != '\0'; i++) {
            length++;
            for (int j = 0; delim[j] != '\0'; j++) {
                if (str[i] == delim[j]) {
                    str[i] = '\0';
                    break;
                }
            }
        }
        if (length == 0) {
            return NULL;
        }
        return ptr;
    } else {
        // Handle the case when str is NULL
        if (ptr == NULL || length == 0) {
            return NULL;
        }
        
        while (*ptr == '\0' && length > 0) {
            ptr++;
            length--;
        }

        if (length == 0) {
            return NULL;
        }

        char *start = ptr;
        while (*ptr != '\0' && length > 0) {
            ptr++;
            length--;
        }
        
        return start;
    }
}
