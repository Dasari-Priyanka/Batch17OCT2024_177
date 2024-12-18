#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Structure for student
struct student {
    int id;
    char *name;        // Pointer to hold dynamically allocated name
    float percentage;
};
 
// Function to read and update the name
char* read_update_name() {
    char temp_name[100];  // Temporary buffer to hold the new name
 
    printf("Enter new name: ");
    scanf("%s", temp_name);
 
    // Allocate memory for the name dynamically and copy the input to it
    char *name = (char *)malloc(strlen(temp_name) + 1);  // +1 for null terminator
    if (name == NULL) {
        printf("Memory allocation failed for name!\n");
        exit(1);  // Exit if memory allocation fails
    }
    strcpy(name, temp_name);  // Copy the new name to dynamically allocated memory
 
    return name;  // Return the updated name
}
 
// Function to read and update the percentage
float read_update_percentage() {
    float percentage;
    printf("Enter new percentage: ");
    scanf("%f", &percentage);
    return percentage;  // Return the updated percentage
}
 
// Function to free dynamically allocated memory for each student
void free_student(struct student *s) {
    if (s->name != NULL) {
        free(s->name);  // Free dynamically allocated memory for name
    }
}
 
// Main function
int main() {
    int num_students;
    printf("How many students do you want to enter? ");
    scanf("%d", &num_students);  // Number of students to be entered
 
    // Dynamically allocate memory for an array of students
    struct student *students = (struct student *)malloc(num_students * sizeof(struct student));
    if (students == NULL) {
        printf("Memory allocation failed for students array!\n");
        return 1;  // Exit if memory allocation fails
    }
 
    // Loop to enter student details
    for (int i = 0; i < num_students; i++) {
        printf("\nEntering details for student %d\n", i + 1);
        students[i].id = i + 1;  // Assigning ID as incrementing integer
 
        // Read and update name and percentage
        students[i].name = read_update_name();
        students[i].percentage = read_update_percentage();
    }
 
    // Display the records
    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Percentage: %.2f\n", students[i].percentage);
    }
 
    // Free dynamically allocated memory for each student
    for (int i = 0; i < num_students; i++) {
        free_student(&students[i]);
    }
 
    // Free the array of students
    free(students);
 
    return 0;
}
