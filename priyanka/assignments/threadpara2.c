#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

// Structure to hold the line and its word count
typedef struct {
    char *line;
    int word_count;
} line_info_t;

// Function to count words in a line
int count_words(const char *line) {
    int count = 0;
    char *copy = strdup(line); // Make a copy of the line to safely tokenize
    char *token = strtok(copy, " \t\n"); // Tokenize by spaces or newlines

    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }

    free(copy); // Free the copied line to avoid memory leak
    return count;
}

// Thread function to process each line, count words, and return the result
void *thread_proc(void *arg) {
    char *line = (char *)arg;
    line_info_t *line_info = malloc(sizeof(line_info_t)); // Allocate memory for result

    line_info->line = strdup(line); // Duplicate the line
    line_info->word_count = count_words(line); // Count words in the line

    // Display the result
    printf("Line: %s\nWord Count: %d\n", line_info->line, line_info->word_count);

    pthread_exit((void *)line_info); // Return the result to the parent thread
}

// Function to create threads
pthread_t *createthreads(int count) {
    pthread_t *threads = (pthread_t *)malloc(count * sizeof(pthread_t)); // Allocate memory for thread array
    if (threads == NULL) {
        perror("Failed to allocate memory for threads");
        exit(EXIT_FAILURE);
    }
    return threads;
}

// Function to process the file
void process_file(const char *filename, pthread_t *threads, int line_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int line_index = 0;

    while (fgets(line, sizeof(line), file) && line_index < line_count) {
        // Create a thread for each line
        int rc = pthread_create(&threads[line_index], NULL, thread_proc, (void *)strdup(line));
        if (rc != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
        line_index++;
    }

    fclose(file); // Close the file after processing
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    // Open the file and count the number of lines
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open the file");
        return EXIT_FAILURE;
    }

    int line_count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line_count++;
    }
    fclose(file); // Close the file after counting lines

    // Create the thread array
    pthread_t *threads = createthreads(line_count);

    // Process the file and create threads for each line
    process_file(filename, threads, line_count);

    // Wait for all threads to finish and collect the results
    for (int i = 0; i < line_count; i++) {
        void *result;
        pthread_join(threads[i], &result);

        // Retrieve the result (line_info_t) from the thread
        line_info_t *line_info = (line_info_t *)result;

        // Display the results
        printf("From thread: Line = %sWord Count = %d\n", line_info->line, line_info->word_count);

        // Free the memory allocated for the line info
        free(line_info->line);
        free(line_info);
    }

    // Free the memory allocated for threads array
    free(threads);

    return EXIT_SUCCESS;
}

