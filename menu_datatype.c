#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold elements of different types
typedef struct
{
    int type; // Type of the element: 1 for int, 2 for char, 3 for float, 4 for double
    union
    {
        int int_data;
        char char_data;
        float float_data;
        double double_data;
    } data;
} Element;

Element *arr = NULL; // Pointer to dynamically allocated array of elements
int count = 0;       // Current number of elements in the array
int capacity = 0;    // Current capacity of the array

// Function prototypes
void addElement();
void removeElement();
void displayElements();

int main()
{
    int choice;

    do
    {
        printf("\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\nChoice ---> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addElement();
            break;
        case 2:
            removeElement();
            break;
        case 3:
            displayElements();
            break;
        case 4:
            printf("Exiting from the program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory before exiting
    free(arr);

    return 0;
}

void addElement()
{
    int type;

    // Reallocate memory if needed
    if (count >= capacity)
    {
        capacity += 10; // Increase capacity by 10 elements
        arr = realloc(arr, capacity * sizeof(Element));
        if (arr == NULL)
        {
            printf("Memory allocation failed. Cannot add more elements.\n");
            return;
        }
    }

    printf("Enter the type you have to insert:\n1. int\n2. char\n3. float\n4. double\nChoice ---> ");
    scanf("%d", &type);

    switch (type)
    {
    case 1:
        printf("Enter the int : ");
        scanf("%d", &arr[count].data.int_data);
        break;
    case 2:
        printf("Enter the char : ");
        scanf(" %c", &arr[count].data.char_data);
        break;
    case 3:
        printf("Enter the float : ");
        scanf("%f", &arr[count].data.float_data);
        break;
    case 4:
        printf("Enter the double : ");
        scanf("%lf", &arr[count].data.double_data);
        break;
    default:
        printf("Invalid type! Element not added.\n");
        return;
    }

    arr[count].type = type;
    count++;
}

void removeElement()
{
    int index;

    if (count == 0)
    {
        printf("Array is empty. No elements to remove.\n");
        return;
    }

    printf("Enter the index value to be deleted : ");
    scanf("%d", &index);

    if (index < 0 || index >= count)
    {
        printf("Invalid index! Element not removed.\n");
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    count--;
    printf("Index %d successfully deleted.\n", index);
}

void displayElements()
{
    if (count == 0)
    {
        printf("Array is empty. No elements to display.\n");
        return;
    }

    printf("------------------------\n");
    for (int i = 0; i < count; i++)
    {
        switch (arr[i].type)
        {
        case 1:
            printf("%d -> %d (int)\n", i, arr[i].data.int_data);
            break;
        case 2:
            printf("%d -> %c (char)\n", i, arr[i].data.char_data);
            break;
        case 3:
            printf("%d -> %.2f (float)\n", i, arr[i].data.float_data);
            break;
        case 4:
            printf("%d -> %.2lf (double)\n", i, arr[i].data.double_data);
            break;
        default:
            printf("%d -> Invalid type\n", i);
        }
    }
    printf("------------------------\n");
}
