#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for inventory item
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item stock[MAX];
int count = 0;

// Function prototypes
void addItem();
void displayItems();
void searchItem();
void updateItem();
void deleteItem();

int main() {
    int choice;

    while (1) {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
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

// Add item
void addItem() {
    if (count < MAX) {
        printf("Enter Item ID: ");
        scanf("%d", &stock[count].id);

        printf("Enter Item Name: ");
        scanf(" %[^\n]", stock[count].name);

        printf("Enter Quantity: ");
        scanf("%d", &stock[count].quantity);

        printf("Enter Price: ");
        scanf("%f", &stock[count].price);

        count++;

        printf("Item added successfully!\n");
    } else {
        printf("Inventory full!\n");
    }
}

// Display items
void displayItems() {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", stock[i].id);
        printf("Name: %s\n", stock[i].name);
        printf("Quantity: %d\n", stock[i].quantity);
        printf("Price: %.2f\n", stock[i].price);
        printf("----------------------\n");
    }
}

// Search item
void searchItem() {
    int id, found = 0;

    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", stock[i].id);
            printf("Name: %s\n", stock[i].name);
            printf("Quantity: %d\n", stock[i].quantity);
            printf("Price: %.2f\n", stock[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

// Update item
void updateItem() {
    int id, found = 0;

    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &stock[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &stock[i].price);

            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

// Delete item
void deleteItem() {
    int id, found = 0;

    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                stock[j] = stock[j + 1];
            }
            count--;
            printf("Item deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}