#include <stdio.h>

struct Book
{
    int bookId;
    char title[50];
    char author[50];
};

int main()
{
    struct Book books[100];
    int n, i;

    printf("Enter number of books: ");
    scanf("%d", &n);

    // Input book details
    for(i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &books[i].bookId);

        printf("Enter Book Title: ");
        scanf("%s", books[i].title);

        printf("Enter Author Name: ");
        scanf("%s", books[i].author);
    }

    // Display book details
    printf("\n===== Library Records =====\n");

    for(i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("Book ID : %d\n", books[i].bookId);
        printf("Title   : %s\n", books[i].title);
        printf("Author  : %s\n", books[i].author);
    }

    return 0;
}