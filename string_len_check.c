#include <stdio.h>
#include <string.h>

int main() {
  char name[20], id[20], pno[20];

  printf("Enter your name: ");  
  gets(name);      

  printf("Enter your ID: ");
  gets(id); 

  printf("Enter your phone number: ");
  gets(pno); 

  if (strlen(pno) == 10) {
    printf("Name : %s\n", name);
    printf("id : %s\n", id);
    printf("Ph Number : %s\n", pno);
  } else {
    printf("Invalid Mobile number\n");
    printf("Mobile number : %f\n",pno);
    
  }

  return 0;
}
