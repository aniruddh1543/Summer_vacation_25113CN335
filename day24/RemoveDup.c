#include <stdio.h>
#include <string.h>

int main() {
    char str[100], result[100];
    int i, j, k = 0, found;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        found = 0;

        // Check if character already exists in result
        for (j = 0; j < k; j++) {
            if (str[i] == result[j]) {
                found = 1;
                break;
            }
        }

        // If not found, add to result
        if (!found) {
            result[k++] = str[i];
        }
    }

    result[k] = '\0';

    printf("String after removing duplicates: %s\n", result);

    return 0;
}