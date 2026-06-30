#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int id[MAX], age[MAX];
    float salary[MAX];
    char name[MAX][50], dept[MAX][30];

    int n = 0, choice, found;

    while (1) {
        printf("\n===== MINI EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Find Highest Salary Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter Employee ID: ");
                scanf("%d", &id[n]);

                printf("Enter Name: ");
                scanf(" %[^\n]", name[n]);

                printf("Enter Age: ");
                scanf("%d", &age[n]);

                printf("Enter Department: ");
                scanf(" %[^\n]", dept[n]);

                printf("Enter Salary: ");
                scanf("%f", &salary[n]);

                n++;
                printf("Employee added successfully!\n");
                break;

            case 2:
                if (n == 0) {
                    printf("No employee records found.\n");
                    break;
                }

                printf("\n--- Employee Records ---\n");
                for (int i = 0; i < n; i++) {
                    printf("ID        : %d\n", id[i]);
                    printf("Name      : %s\n", name[i]);
                    printf("Age       : %d\n", age[i]);
                    printf("Department: %s\n", dept[i]);
                    printf("Salary    : %.2f\n", salary[i]);
                    printf("------------------------\n");
                }
                break;

            case 3: {
                int searchId;
                found = 0;

                printf("Enter Employee ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < n; i++) {
                    if (id[i] == searchId) {
                        printf("\nEmployee Found:\n");
                        printf("ID        : %d\n", id[i]);
                        printf("Name      : %s\n", name[i]);
                        printf("Age       : %d\n", age[i]);
                        printf("Department: %s\n", dept[i]);
                        printf("Salary    : %.2f\n", salary[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Employee not found!\n");
                }
                break;
            }

            case 4: {
                if (n == 0) {
                    printf("No employee records found.\n");
                    break;
                }

                int maxIndex = 0;

                for (int i = 1; i < n; i++) {
                    if (salary[i] > salary[maxIndex]) {
                        maxIndex = i;
                    }
                }

                printf("\nHighest Salary Employee:\n");
                printf("ID        : %d\n", id[maxIndex]);
                printf("Name      : %s\n", name[maxIndex]);
                printf("Age       : %d\n", age[maxIndex]);
                printf("Department: %s\n", dept[maxIndex]);
                printf("Salary    : %.2f\n", salary[maxIndex]);
                break;
            }

            case 5:
                printf("Exiting system...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}