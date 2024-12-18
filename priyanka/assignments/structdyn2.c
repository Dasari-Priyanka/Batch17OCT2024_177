#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

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

// Function to search for a name and replace it with a user-defined name
char* search_update(char *searchstr, char *replacestr) {
    char *result = (char *)malloc(strlen(replacestr) + 1);
    if (result == NULL) {
        printf("Memory allocation failed for updated name!\n");
        exit(1);
    }
    strcpy(result, replacestr);
    return result;  // Return the updated string
}

// Function to search and delete the record with a given name or percentage value
int delete_record(char *searchstr, int percent, struct student *students, int *num_records) {
    int i, found = 0;
    
    for (i = 0; i < *num_records; i++) {
        if ((searchstr != NULL && strcmp(students[i].name, searchstr) == 0) || 
            (percent != -1 && (int)students[i].percentage == percent)) {
            // Free the memory for the name and shift the records
            free_student(&students[i]);

            // Shift records to remove the deleted one
            for (int j = i; j < *num_records - 1; j++) {
                students[j] = students[j + 1];
            }

            (*num_records)--;  // Decrease the record count
            found = 1;
            break;
        }
    }
    return found ? SUCCESS : FAILURE;
}

// Function to search for a name and create a copy of the record in newstudent
int copy(char *name, struct student **newstudent, struct student *students, int num_records) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(students[i].name, name) == 0) {
            // Allocate memory for the new student record
            *newstudent = (struct student *)malloc(sizeof(struct student));
            if (*newstudent == NULL) {
                printf("Memory allocation failed for new student record!\n");
                return FAILURE;
            }

            // Copy the name and percentage of the found student
            (*newstudent)->name = (char *)malloc(strlen(students[i].name) + 1);
            if ((*newstudent)->name == NULL) {
                printf("Memory allocation failed for new student's name!\n");
                free(*newstudent);
                return FAILURE;
            }
            strcpy((*newstudent)->name, students[i].name);
            (*newstudent)->percentage = students[i].percentage;
            
            return SUCCESS;  // Return success if copy is successful
        }
    }
    return FAILURE;  // Return failure if the student with the given name is not found
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

    // Example usage of search_update function
    char *updated_name = search_update(students[0].name, "new_name");
    free(students[0].name);  // Free the old name memory
    students[0].name = updated_name;
    printf("\nAfter update:\n");
    display_records(students, num_records);

    // Example usage of delete_record function
    if (delete_record("new_name", -1, students, &num_records) == SUCCESS) {
        printf("\nAfter deletion:\n");
        display_records(students, num_records);
    }

    // Example usage of copy function
    struct student *new_student;
    if (copy("user21", &new_student, students, num_records) == SUCCESS) {
        printf("\nCopied Record:\n");
        printf("Name: %s, Percentage: %.2f\n", new_student->name, new_student->percentage);
        free_student(new_student);  // Free copied student memory
        free(new_student);
    } else {
        printf("Record not found for copying!\n");
    }

    // Free dynamically allocated memory for student names
    for (int i = 0; i < num_records; i++) {
        free_student(&students[i]);
    }

    // Free the memory allocated for the array of student records
    free(students);

    return 0;
}

