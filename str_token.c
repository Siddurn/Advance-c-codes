#include <stdio.h>
#include <string.h>
void strtoken(char *);
int main() {
  char str1[]=“www.emertxe.com/bangalore”;
  strtoken(str1);
  printf("Update : %s",str1);
  return 0;
}

void strtoken(char *str1)
{
    while(*str1 !='\0')
  {
      if(*str1=='.')
      {
          *str1=' ';
      }
      if(*str1=='/')
      {
          *str1=' ';
      }
      str1++;
  }
}
