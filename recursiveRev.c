#include <stdio.h>

// Global variable to store reversed number
int reverse = 0;

// Recursive function to reverse the number
int reverseNumber(int n)
{
    if (n == 0)
        return reverse;

    reverse = reverse * 10 + (n % 10);
    return reverseNumber(n / 10);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        num = -num;

    printf("Reversed number = %d\n", reverseNumber(num));

    return 0;
}