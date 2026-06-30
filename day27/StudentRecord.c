#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store student data
struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Add student
void addStudent() {
    if (count < MAX) {
        printf("Enter Roll Number: ");
        scanf("%d", &students[count].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[count].name);

        printf("Enter Age: ");
        scanf("%d", &students[count].age);

        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);

        count++;

        printf("Student added successfully!\n");
    } else {
        printf("Database full!\n");
    }
}

// Display all students
void displayStudents() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("----------------------\n");
    }
}

// Search student
void searchStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}