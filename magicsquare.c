/*
Test Case 1:
user@emertxe] ./magic_square
Enter a number: 3
8      1      6
3      5      7
4      9      2

Test Case 2:
Enter a number: 6
Error : Please enter only positive values
*/
#include <stdio.h>
#include <stdlib.h>

void magic_square(int **, int);
void print_square(int **array, int size);

int main()
{
    int size;
    printf("Enter a number: ");
    scanf("%d",&size);
    if (size % 2 == 0 || size <= 0)
    {
        printf("Error: Please enter only positive odd values\n");
        return 1;
    }

    int **array = (int **)calloc(size, sizeof(int *));
    if (array == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = (int *)calloc(size, sizeof(int));
        if (array[i] == NULL)
        {
            printf("Memory allocation failed\n");
            return -1;
        }
    }

    magic_square(array, size);
    print_square(array, size);

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}

void magic_square(int **array, int size)
{
    // Initialize row and col at the top center
    int row = 0, col = size / 2; 
    int prev_row, prev_col;      // declare variables to keep track of previous row and column

    
    array[row][col] = 1; // make first number is 1

    // Run a loop with condition when count reaches size * size
    for (int count = 2; count <= (size * size);)
    {
        
        // keep track of previous row and col
        prev_row = row;
        prev_col = col;

        // Check for condition row value is less than 0th index
        if ((row - 1) < 0)
        {
            row = size - 1; // set row to last row position
        }
        else
        {
            row--; //otherwise decreament row by one 
        }
        //condition: collumn is crossing size limit
        if ((col + 1) > (size - 1))
        {
            col = 0; // set collumn to 0th position(i.e first collumn)
        }
        else
        {
            col++; // otherwise increameent collumn by one
        }

        // Check if the next position is already occupied
        if (array[row][col] != 0)
        {
            // If occupied, go back to the previous position and move one row down
            row = prev_row + 1; // Move one row down from the previous position
            col = prev_col;     // Set column as the previous position
        }

        // Place the next number in the calculated position
        array[row][col] = count; // Place the next number
        count++;                 // Increment the number for the next iteration
    }
}
//Function to print the result
void print_square(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}