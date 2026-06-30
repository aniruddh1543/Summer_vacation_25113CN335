#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store employee salary data
struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float allowance;
    float deductions;
    float netSalary;
};

struct Employee emp[MAX];
int count = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void calculateSalary();

int main() {
    int choice;

    while (1) {
        printf("\n===== SALARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee Salary Details\n");
        printf("2. Display All Salary Records\n");
        printf("3. Calculate Net Salary\n");
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
                calculateSalary();
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

// Add employee salary details
void addEmployee() {
    if (count < MAX) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[count].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp[count].name);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[count].basicSalary);

        printf("Enter Allowance: ");
        scanf("%f", &emp[count].allowance);

        printf("Enter Deductions: ");
        scanf("%f", &emp[count].deductions);

        emp[count].netSalary = 0; // initially 0

        count++;

        printf("Employee salary details added successfully!\n");
    } else {
        printf("Database full!\n");
    }
}

// Calculate net salary
void calculateSalary() {
    int id, found = 0;

    printf("Enter Employee ID to calculate salary: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            emp[i].netSalary = emp[i].basicSalary + emp[i].allowance - emp[i].deductions;

            printf("\nSalary Calculated Successfully!\n");
            printf("Name: %s\n", emp[i].name);
            printf("Net Salary: %.2f\n", emp[i].netSalary);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

// Display all employees
void displayEmployees() {
    if (count == 0) {
        printf("No salary records found.\n");
        return;
    }

    printf("\n--- Salary Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Basic Salary: %.2f\n", emp[i].basicSalary);
        printf("Allowance: %.2f\n", emp[i].allowance);
        printf("Deductions: %.2f\n", emp[i].deductions);
        printf("Net Salary: %.2f\n", emp[i].netSalary);
        printf("------------------------\n");
    }
}