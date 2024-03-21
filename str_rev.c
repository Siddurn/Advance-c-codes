#include <stdio.h>

void str_rev(char *,char *,int);
int main() 
{
  char str1[20]=“Hello World”,str2[20]="";
  str_rev(str1,str2,strlen(str1));
  printf("Reversed string : %s",str2);
  return 0;
}

void str_rev(char *str1,char *str2,int size)
{
    while(*str1!='\0')
    str1++;
    str1--;
    while(size)
    {
        *str2++=*str1--;
        size--;
    }
    *str2='\0';
}
