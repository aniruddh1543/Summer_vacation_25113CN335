#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[200];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Check lengths
    if (strlen(str1) != strlen(str2)) {
        printf("Not a rotation\n");
        return 0;
    }

    // Concatenate first string with itself
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if second string is a substring
    if (strstr(temp, str2) != NULL) {
        printf("Strings are rotation of each other\n");
    } else {
        printf("Not a rotation\n");
    }

    return 0;
}