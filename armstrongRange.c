#include <stdio.h>
#include <math.h>

int main() {
    int lower, upper, number, originalNumber, remainder, n;
    double result;

    printf("Enter lower limit: ");
    scanf("%d", &lower);

    printf("Enter upper limit: ");
    scanf("%d", &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);

    for (number = lower; number <= upper; number++) {

        originalNumber = number;
        result = 0;
        n = 0;

        // Count digits
        while (originalNumber != 0) {
            originalNumber /= 10;
            n++;
        }

        originalNumber = number;

        // Calculate sum of digits raised to power n
        while (originalNumber != 0) {
            remainder = originalNumber % 10;
            result += pow(remainder, n);
            originalNumber /= 10;
        }

        if ((int)result == number) {
            printf("%d ", number);
        }
    }

    return 0;
}