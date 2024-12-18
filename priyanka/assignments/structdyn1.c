#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *name;          // Pointer to dynamically allocated name
    float percentage;    // Student's percentage
};

// Function to free dynamically allocated memory for student name
void free_student(struct student *s) {
    if (s->name != NULL) {
        free(s->name);  // Free memory allocated for name
    }
}

// Function to parse records and store them in an array of structures
void parse_records(char *input, struct student **students, int *num_records) {
    char *record;
    char *token;
    int i = 0;

    // Count how many records are there
    *num_records = 0;
    for (int j = 0; input[j] != '\0'; j++) {
        if (input[j] == ';') {
            (*num_records)++;
        }
    }
    (*num_records)++; // last record after the last semicolon

    // Allocate memory for the student records
    *students = (struct student *)malloc(*num_records * sizeof(struct student));
    if (*students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Split the input string into records
    record = strtok(input, ";");
    while (record != NULL) {
        // Split the record into name and percentage
        token = strtok(record, ",");
        (*students)[i].name = (char *)malloc(strlen(token) + 1);
        if ((*students)[i].name == NULL) {
            printf("Memory allocation failed for name!\n");
            exit(1);
        }
        strcpy((*students)[i].name, token);

        token = strtok(NULL, ",");
        (*students)[i].percentage = atof(token);  // Convert string to float

        i++;
        record = strtok(NULL, ";");  // Move to the next record
    }
}

// Function to display student records
void display_records(struct student *students, int num_records) {
    printf("No. of records: %d\n", num_records);
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s, Percentage: %.2f\n", students[i].name, students[i].percentage);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    struct student *students = NULL;
    int num_records = 0;

    // Parse the records from the input string
    parse_records(argv[1], &students, &num_records);

    // Display the records
    display_records(students, num_records);

    // Free dynamically allocated memory for student names
    for (int i = 0; i < num_records; i++) {
        free_student(&students[i]);
    }

    // Free the memory allocated for the array of student records
    free(students);

    return 0;
}

