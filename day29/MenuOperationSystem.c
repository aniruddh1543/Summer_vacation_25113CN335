#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

int main() {
    char str1[MAX], str2[MAX], result[MAX];
    int choice, len;

    while (1) {
        printf("\n===== MENU DRIVEN STRING OPERATIONS =====\n");
        printf("1. Input String\n");
        printf("2. Display String\n");
        printf("3. Find Length\n");
        printf("4. Copy String\n");
        printf("5. Concatenate Strings\n");
        printf("6. Compare Strings\n");
        printf("7. Reverse String\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {

            case 1:
                printf("Enter first string: ");
                fgets(str1, MAX, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                break;

            case 2:
                printf("String: %s\n", str1);
                break;

            case 3:
                len = strlen(str1);
                printf("Length of string: %d\n", len);
                break;

            case 4:
                strcpy(result, str1);
                printf("Copied string: %s\n", result);
                break;

            case 5:
                printf("Enter second string: ");
                fgets(str2, MAX, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcpy(result, str1);
                strcat(result, str2);

                printf("Concatenated string: %s\n", result);
                break;

            case 6:
                printf("Enter second string: ");
                fgets(str2, MAX, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 7:
                len = strlen(str1);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--) {
                    printf("%c", str1[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}