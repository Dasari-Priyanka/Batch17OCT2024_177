#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to sort a string
void sortString(char *str) {
    int i, j;
    char temp;
    int n = strlen(str);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                // Swap characters
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    // Remove spaces and convert to lowercase
    char str1Copy[MAX], str2Copy[MAX];
    int i, j = 0;

    // Remove spaces and convert to lowercase for str1
    for (i = 0; str1[i] != '\0'; i++) {
        if (!isspace(str1[i])) {
            str1Copy[j++] = tolower(str1[i]);
        }
    }
    str1Copy[j] = '\0';

    // Reset j for str2 copy
    j = 0;

    // Remove spaces and convert to lowercase for str2
    for (i = 0; str2[i] != '\0'; i++) {
        if (!isspace(str2[i])) {
            str2Copy[j++] = tolower(str2[i]);
        }
    }
    str2Copy[j] = '\0';

    // Check if lengths are equal after removing spaces and converting to lowercase
    if (strlen(str1Copy) != strlen(str2Copy)) {
        return 0; // Not an anagram
    }

    // Sort both strings
    sortString(str1Copy);
    sortString(str2Copy);

    // Compare sorted strings
    if (strcmp(str1Copy, str2Copy) == 0) {
        return 1; // They are anagrams
    }
    return 0; // Not an anagram
}

int main() {
    char str1[MAX], str2[MAX];

    // Get input strings
    printf("Enter first string: ");
    fgets(str1, MAX, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove the newline character

    printf("Enter second string: ");
    fgets(str2, MAX, stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove the newline character

    // Check if strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are non-anagrams.\n");
    }

    return 0;
}

