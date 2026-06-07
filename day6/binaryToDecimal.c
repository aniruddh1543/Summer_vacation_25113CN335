#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        remainder = binary % 10;      // Get last digit
        decimal += remainder * base;  // Add to decimal value
        binary = binary / 10;         // Remove last digit
        base = base * 2;              // Increase base (2^n)
    }

    printf("Decimal: %d\n", decimal);

    return 0;
}