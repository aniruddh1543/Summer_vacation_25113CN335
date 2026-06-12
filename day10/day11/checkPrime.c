#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
    int i;

    if (n <= 1)
        return 0;   // Not prime

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;   // Not prime
    }

    return 1;   // Prime
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a Prime number.\n", num);
    else
        printf("%d is not a Prime number.\n", num);

    return 0;
}