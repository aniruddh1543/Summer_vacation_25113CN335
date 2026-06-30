#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Find length of string
    for (i = 0; str[i] != '\0'; i++);

    // Reverse the string
    for (j = 0, i = i - 1; j < i; j++, i--) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }

    printf("Reversed string = %s\n", str);

    return 0;
}