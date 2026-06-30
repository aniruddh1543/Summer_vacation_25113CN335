#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int count[256] = {0};
    int i;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // If lengths are different, not anagrams
    if (strlen(str1) != strlen(str2)) {
        printf("Not an anagram\n");
        return 0;
    }

    // Count characters in first string
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
    }

    // Subtract counts using second string
    for (i = 0; str2[i] != '\0'; i++) {
        count[(unsigned char)str2[i]]--;
    }

    // Check if all counts are zero
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not an anagram\n");
            return 0;
        }
    }

    printf("Strings are anagrams\n");

    return 0;
}