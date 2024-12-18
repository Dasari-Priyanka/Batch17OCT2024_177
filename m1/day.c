#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the struct DT to store the date
struct DT {
    int day;
    int month;
    int year;
};

// Function to tokenize the date string and store in the struct DT
void strtoken(char *datestr, struct DT *date) {
    // Tokenize the date string using "/" as the delimiter
    char *token = strtok(datestr, "/");
    
    // Convert each token to an integer and store it in the date structure
    date->day = atoi(token);  // Convert day string to integer
    token = strtok(NULL, "/");
    date->month = atoi(token);  // Convert month string to integer
    token = strtok(NULL, "/");
    date->year = atoi(token);  // Convert year string to integer
}

// Function to compare two dates
int compare(struct DT *date1, struct DT *date2) {
    // Compare the years first
    if (date1->year < date2->year) {
        return 1;  // date1 is earlier
    } else if (date1->year > date2->year) {
        return 2;  // date2 is earlier
    } else {
        // If years are equal, compare months
        if (date1->month < date2->month) {
            return 1;  // date1 is earlier
        } else if (date1->month > date2->month) {
            return 2;  // date2 is earlier
        } else {
            // If both years and months are equal, compare days
            if (date1->day < date2->day) {
                return 1;  // date1 is earlier
            } else if (date1->day > date2->day) {
                return 2;  // date2 is earlier
            } else {
                return 0;  // Both dates are equal
            }
        }
    }
}

int main() {
    char datestr1[20], datestr2[20];  // Arrays to hold the date strings
    struct DT date1, date2;  // Structs to hold the date details

    // Input for two dates in DD/MM/YYYY format
    printf("Enter first date (DD/MM/YYYY): ");
    scanf("%s", datestr1);  // Read the first date string

    printf("Enter second date (DD/MM/YYYY): ");
    scanf("%s", datestr2);  // Read the second date string

    // Tokenize the dates and store them in the date structures
    strtoken(datestr1, &date1);
    strtoken(datestr2, &date2);

    // Compare the two dates and output the result
    int result = compare(&date1, &date2);
    if (result == 1) {
        printf("The first date is earlier.\n");
    } else if (result == 2) {
        printf("The second date is earlier.\n");
    } else {
        printf("Both dates are equal.\n");
    }

    return 0;
}

