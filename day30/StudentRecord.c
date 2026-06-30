#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int roll[MAX], marks[MAX];
    char name[MAX][50];
    int n, choice, found;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student records
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &roll[i]);

        printf("Name: ");
        scanf(" %[^\n]", name[i]);

        printf("Marks: ");
        scanf("%d", &marks[i]);
    }

    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Display All Records\n");
        printf("2. Search by Roll Number\n");
        printf("3. Find Highest Marks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n--- Student Records ---\n");
                for (int i = 0; i < n; i++) {
                    printf("Roll No: %d\n", roll[i]);
                    printf("Name   : %s\n", name[i]);
                    printf("Marks  : %d\n", marks[i]);
                    printf("----------------------\n");
                }
                break;

            case 2: {
                int r;
                found = 0;

                printf("Enter roll number to search: ");
                scanf("%d", &r);

                for (int i = 0; i < n; i++) {
                    if (roll[i] == r) {
                        printf("\nRecord Found:\n");
                        printf("Roll No: %d\n", roll[i]);
                        printf("Name   : %s\n", name[i]);
                        printf("Marks  : %d\n", marks[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }
                break;
            }

            case 3: {
                int maxIndex = 0;

                for (int i = 1; i < n; i++) {
                    if (marks[i] > marks[maxIndex]) {
                        maxIndex = i;
                    }
                }

                printf("\nTopper Student:\n");
                printf("Roll No: %d\n", roll[maxIndex]);
                printf("Name   : %s\n", name[maxIndex]);
                printf("Marks  : %d\n", marks[maxIndex]);
                break;
            }

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}