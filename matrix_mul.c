#include <stdio.h>
#include <stdlib.h>

void matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
    //Dynamic allocation of mat_a,mat_b and result
    int **mat_a, **mat_b, **result;
    int row1, col1, row2, col2;
    printf("Enter number of rows : ");
    scanf("%d", &row1);
    printf("Enter number of columns : ");
    scanf("%d", &col1);

    mat_a = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
        mat_a[i] = (int *)malloc(col1 * sizeof(int));
    printf("Enter values for %d x %d matrix :\n", row1, col1);
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &mat_a[i][j]);
        }
    }
    /*************************************************/
    printf("Enter number of rows : ");
    scanf("%d", &row2);
    printf("Enter number of columns : ");
    scanf("%d", &col2);
    if (col1 != row2)
    {
        printf("Matrix multiplication is not possible\n");
        return;
    }
    mat_b = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
        mat_b[i] = (int *)malloc(col2 * sizeof(int));
    printf("Enter values for %d x %d matrix :\n", row1, col1);
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &mat_b[i][j]);
        }
    }
    /*************************************************/

    result = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
        result[i] = (int *)malloc(col2 * sizeof(int));
    //calling matrix_mul function
    matrix_mul(mat_a, row1, col1, mat_b, row2, col2, result, row1, col2);
    //Display the result
    printf("Product of two matrix :\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    //free the allocated memory
    for (int i = 0; i < row1; i++)
        free(mat_a[i]);
    free(mat_a);
    for (int i = 0; i < row2; i++)
        free(mat_b[i]);
    free(mat_b);
    for (int i = 0; i < row1; i++)
        free(result[i]);
    free(result);
    return 0;
}

void matrix_mul(int **mat_a, int row1, int col1, int **mat_b, int row2, int col2, int **result, int row3, int col3)
{
    //run a loop for row1 elements
    for (int i = 0; i < row1; i++)
    {
        //run a loop for col2 elements
        for (int j = 0; j < col2; j++)
        {
            //each element of result initial value is 0
            result[i][j] = 0; 
            //run a loop to get col index and row index for mat_a and mat_b respectively
            for (int index = 0; index < col1; index++)
            {
                //add 
                result[i][j] += mat_a[i][index] * mat_b[index][j]; 
            }
        }
    }
}