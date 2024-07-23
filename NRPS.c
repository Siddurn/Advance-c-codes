#include <stdio.h>

void nrps(char[], int, int);

int main()
{
  int N, C;

  // read the input from the user
  printf("Enter the number characters C : ");
  scanf("%d", &C);
  printf("Enter the Length of the string N : ");
  scanf("%d", &N);
  char str[C];
  printf("Enter %d distinct characters :", C);
  for (int i = 0; i < C; i++)
  {
    scanf(" %c", &str[i]); // Note the space before %c to skip whitespace characters
  }
  for(int i=0;i<C-1;i++)
  {
    for(int j=i+1;j<C;j++)
    {
      if(str[i]==str[j])
      {
        printf("Error : Enter distinct characters");
        return 0;
      }
    }
  }
  // function call to pass input to the function
  nrps(str, C, N);
  return 0;
}

void nrps(char str[], int C, int N)
{
  int i = 0, j = 0;
  // Indices for swapping the first and last character
  int first = 0, last = C - 1; 
 //run a loop untill i reaches length of NRPS series 
  while (i < N)
  {
    j = 0;
    //run  a loop untill j reaches number of distict char and if i reaches leangth of NRPS series 
    while (j < C && i < N)
    {
      printf("%c", str[j]);
      //increament i and j variables
      i++;
      j++;
    }
    // Swap first and last character from str
    char temp = str[first];
    str[first] = str[last];
    str[last] = temp;
  }
  //print a new line charector
  printf("\n");
}