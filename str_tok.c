#include <stdio.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);

int main() {
    char str[50], delim[50];

    printf("Enter the string: ");
    scanf("%s", str);
    __fpurge(stdin);

    printf("Enter the delimiter: ");
    scanf("%s", delim);
    __fpurge(stdin);

    char *token = my_strtok(str, delim);
    printf("Tokens:\n");

    while (token != NULL) {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}

char *my_strtok(char str[], const char delim[]) {
    static int prev_index ,length;
    static char str_cp[50];

    if (str != NULL) {
        int i;
        prev_index=0;
        for (i = 0; str[i] != '\0'; i++) {
            str_cp[i] = str[i];
        }
        length=i;
        str_cp[i] = '\0'; // Null-terminate the copied string
    } 

    if(prev_index<length)
        return 0;
    
    int i, j;
    int flag = 1;

    for (i = prev_index; flag ; i++) {
        for (j = 0; delim[j] != '\0'; j++) {
            if (str_cp[i] == delim[j]) {
                str_cp[i] = '\0';
                prev_index = i + 1;
                flag = 0;
                break;
            }
        }
        if (str_cp[i] == '\0') 
            flag = 0;
            prev_index=i+1;
    }

    if (str != NULL) {
        return str_cp;
    } else {
        return (str_cp + prev_index);
    }
}
