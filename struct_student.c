#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Students
{
    int roll_no;
    char name[20];
    int marks[10]; // assuming max 10 subs
    double avg;
    char grade;
};

int main()
{
    int no_student;
    printf("Enter no. of students: ");
    scanf("%d", &no_student);
    int no_sub;
    printf("Enter no. of subjects: ");
    scanf("%d", &no_sub);
    while (getchar() != '\n')
        ;
    struct Students S[no_student];
    char subject_name[10][20]; // max len is 20 and max subject is 10
    for (int i = 0; i < no_sub; i++)
    {
        printf("Enter the name of subject %d: ", i + 1);
        fflush(stdin);
        fgets(subject_name[i], 20, stdin);
        subject_name[i][strcspn(subject_name[i], "\n")] = '\0';
    }
    for (int i = 0; i < no_student; i++)
    {
        printf("----------Enter the student details-------------\n");
        printf("Enter the student Roll no.: ");
        scanf("%d", &S[i].roll_no);
        while (getchar() != '\n')
            ;
        printf("Enter the student %d name: ", i + 1);
        fgets(S[i].name, 20, stdin);
        S[i].name[strcspn(S[i].name, "\n")] = '\0';
        S[i].avg = 0; // Initialize average
        for (int j = 0; j < no_sub; j++)
        {
            printf("Enter %s marks: ", subject_name[j]);
            scanf("%d", &S[i].marks[j]);
            S[i].avg += S[i].marks[j]; // Accumulate marks for average calculation
        }
        S[i].avg /= no_sub; // Calculate average
        // Calculate grade
        if (S[i].avg < 50)
            S[i].grade = 'F';
        else if (S[i].avg < 60)
            S[i].grade = 'D';
        else if (S[i].avg < 70)
            S[i].grade = 'C';
        else if (S[i].avg < 80)
            S[i].grade = 'B';
        else
            S[i].grade = 'A';
    }
    printf("----Display Menu----\n");
    printf("1. All student details\n2. Particular student details\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("| %-10s | %-10s |", "Roll No.", "Name");
        for (int j = 0; j < no_sub; j++)
            printf("%-10s |", subject_name[j]);
        printf(" %-10s | %-10s |\n", "Average", "Grade");
        for (int i = 0; i < no_student; i++)
        {
            printf("| %-10d | %-10s |", S[i].roll_no, S[i].name);
            for (int j = 0; j < no_sub; j++)
            {
                printf(" %-10d|", S[i].marks[j]);
            }
            printf(" %-10.2f | %-10c |\n", S[i].avg, S[i].grade);
        }
        break;
    case 2:
        printf("----Menu for Particular student----\n");
        printf("1. Name.\n2. Roll no.\n");
        printf("Enter your choice: ");
        int user_choice;
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
        {
            char check_name[20];
            printf("Enter the name of the student: ");
            while (getchar() != '\n')
                ; // Clear input buffer
            fgets(check_name, 20, stdin);
            check_name[strcspn(check_name, "\n")] = '\0'; // Remove newline character
            int get_index = -1;                           // Initialize with an invalid value
            for (int i = 0; i < no_student; i++)
            {
                if (strcmp(S[i].name, check_name) == 0)
                {
                    get_index = i; // Set index if name matches
                    break;         // No need to continue looping
                }
            }
            if (get_index != -1)
            {
                printf("| %-10s | %-10s |", "Roll No.", "Name");
                for (int j = 0; j < no_sub; j++)
                    printf("%-10s |", subject_name[j]);
                printf(" %-10s | %-10s |\n", "Average", "Grade");
                printf("| %-10d| %-10s |", S[get_index].roll_no, S[get_index].name);
                for (int i = 0; i < no_sub; i++)
                {
                    printf(" %-10d |", S[get_index].marks[i]);
                }
                printf(" %-10.2f | %-10c\n", S[get_index].avg, S[get_index].grade);
            }
            else
            {
                printf("Student not found.\n");
            }
        }
        break;
        case 2:
        {
            int check_rno, get_index;
            printf("Enter Roll no: ");
            scanf("%d", &check_rno);
            for (int i = 0; i < no_student; i++)
            {
                if (S[i].roll_no == check_rno)
                {
                    get_index = i;
                    break;
                }
            }
            if (get_index != -1)
            {
                printf("| %-10s | %-10s |", "Roll No.", "Name");
                for (int i = 0; i < no_sub; i++)
                    printf("%-10s |", subject_name[i]);
                printf(" %-10s | %-10s |\n", "Average", "Grade");
                printf("| %-10d| %-10s |", S[get_index].roll_no, S[get_index].name);
                for (int i = 0; i < no_sub; i++)
                {
                    printf(" %-10d |", S[get_index].marks[i]);
                }
                printf(" %-10.2f | %-10c\n", S[get_index].avg, S[get_index].grade);
            }
            else
            {
                printf("Student not found.\n");
            }
        }
        break;
        default:
            printf("Invalid input\n");
            break;
        }

        break;
    default:
        printf("Invalid input\n");
        break;
    }

    return 0;
}
