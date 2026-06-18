#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Function to add student
void addStudent()
{
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].rollNo);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Record Added Successfully!\n");
}

// Function to display students
void displayStudents()
{
    int i;

    if(count == 0)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n----- Student Records -----\n");

    for(i = 0; i < count; i++)
    {
        printf("\nRoll No : %d", s[i].rollNo);
        printf("\nName    : %s", s[i].name);
        printf("\nMarks   : %.2f\n", s[i].marks);
    }
}

// Function to search student
void searchStudent()
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++)
    {
        if(s[i].rollNo == roll)
        {
            printf("\nRecord Found!");
            printf("\nRoll No : %d", s[i].rollNo);
            printf("\nName    : %s", s[i].name);
            printf("\nMarks   : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("Exiting Program...");
                break;

            default:
                printf("Invalid Choice!");
        }

    } while(choice != 4);

    return 0;
}