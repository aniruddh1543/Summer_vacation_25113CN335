#include <stdio.h>

int main() {
    int n = 5;

    for(int i = n; i >= 1; i--) {
        // Print spaces
        for(int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // Print stars
        for(int k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}