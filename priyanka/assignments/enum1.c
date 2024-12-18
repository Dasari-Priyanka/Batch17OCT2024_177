#include <stdio.h>

// Define the enum for designations
enum Designation {
    E2F = 1,    // Software Fresher
    E2,         // Software Engineer
    E3,         // Senior Software Engineer
    E4,         // Team Lead
    E5          // Senior Team Lead
};

// Function to get the designation string based on the enum value
const char* get_designation_string(enum Designation designation) {
    switch (designation) {
        case E2F:
            return "Software Fresher";
        case E2:
            return "Software Engineer";
        case E3:
            return "Senior Software Engineer";
        case E4:
            return "Team Lead";
        case E5:
            return "Senior Team Lead";
        default:
            return "Invalid Designation";  // If the input does not match any value
    }
}

int main() {
    int input_designation;

    // Prompt the user to enter a designation value
    printf("Enter your designation number (1 for E2F, 2 for E2, 3 for E3, 4 for E4, 5 for E5): ");
    scanf("%d", &input_designation);

    // Validate input and output the corresponding designation string
    if (input_designation >= E2F && input_designation <= E5) {
        // Cast the input to enum Designation
        enum Designation user_designation = (enum Designation)input_designation;
        printf("Your designation: %s\n", get_designation_string(user_designation));
    } else {
        printf("Invalid input! Please enter a number between 1 and 5.\n");
    }

    return 0;
}

