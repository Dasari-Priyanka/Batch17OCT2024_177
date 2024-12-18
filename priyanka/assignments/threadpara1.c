#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Mutex to synchronize output from different threads
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to compare two strings for qsort()
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to sort words in a line and return the sorted line
void *sort_line(void *arg) {
    char *line = (char *)arg;
    char *line_copy = strdup(line); // Copy the line to avoid modifying the original

    // Split the line into words using space as the delimiter
    char *word = strtok(line_copy, " ");
    int word_count = 0;
    char *words[100]; // Array to hold words (assuming a max of 100 words)

    // Store words in the words array
    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }

    // Sort the words using qsort
    qsort(words, word_count, sizeof(char *), compare_strings);

    // Create a new line for the sorted words
    char *sorted_line = malloc(1024); // Allocate memory for sorted line
    sorted_line[0] = '\0'; // Initialize the string

    // Concatenate sorted words back into a single line
    for (int i = 0; i < word_count; i++) {
        strcat(sorted_line, words[i]);
        if (i < word_count - 1) {
            strcat(sorted_line, " ");
        }
    }

    // Free the copied line to avoid memory leak
    free(line_copy);

    // Return the sorted line to the main thread
    pthread_exit((void *)sorted_line);
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <line1> <line2> <line3>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[3]; // Thread array to hold the threads
    char *lines[3] = {argv[1], argv[2], argv[3]}; // Store the lines from command-line args
    char *sorted_lines[3]; // Array to store the sorted lines

    // Create threads to sort the lines
    for (int i = 0; i < 3; i++) {
        int rc = pthread_create(&threads[i], NULL, sort_line, (void *)lines[i]);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread %d: %s\n", i, strerror(rc));
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to complete and get the sorted lines
    for (int i = 0; i < 3; i++) {
        void *result;
        pthread_join(threads[i], &result); // Wait for thread to finish

        // Lock the mutex to print the result
        pthread_mutex_lock(&mutex);
        sorted_lines[i] = (char *)result; // Store the sorted line
        printf("Sorted Line %d: %s\n", i + 1, sorted_lines[i]);
        pthread_mutex_unlock(&mutex);
    }

    // Free the memory allocated for sorted lines
    for (int i = 0; i < 3; i++) {
        free(sorted_lines[i]);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}

