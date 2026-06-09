#include <stdio.h>

int main() {
    int rows = 5;   // You can change this value
    int i, j;

    for(i = 1; i <= rows; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}