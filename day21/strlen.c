#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate length manually
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n') {   // ignore newline from fgets
            length++;
        }
    }

    printf("Length of string = %d\n", length);

    return 0;
}