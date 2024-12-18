#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Function to read lines from a file
int read_lines_from_file(const char *filename, char lines[MAX_LINES][MAX_LINE_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return 0;
    }

    int i = 0;
    while (fgets(lines[i], MAX_LINE_LENGTH, file)) {
        lines[i][strcspn(lines[i], "\n")] = '\0'; // Remove newline character
        i++;
    }

    fclose(file);
    return i;
}

// Function to compare two strings (for sorting)
int compare_lines(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Function to search and delete a line
int delete_line(char lines[MAX_LINES][MAX_LINE_LENGTH], int num_lines, const char *line_to_delete) {
    for (int i = 0; i < num_lines; i++) {
        if (strcmp(lines[i], line_to_delete) == 0) {
            // Shift the remaining lines up
            for (int j = i; j < num_lines - 1; j++) {
                strcpy(lines[j], lines[j + 1]);
            }
            return num_lines - 1; // Return the new number of lines
        }
    }
    return num_lines; // Line not found, return the original number of lines
}

// Function to write the lines to an output file
void write_lines_to_file(const char *filename, char lines[MAX_LINES][MAX_LINE_LENGTH], int num_lines) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);
}

int main() {
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    const char *input_filename = "input.txt"; // Input file
    const char *output_filename = "out.txt"; // Output file

    // Step 1: Read lines from the file
    int num_lines = read_lines_from_file(input_filename, lines);
    if (num_lines == 0) {
        return 1; // Error reading the file
    }

    // Step 2: Sort the lines
    qsort(lines, num_lines, MAX_LINE_LENGTH, compare_lines);

    // Step 3: Search and delete a specific line (you can modify this line)
    const char *line_to_delete = "Line 7-45 words"; // The line you want to delete
    num_lines = delete_line(lines, num_lines, line_to_delete);

    // Step 4: Write the final list of lines to the output file
    write_lines_to_file(output_filename, lines, num_lines);

    printf("Updated lines written to %s\n", output_filename);
    return 0;
}

