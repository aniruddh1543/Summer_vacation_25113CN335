#include <stdio.h>

// Function to find factorial
long long factorial(int n) {
    long long fact = 1;
    int i;

    if (n < 0)
        return -1;   // Factorial not defined for negative numbers

    for (i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    long long result = factorial(num);

    if (result == -1)
        printf("Factorial not defined for negative numbers.\n");
    else
        printf("Factorial of %d = %lld\n", num, result);

    return 0;
}