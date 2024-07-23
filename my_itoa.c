#include <stdio.h>
void itoa(int num, char str[]);

int main()
{
    int num;
    char str[10];
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    itoa(num, str);
    
    printf("Integer to string is %s", str);
}

void itoa(int num, char str[])
{
    int flag=1; //1 pos 0 neg 
   
    if(num==0)
    {
        str[0]='0';
        str[1]='\0';
        return;
    }
    if(num<0)
    {
        flag=0;
        num=-num;
    }
    int i;
    for(i=0;num>0;i++)
    {
       str[i]='0'+num%10;
       num/=10; 
    }
    str[i]='\0';
    char *p,*q,tmp;
    p=&str[0];
    q=&str[i-1];
    for(;p<q;)
    {
        tmp=*p;
        *p=*q;
        *q=tmp;
        p++;
        q--;
    }
    if(flag==0)
    {
        str[i+1]='\0';
        for(i;i>0;i--)
        str[i]=str[i-1];
        str[0]='-';
    }

}