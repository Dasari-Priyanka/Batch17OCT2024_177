#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Maximum number of words (as per the problem requirement)
#define MAX_WORDS 5

// Structure to pass word and its index to the thread
typedef struct {
    char *word;
    int thread_num;
    char *result;
} ThreadData;

// Function to be executed by each thread
void *process_word(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    
    // Allocate memory for the modified word
    data->result = malloc(strlen(data->word) + 4);  // "_ed" is 3 chars + 1 for '\0'
    
    if (data->result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        pthread_exit(NULL);
    }

    // Append "_ed" to the word
    strcpy(data->result, data->word);
    strcat(data->result, "_ed");

    // Return the modified word to the main thread
    pthread_exit((void *)data->result);
}

int main(int argc, char *argv[]) {
    // Check if there are command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <word1> <word2> ... <word5>\n", argv[0]);
        return 1;
    }

    // Ensure no more than 5 words are provided
    int num_words = (argc - 1) > MAX_WORDS ? MAX_WORDS : (argc - 1);
    
    pthread_t threads[num_words];
    ThreadData thread_data[num_words];
    void *status;
    
    // Create a thread for each word
    for (int i = 0; i < num_words; i++) {
        thread_data[i].word = argv[i + 1];
        thread_data[i].thread_num = i + 1;
        
        if (pthread_create(&threads[i], NULL, process_word, (void *)&thread_data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for each thread to finish and retrieve the modified word
    for (int i = 0; i < num_words; i++) {
        if (pthread_join(threads[i], &status) != 0) {
            perror("Failed to join thread");
            return 1;
        }

        // Display the result from each thread
        printf("Thread %d: %s\n", i + 1, (char *)status);

        // Free the memory allocated by the thread
        free(status);
    }

    return 0;
}

