#include <stdio.h>

int main() {
    int number, count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0) {
        if (number & 1) {   // Check if last bit is 1
            count++;
        }
        number = number >> 1;  // Right shift the number
    }

    printf("Number of set bits: %d\n", count);

    return 0;
}