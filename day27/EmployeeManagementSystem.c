#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store employee data
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Employee emp[MAX];
int count = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
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

// Add employee
void addEmployee() {
    if (count < MAX) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[count].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp[count].name);

        printf("Enter Department: ");
        scanf(" %[^\n]", emp[count].department);

        printf("Enter Salary: ");
        scanf("%f", &emp[count].salary);

        count++;

        printf("Employee added successfully!\n");
    } else {
        printf("Database full!\n");
    }
}

// Display all employees
void displayEmployees() {
    if (count == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Department: %s\n", emp[i].department);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("------------------------\n");
    }
}

// Search employee by ID
void searchEmployee() {
    int id, found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].department);
            printf("Salary: %.2f\n", emp[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}