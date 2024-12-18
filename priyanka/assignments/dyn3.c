#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Function to allocate memory for an array of n pointers to strings
char **allocate_array_memory(char **ptr, int n) {
    ptr = (char **)malloc(n * sizeof(char *));  // Allocate memory for n string pointers
    if (ptr == NULL) {
        printf("Memory allocation failed for array of pointers.\n");
        exit(1);  // Exit if memory allocation fails
    }
    return ptr;
}
 
// Function to allocate memory for a string (with a maximum length of 80 characters)
char *allocate_string_memory(char *string) {
    string = (char *)malloc(81 * sizeof(char));  // Allocate memory for up to 80 characters + 1 for '\0'
    if (string == NULL) {
        printf("Memory allocation failed for string.\n");
        exit(1);  // Exit if memory allocation fails
    }
    return string;
}
 
// Function to display the stored strings
void display(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("String %d: %s\n", i + 1, arr[i]);
    }
}
 
// Function to free memory for the array of pointers
void free_array_memory(char **ptr, int n) {
    for (int i = 0; i < n; i++) {
        free(ptr[i]);  // Free each string
    }
    free(ptr);  // Free the array of pointers itself
}
 
// Function to free memory for an individual string
void free_string_memory(char *ptr) {
    free(ptr);  // Free the string memory
}
 
// Main function
int main() {
    int n;
 
    printf("Enter the maximum number of strings (N): ");
    scanf("%d", &n);
    getchar();  // To consume the newline left by scanf
 
    // Allocate memory for the array of string pointers
    char **arr = NULL;
    arr = allocate_array_memory(arr, n);
 
    int i = 0;
    while (i < n) {
        char *input = NULL;
        input = allocate_string_memory(input);  // Allocate memory for the input string
 
        printf("Enter string %d (or type 'end' or 'END' to stop): ", i + 1);
        fgets(input, 81, stdin);  // Read the input string
        input[strcspn(input, "\n")] = '\0';  // Remove newline character if present
 
        if (strcmp(input, "end") == 0 || strcmp(input, "END") == 0) {
            free_string_memory(input);  // Free the memory for the input string
            break;  // Stop reading input if "end" or "END" is entered
        }
 
        arr[i] = input;  // Store the input string in the array
        i++;
    }
 
    // Display the stored strings
    display(arr, i);
 
    // Free the allocated memory
    free_array_memory(arr, i);
 
    return 0;
}
