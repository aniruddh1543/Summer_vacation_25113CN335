#include <stdio.h>

int main() {
    char str[100];
    int i, j, found;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    // Find first non-repeating character
    for (i = 0; str[i] != '\0'; i++) {
        found = 0;

        for (j = 0; str[j] != '\0'; j++) {
            if (i != j && str[i] == str[j]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("First non-repeating character = %c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found\n");

    return 0;
}