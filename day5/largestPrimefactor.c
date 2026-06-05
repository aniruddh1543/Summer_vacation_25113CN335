#include <stdio.h>

int main() {
    long long num;
    long long largestFactor = -1;

    printf("Enter a number: ");
    scanf("%lld", &num);

    // Remove factors of 2
    while (num % 2 == 0) {
        largestFactor = 2;
        num /= 2;
    }

    // Check for odd factors
    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            largestFactor = i;
            num /= i;
        }
    }

    // If remaining number is greater than 2, it is prime
    if (num > 2) {
        largestFactor = num;
    }

    if (largestFactor != -1)
        printf("Largest Prime Factor is: %lld\n", largestFactor);
    else
        printf("No prime factors found.\n");

    return 0;
}