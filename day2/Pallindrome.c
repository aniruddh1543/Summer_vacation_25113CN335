#include <stdio.h>

int main() {
    int num, original, reverse = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        digit = num % 10;               // Extract last digit
        reverse = reverse * 10 + digit; // Reverse the number
        num /= 10;                      // Remove last digit
    }

    if (original == reverse)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome number\n");

    return 0;
}