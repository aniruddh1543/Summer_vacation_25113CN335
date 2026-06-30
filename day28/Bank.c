#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for bank account
struct Account {
    int accNo;
    char name[50];
    float balance;
};

struct Account bank[MAX];
int count = 0;

// Function prototypes
void createAccount();
void displayAccounts();
void searchAccount();
void depositMoney();
void withdrawMoney();

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK ACCOUNT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                depositMoney();
                break;
            case 5:
                withdrawMoney();
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

// Create account
void createAccount() {
    if (count < MAX) {
        printf("Enter Account Number: ");
        scanf("%d", &bank[count].accNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", bank[count].name);

        printf("Enter Initial Deposit: ");
        scanf("%f", &bank[count].balance);

        if (bank[count].balance < 0) {
            printf("Invalid deposit amount!\n");
            return;
        }

        count++;
        printf("Account created successfully!\n");
    } else {
        printf("Bank database full!\n");
    }
}

// Display accounts
void displayAccounts() {
    if (count == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    for (int i = 0; i < count; i++) {
        printf("Account No: %d\n", bank[i].accNo);
        printf("Name: %s\n", bank[i].name);
        printf("Balance: %.2f\n", bank[i].balance);
        printf("----------------------\n");
    }
}

// Search account
void searchAccount() {
    int accNo, found = 0;

    printf("Enter Account Number to search: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (bank[i].accNo == accNo) {
            printf("\nAccount Found:\n");
            printf("Account No: %d\n", bank[i].accNo);
            printf("Name: %s\n", bank[i].name);
            printf("Balance: %.2f\n", bank[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}

// Deposit money
void depositMoney() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (bank[i].accNo == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {
                bank[i].balance += amount;
                printf("Amount deposited successfully!\n");
            } else {
                printf("Invalid amount!\n");
            }
            return;
        }
    }

    printf("Account not found!\n");
}

// Withdraw money
void withdrawMoney() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (bank[i].accNo == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > 0 && amount <= bank[i].balance) {
                bank[i].balance -= amount;
                printf("Please collect your cash!\n");
            } else {
                printf("Insufficient balance or invalid amount!\n");
            }
            return;
        }
    }

    printf("Account not found!\n");
}