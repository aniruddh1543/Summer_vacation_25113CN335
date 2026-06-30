#include <stdio.h>

int main() {
    int i, j, n, sum = 0;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Diagonal sum
    for (i = 0; i < n; i++) {
        sum += a[i][i];   // main diagonal
    }

    printf("Sum of main diagonal = %d\n", sum);

    return 0;
}