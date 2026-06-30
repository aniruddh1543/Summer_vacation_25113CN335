#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for contact details
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact c[MAX];
int count = 0;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Add contact
void addContact() {
    if (count < MAX) {
        printf("Enter Name: ");
        scanf(" %[^\n]", c[count].name);

        printf("Enter Phone: ");
        scanf(" %[^\n]", c[count].phone);

        printf("Enter Email: ");
        scanf(" %[^\n]", c[count].email);

        count++;

        printf("Contact added successfully!\n");
    } else {
        printf("Contact list is full!\n");
    }
}

// Display contacts
void displayContacts() {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name : %s\n", c[i].name);
        printf("Phone: %s\n", c[i].phone);
        printf("Email: %s\n", c[i].email);
        printf("----------------------\n");
    }
}

// Search contact
void searchContact() {
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(c[i].name, name) == 0) {
            printf("\nContact Found:\n");
            printf("Name : %s\n", c[i].name);
            printf("Phone: %s\n", c[i].phone);
            printf("Email: %s\n", c[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Delete contact
void deleteContact() {
    char name[50];
    int found = 0;

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(c[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                c[j] = c[j + 1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}