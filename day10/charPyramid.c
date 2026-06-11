#include <stdio.h>

int main() {
    int n = 5;

    for(int i = 0; i < n; i++) {
        // Print spaces
        for(int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print ascending characters
        for(int j = 0; j <= i; j++) {
            printf("%c", 'A' + j);
        }

        // Print descending characters
        for(int j = i - 1; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}