#include <stdio.h>

int str_cmp(char *,char *,int);
int main() 
{
  char str1[20]=“Be yourself”,str2[20]="Be ourself";
  int n=5,ret;
  ret=str_cmp(str1,str2,n);
  if(ret==n)
  printf("Strings are equal and %d charecters matching",ret);
  else
  printf("Strings are not equal and %d charecters matching",ret);
  
  return 0;
}

int str_cmp(char *str1,char *str2,int n)
{
    int count=0;
    while(n--)
    {
     if(*str1++==*str2++) 
         count++;
    }
    return count;
}
