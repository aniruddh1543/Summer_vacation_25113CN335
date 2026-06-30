#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int id[MAX], issued[MAX];
    char title[MAX][50], author[MAX][50];
    int n = 0, choice, found;

    while (1) {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter Book ID: ");
                scanf("%d", &id[n]);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", title[n]);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", author[n]);

                issued[n] = 0; // 0 = available, 1 = issued

                n++;
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("\n--- Book List ---\n");
                for (int i = 0; i < n; i++) {
                    printf("ID     : %d\n", id[i]);
                    printf("Title  : %s\n", title[i]);
                    printf("Author : %s\n", author[i]);
                    printf("Status : %s\n", issued[i] ? "Issued" : "Available");
                    printf("----------------------\n");
                }
                break;

            case 3: {
                int searchId;
                found = 0;

                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < n; i++) {
                    if (id[i] == searchId) {
                        printf("\nBook Found:\n");
                        printf("ID     : %d\n", id[i]);
                        printf("Title  : %s\n", title[i]);
                        printf("Author : %s\n", author[i]);
                        printf("Status : %s\n", issued[i] ? "Issued" : "Available");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;
            }

            case 4: {
                int searchId;
                found = 0;

                printf("Enter Book ID to issue: ");
                scanf("%d", &searchId);

                for (int i = 0; i < n; i++) {
                    if (id[i] == searchId) {
                        if (issued[i] == 0) {
                            issued[i] = 1;
                            printf("Book issued successfully!\n");
                        } else {
                            printf("Book is already issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;
            }

            case 5: {
                int searchId;
                found = 0;

                printf("Enter Book ID to return: ");
                scanf("%d", &searchId);

                for (int i = 0; i < n; i++) {
                    if (id[i] == searchId) {
                        if (issued[i] == 1) {
                            issued[i] = 0;
                            printf("Book returned successfully!\n");
                        } else {
                            printf("Book was not issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;
            }

            case 6:
                printf("Exiting system...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}