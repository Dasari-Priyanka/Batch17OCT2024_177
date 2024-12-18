#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Structure to hold thread arguments
typedef struct {
    unsigned long long large_serial_number;
    const char *my_name;
    pthread_t caller_thread;
} fun_thread_args_t;

#define NUM_LOOPS 5u

// Thread function to run the task
static void* _fun_thread_run(void *arg) {
    // Get the thread arguments
    fun_thread_args_t *thread_args = (fun_thread_args_t *)arg;

    unsigned int counter = 0;
    bool done = false;

    while (!done) {
        // Use the args in the loop
        counter++;
        printf("My name is: '%s', my number is: %llX, loop count: %u\n",
               thread_args->my_name,
               thread_args->large_serial_number,
               counter);

        if (counter >= NUM_LOOPS) {
            printf("'%s' is sooooo done.\n", thread_args->my_name);
            done = true;
        } else {
            sleep(1u);
        }
    }

    // Free the allocated memory for thread args
    free(arg);
    return NULL;
}

// Launch a new fun thread and pass arguments
static pthread_t *_launch_fun_thread(pthread_t *thread, unsigned long long serial_number, const char *name) {
    // Allocate memory for thread arguments
    fun_thread_args_t *args = calloc(1, sizeof(fun_thread_args_t));
    if (args == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Set up the arguments for the thread
    args->caller_thread = pthread_self();
    args->large_serial_number = serial_number;
    args->my_name = name;

    // Create the thread and return its result
    int rc = pthread_create(thread, NULL, &_fun_thread_run, args);
    if (rc != 0) {
        fprintf(stderr, "Thread creation failed with error code %d\n", rc);
        free(args); // Clean up memory in case of failure
        return NULL;
    }

    return thread;
}

int main(void) {
    puts("The fun we are having!");

    pthread_t fun_thread1;
    pthread_t fun_thread2;

    // Launch the first fun thread
    if (_launch_fun_thread(&fun_thread1, 0xABCDEF12345678ULL, "super FUN thread 1") == NULL) {
        fprintf(stderr, "Failed to create thread 1\n");
        return EXIT_FAILURE;
    }

    // Sleep briefly before launching the second thread
    usleep(500UL * 1000UL);

    // Launch the second fun thread
    if (_launch_fun_thread(&fun_thread2, 0xDEADBEEF55AA55ULL, "super FUN thread 2") == NULL) {
        fprintf(stderr, "Failed to create thread 2\n");
        return EXIT_FAILURE;
    }

    // Wait for both threads to finish
    pthread_join(fun_thread1, NULL);
    pthread_join(fun_thread2, NULL);

    puts("We are done having fun :(");
    return EXIT_SUCCESS;
}

