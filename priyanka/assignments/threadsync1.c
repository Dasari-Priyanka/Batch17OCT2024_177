#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

// Global variables to track palindrome and non-palindrome counts
int is_palindrome = 0;
int not_palindrome = 0;

// Mutex for synchronized access to global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to check if a string is a palindrome
bool is_palindrome_check(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Structure to pass the string and thread ID
typedef struct {
    char *str;
    int thread_id;
} thread_data_t;

// Function to be executed by each thread
void *check_palindrome(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    bool is_palindrome_status = is_palindrome_check(data->str);
    char *result_message = malloc(100 * sizeof(char)); // Allocate memory for result message

    if (is_palindrome_status) {
        sprintf(result_message, "%s is a palindrome", data->str);
        // Safely update the global palindrome counter
        pthread_mutex_lock(&mutex);
        is_palindrome++;
        pthread_mutex_unlock(&mutex);
    } else {
        sprintf(result_message, "%s is not a palindrome", data->str);
        // Safely update the global non-palindrome counter
        pthread_mutex_lock(&mutex);
        not_palindrome++;
        pthread_mutex_unlock(&mutex);
    }

    // Return the result message to the parent thread
    pthread_exit(result_message);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please provide at least 2 strings as command line arguments.\n");
        return EXIT_FAILURE;
    }

    int n = argc - 1; // Number of input strings

    pthread_t *threads = malloc(n * sizeof(pthread_t)); // Array to hold thread IDs
    thread_data_t *thread_data = malloc(n * sizeof(thread_data_t)); // Array to hold thread data

    // Create threads to check each string for palindrome
    for (int i = 0; i < n; i++) {
        thread_data[i].str = argv[i + 1]; // Pass the string to the thread
        thread_data[i].thread_id = i + 1;

        int rc = pthread_create(&threads[i], NULL, check_palindrome, (void *)&thread_data[i]);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread %d: %s\n", i + 1, strerror(rc));
            return EXIT_FAILURE;
        }
    }

    // Main thread waits for all threads to finish
    for (int i = 0; i < n; i++) {
        void *result;
        pthread_join(threads[i], &result); // Wait for thread to finish

        // Display the message returned by the thread
        printf("Thread %d: %s\n", i + 1, (char *)result);

        // Free the memory allocated for the result message
        free(result);
    }

    // Print the final counts of palindrome and non-palindrome strings
    printf("Total palindromes: %d\n", is_palindrome);
    printf("Total non-palindromes: %d\n", not_palindrome);

    // Clean up allocated memory
    free(threads);
    free(thread_data);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}

