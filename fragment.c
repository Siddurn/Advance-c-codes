/*
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1
*/
#include <stdio.h>
#include <stdlib.h>

int fragments(int, int *[]);

int main()
{
    int row,col;
    printf("Enter no. of rows : ");
    scanf("%d",&row);
    float **ptr=malloc((row+1)*sizeof(float));
    ptr[0]=malloc(row*sizeof(float));
    int col_size[row];
    for(int i=1;i<row+1;i++)
    {
        printf("Enter no of columns in row[%d] : ",i-1);
        scanf("%d",&col);
        col_size[i-1]=col;
        ptr[i]=malloc((col+1)*sizeof(float));
    }
    for(int i=1;i<row+1;i++)
    {
        printf("Enter %d values for row[%d] : ",col_size[i-1],i-1);
        for(int j=0;j<col_size[i-1];j++)
        {
            scanf("%f",&(ptr[i][j]));
        }
    }
    
    printf("Values u entered\n");
     for(int i=1;i<row+1;i++)
    {
        printf(" %d values in row[%d] : ",col_size[i-1],i-1);
        for(int j=0;j<col;j++)
        {
            printf("%f ",ptr[i][j]);
        }
        printf("\n");
    }
    return 0;
}