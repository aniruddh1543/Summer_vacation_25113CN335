#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store student marks
struct Student {
    int rollNo;
    char name[50];
    int marks1, marks2, marks3, marks4, marks5;
    int total;
    float percentage;
    char grade;
};

struct Student s[MAX];
int count = 0;

// Function prototypes
void addStudent();
void generateMarksheet();
void displayAll();

int main() {
    int choice;

    while (1) {
        printf("\n===== MARKSHEET GENERATION SYSTEM =====\n");
        printf("1. Add Student Marks\n");
        printf("2. Generate Marksheet\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                generateMarksheet();
                break;
            case 3:
                displayAll();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Add student marks
void addStudent() {
    if (count < MAX) {
        printf("Enter Roll Number: ");
        scanf("%d", &s[count].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[count].name);

        printf("Enter marks of 5 subjects:\n");
        scanf("%d %d %d %d %d",
              &s[count].marks1,
              &s[count].marks2,
              &s[count].marks3,
              &s[count].marks4,
              &s[count].marks5);

        s[count].total = 0;
        s[count].percentage = 0;
        s[count].grade = 'F';

        count++;

        printf("Student record added successfully!\n");
    } else {
        printf("Database full!\n");
    }
}

// Generate marksheet
void generateMarksheet() {
    int roll, found = 0;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {

            s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3 +
                         s[i].marks4 + s[i].marks5;

            s[i].percentage = s[i].total / 5.0;

            if (s[i].percentage >= 90)
                s[i].grade = 'A';
            else if (s[i].percentage >= 75)
                s[i].grade = 'B';
            else if (s[i].percentage >= 60)
                s[i].grade = 'C';
            else if (s[i].percentage >= 40)
                s[i].grade = 'D';
            else
                s[i].grade = 'F';

            printf("\n===== MARKSHEET =====\n");
            printf("Roll No: %d\n", s[i].rollNo);
            printf("Name: %s\n", s[i].name);
            printf("Total Marks: %d\n", s[i].total);
            printf("Percentage: %.2f\n", s[i].percentage);
            printf("Grade: %c\n", s[i].grade);
            printf("=====================\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Display all students
void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");

    for (int i = 0; i < count; i++) {
        printf("Roll No: %d\n", s[i].rollNo);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %d %d %d %d %d\n",
               s[i].marks1, s[i].marks2, s[i].marks3,
               s[i].marks4, s[i].marks5);
        printf("------------------------\n");
    }
}