#include <stdio.h>
#include <string.h>

int main() {
    char str[200], word[50], longest[50];
    int i = 0, j = 0, maxLen = 0, len;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    while (1) {
        // Extract a word
        len = 0;

        while (str[i] != ' ' && str[i] != '\0') {
            word[len++] = str[i++];
        }

        word[len] = '\0';

        // Check if it's the longest
        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, word);
        }

        if (str[i] == '\0')
            break;

        i++; // skip space
    }

    printf("Longest word = %s\n", longest);
    printf("Length = %d\n", maxLen);

    return 0;
}