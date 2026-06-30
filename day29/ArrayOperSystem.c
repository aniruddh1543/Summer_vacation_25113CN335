#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;

// Function prototypes
void createArray();
void displayArray();
void insertElement();
void deleteElement();
void searchElement();

int main() {
    int choice;

    while (1) {
        printf("\n===== MENU DRIVEN ARRAY OPERATIONS =====\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                searchElement();
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

// Create array
void createArray() {
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("Invalid size!\n");
        size = 0;
        return;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array created successfully!\n");
}

// Display array
void displayArray() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert element
void insertElement() {
    int pos, value;

    if (size >= MAX) {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position (0 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 0 || pos > size) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;

    printf("Element inserted successfully!\n");
}

// Delete element
void deleteElement() {
    int pos;

    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Element deleted successfully!\n");
}

// Search element
void searchElement() {
    int value, found = 0;

    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found!\n");
    }
}