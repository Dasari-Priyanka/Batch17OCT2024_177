#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

// Global variable to count valid emails
int validmail_count = 0;

// Mutex for synchronized access to global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to check if the email is valid
int is_valid_email(const char *email) {
    // Split email into username and domain
    const char *at_sign = strchr(email, '@');
    if (at_sign == NULL) {
        return 0; // Invalid email if no '@' found
    }

    // Username is the part before the '@'
    size_t username_len = at_sign - email;
    if (username_len == 0 || !isalpha(email[0])) {
        return 0; // Invalid email if username is empty or doesn't start with a letter
    }

    // Domain is the part after the '@'
    const char *domain = at_sign + 1;

    // Check if domain ends with ".com" or ".edu"
    if (strstr(domain, ".com") != NULL || strstr(domain, ".edu") != NULL) {
        return 1; // Valid email if domain ends with ".com" or ".edu"
    }
    return 0; // Invalid email if domain is not ".com" or ".edu"
}

// Thread function to validate the email and return the username
void *validate_email(void *arg) {
    char *email = (char *)arg;

    // Check if the email is valid
    if (is_valid_email(email)) {
        char *username = strtok(email, "@"); // Extract username from email
        char *result = malloc(strlen(username) + 1);
        strcpy(result, username); // Copy the username to result

        // Safely increment the valid email count
        pthread_mutex_lock(&mutex);
        validmail_count++;
        pthread_mutex_unlock(&mutex);

        // Return the valid username
        pthread_exit(result);
    } else {
        pthread_exit(NULL); // Return NULL if email is not valid
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <email_list>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the list of emails separated by ';'
    char *emails = argv[1];
    char *email = strtok(emails, ";"); // Split the string into individual emails

    pthread_t *threads = malloc(sizeof(pthread_t) * 100); // Allocate memory for threads (assuming max 100 emails)
    int thread_count = 0;

    // Create threads for each email
    while (email != NULL) {
        // Copy email to pass to thread
        char *email_copy = strdup(email);

        int rc = pthread_create(&threads[thread_count], NULL, validate_email, (void *)email_copy);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread for email: %s\n", email);
            return EXIT_FAILURE;
        }
        email = strtok(NULL, ";");
        thread_count++;
    }

    // Main thread waits for each thread to finish
    for (int i = 0; i < thread_count; i++) {
        void *result;
        pthread_join(threads[i], &result); // Wait for thread to complete

        // Display the result if the thread returned a valid username
        if (result != NULL) {
            printf("Valid username: %s\n", (char *)result);
            free(result); // Free the allocated memory for the valid username
        }
    }

    // Display the final count of valid email addresses
    printf("Total valid email addresses: %d\n", validmail_count);

    // Clean up resources
    free(threads);
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}

