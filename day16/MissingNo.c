#include <stdio.h>

int main() {
    int n, i, sum = 0, expected_sum;

    printf("Enter number of elements (n-1): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers from 1 to %d (one missing):\n", n, n + 1);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    expected_sum = (n + 1) * (n + 2) / 2;

    printf("Missing number = %d\n", expected_sum - sum);

    return 0;
}