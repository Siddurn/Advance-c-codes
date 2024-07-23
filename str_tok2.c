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

char *my_strtok(char str[], const char delim[]) 
{
    int i;   
    static int prev_index ,length;
    static char str_cp[50];
     if (str != NULL) 
     {
        
        for (i = 0; str[i] != '\0'; i++) {
            str_cp[i] = str[i];
        }
        length=i;
        str_cp[i]='\0';
        for(i=0;str[i]!='\0';i++)
        {
            for(int j=0;str[j]!='\0';j++)
            {
                if(str_cp[i]==delim[j])
                {
                    str_cp[i]='\0';
                }
            }
        }
        return &str_cp[0];

     }

     else
     {
        if(prev_index>length)
        return NULL;
        
        for(i=prev_index;str_cp!='\0';i++);
        int pres_index=prev_index;
        prev_index=i+1;
        


     }
}
