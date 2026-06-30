#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for book details
struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued; // 0 = available, 1 = issued
};

struct Book lib[MAX];
int count = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Add book
void addBook() {
    if (count < MAX) {
        printf("Enter Book ID: ");
        scanf("%d", &lib[count].id);

        printf("Enter Book Title: ");
        scanf(" %[^\n]", lib[count].title);

        printf("Enter Author Name: ");
        scanf(" %[^\n]", lib[count].author);

        lib[count].isIssued = 0;

        count++;

        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

// Display books
void displayBooks() {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", lib[i].id);
        printf("Title: %s\n", lib[i].title);
        printf("Author: %s\n", lib[i].author);
        printf("Status: %s\n", lib[i].isIssued ? "Issued" : "Available");
        printf("----------------------\n");
    }
}

// Search book
void searchBook() {
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lib[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\n", lib[i].id);
            printf("Title: %s\n", lib[i].title);
            printf("Author: %s\n", lib[i].author);
            printf("Status: %s\n", lib[i].isIssued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

// Issue book
void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lib[i].id == id) {
            if (lib[i].isIssued == 0) {
                lib[i].isIssued = 1;
                printf("Book issued successfully!\n");
            } else {
                printf("Book is already issued!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}

// Return book
void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lib[i].id == id) {
            if (lib[i].isIssued == 1) {
                lib[i].isIssued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}