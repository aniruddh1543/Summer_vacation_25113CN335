#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1, i;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, original, remainder, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while(num > 0) {
        remainder = num % 10;
        sum += factorial(remainder);
        num /= 10;
    }

    if(sum == original)
        printf("%d is a Strong Number.\n", original);
    else
        printf("%d is not a Strong Number.\n", original);

    return 0;
}