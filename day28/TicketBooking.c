#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for ticket booking
struct Ticket {
    int ticketNo;
    char name[50];
    char source[30];
    char destination[30];
    int isBooked; // 0 = not booked, 1 = booked
};

struct Ticket t[MAX];
int count = 0;

// Function prototypes
void bookTicket();
void displayTickets();
void searchTicket();
void cancelTicket();

int main() {
    int choice;

    while (1) {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayTickets();
                break;
            case 3:
                searchTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Book ticket
void bookTicket() {
    if (count < MAX) {
        printf("Enter Ticket Number: ");
        scanf("%d", &t[count].ticketNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", t[count].name);

        printf("Enter Source: ");
        scanf(" %[^\n]", t[count].source);

        printf("Enter Destination: ");
        scanf(" %[^\n]", t[count].destination);

        t[count].isBooked = 1;

        count++;

        printf("Ticket booked successfully!\n");
    } else {
        printf("All tickets are booked (system full)!\n");
    }
}

// Display tickets
void displayTickets() {
    if (count == 0) {
        printf("No tickets found.\n");
        return;
    }

    printf("\n--- Ticket Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Ticket No: %d\n", t[i].ticketNo);
        printf("Name: %s\n", t[i].name);
        printf("From: %s\n", t[i].source);
        printf("To: %s\n", t[i].destination);
        printf("Status: %s\n", t[i].isBooked ? "Booked" : "Not Booked");
        printf("----------------------\n");
    }
}

// Search ticket
void searchTicket() {
    int ticketNo, found = 0;

    printf("Enter Ticket Number to search: ");
    scanf("%d", &ticketNo);

    for (int i = 0; i < count; i++) {
        if (t[i].ticketNo == ticketNo) {
            printf("\nTicket Found:\n");
            printf("Ticket No: %d\n", t[i].ticketNo);
            printf("Name: %s\n", t[i].name);
            printf("From: %s\n", t[i].source);
            printf("To: %s\n", t[i].destination);
            printf("Status: %s\n", t[i].isBooked ? "Booked" : "Not Booked");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Ticket not found!\n");
    }
}

// Cancel ticket
void cancelTicket() {
    int ticketNo, found = 0;

    printf("Enter Ticket Number to cancel: ");
    scanf("%d", &ticketNo);

    for (int i = 0; i < count; i++) {
        if (t[i].ticketNo == ticketNo) {
            if (t[i].isBooked == 1) {
                t[i].isBooked = 0;
                printf("Ticket cancelled successfully!\n");
            } else {
                printf("Ticket is already not booked!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Ticket not found!\n");
    }
}