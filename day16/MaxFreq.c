#include <stdio.h>

int main() {
    int n, i, j, maxCount = 0, count, maxElement;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        count = 1;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }

    printf("Maximum frequency element = %d\n", maxElement);
    printf("Frequency = %d\n", maxCount);

    return 0;
}