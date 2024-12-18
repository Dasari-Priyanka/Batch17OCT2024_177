#include <stdio.h>
#include <string.h>

char* read_extract_characters(void) {
    static char extracted[51]; // Array to store extracted characters (max length 50)
    char input[51];             // Array to store input string

    printf("Enter a string (max 50 characters): ");
    fgets(input, sizeof(input), stdin); // Read input string from user

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    int j = 0;  // Index for storing extracted characters
    // Extract characters at odd indices (1, 3, 5, ...)
    for (int i = 1; i < strlen(input); i += 2) {
        extracted[j++] = input[i];
    }
    extracted[j] = '\0'; // Null-terminate the extracted string

    return extracted; // Return the static array holding the extracted characters
}

int main() {
    // Call the function to extract characters at odd indices
    char* extracted_string = read_extract_characters();

    // Display the extracted string
    printf("Extracted string with characters at odd indices: %s\n", extracted_string);

    return 0;
}

