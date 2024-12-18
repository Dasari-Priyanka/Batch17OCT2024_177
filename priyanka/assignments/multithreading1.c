#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define THREAD_COUNT 3

// Define a structure to hold thread-specific information
typedef struct {
    pthread_t thread_id;
    int thread_num;
} ThreadData;

void *thread1_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); // Disable cancellation
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); // Deferred cancellation

    while (1) {
        time_t t = time(NULL);
        printf("%s Thread %d: Health OK\n", ctime(&t), data->thread_num);
        sleep(2); // Sleep for 2 seconds
    }
    return NULL;
}

void *thread2_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); // Enable cancellation
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); // Deferred cancellation

    int count = 1000;
    while (1) {
        time_t t = time(NULL);
        printf("%s Thread %d: %d\n", ctime(&t), data->thread_num, count);
        count += 2;
        sleep(3); // Sleep for 3 seconds
    }
    return NULL;
}

void *thread3_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); // Enable cancellation
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL); // Asynchronous cancellation

    int count = 2000;
    while (1) {
        time_t t = time(NULL);
        printf("%s Thread %d: %d\n", ctime(&t), data->thread_num, count);
        count += 2;
        sleep(3); // Sleep for 3 seconds
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];

    // Create Thread 1 (Detached, PTHREAD_CANCEL_DISABLE)
    thread_data[0].thread_num = 1;
    pthread_create(&threads[0], NULL, thread1_function, &thread_data[0]);
    pthread_detach(threads[0]); // Detach Thread 1

    // Create Thread 2 (Not Detached, PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DEFERRED)
    thread_data[1].thread_num = 2;
    pthread_create(&threads[1], NULL, thread2_function, &thread_data[1]);

    // Create Thread 3 (Not Detached, PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_ASYNCHRONOUS)
    thread_data[2].thread_num = 3;
    pthread_create(&threads[2], NULL, thread3_function, &thread_data[2]);

    // Let the threads run for 3 minutes before cancelling
    sleep(180); // Sleep for 3 minutes

    // Cancel all threads
    printf("\nMain thread: Cancelling all threads...\n");
    pthread_cancel(threads[0]);
    pthread_cancel(threads[1]);
    pthread_cancel(threads[2]);

    // Sleep a bit to allow cancellation to take effect
    sleep(1);

    return 0;
}

