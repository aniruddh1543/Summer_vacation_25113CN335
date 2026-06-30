#include <stdio.h>
#include <string.h>

#define MAX 100

// Arrays for student data
int roll[MAX];
char name[MAX][50];
int marks[MAX];
int count = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Add student
void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll[count]);

    printf("Enter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Marks: ");
    scanf("%d", &marks[count]);

    count++;
    printf("Student added successfully!\n");
}

// Display students
void displayStudents() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d\n", roll[i]);
        printf("Name   : %s\n", name[i]);
        printf("Marks  : %d\n", marks[i]);
        printf("----------------------\n");
    }
}

// Search student
void searchStudent() {
    int r, found = 0;

    printf("Enter Roll Number to search: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (roll[i] == r) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", roll[i]);
            printf("Name   : %s\n", name[i]);
            printf("Marks  : %d\n", marks[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Update student
void updateStudent() {
    int r, found = 0;

    printf("Enter Roll Number to update: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (roll[i] == r) {
            printf("Enter new name: ");
            scanf(" %[^\n]", name[i]);

            printf("Enter new marks: ");
            scanf("%d", &marks[i]);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Delete student
void deleteStudent() {
    int r, found = 0;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (roll[i] == r) {
            for (int j = i; j < count - 1; j++) {
                roll[j] = roll[j + 1];
                strcpy(name[j], name[j + 1]);
                marks[j] = marks[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}