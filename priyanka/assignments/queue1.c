#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5  // Define the maximum queue size (can be modified by user)

// Queue structure definition
typedef struct queue {
    int arr[MAX_QUEUE_SIZE];  // Array to store integer values, can be used for indexes or data
    char **data;              // Array of strings (char pointers) to store user input strings
    int front;
    int rear;
} queue_t;

// Function prototypes
void init_queue(queue_t *q);
int is_full(queue_t *q);
int is_empty(queue_t *q);
void enqueue(queue_t *q, const char *str);
void dequeue(queue_t *q);
void display(queue_t *q);
void free_queue(queue_t *q);

int main() {
    queue_t q;
    init_queue(&q);
    
    // Example of user input for MAX_QUEUE_SIZE number of strings
    char input[100];
    
    printf("Enter %d strings to add to the queue:\n", MAX_QUEUE_SIZE);
    
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from the string
        enqueue(&q, input);
    }
    
    // Display the queue contents
    printf("\nQueue contents after enqueue:\n");
    display(&q);

    // Dequeue elements
    printf("\nDequeuing strings:\n");
    dequeue(&q);
    dequeue(&q);

    // Display the queue contents after dequeuing
    printf("\nQueue contents after dequeue:\n");
    display(&q);

    // Free dynamically allocated memory
    free_queue(&q);

    return 0;
}

// Initialize the queue
void init_queue(queue_t *q) {
    q->front = -1;
    q->rear = -1;
    q->data = (char **)malloc(MAX_QUEUE_SIZE * sizeof(char *));
    if (!q->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Check if the queue is full
int is_full(queue_t *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

// Check if the queue is empty
int is_empty(queue_t *q) {
    return q->front == -1;
}

// Enqueue a string to the queue
void enqueue(queue_t *q, const char *str) {
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue more strings.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // If the queue is empty, set front to 0
    }
    q->rear++;
    
    // Allocate memory for the new string and copy it into the queue
    q->data[q->rear] = (char *)malloc(strlen(str) + 1);
    if (!q->data[q->rear]) {
        printf("Memory allocation failed for string\n");
        exit(1);
    }
    strcpy(q->data[q->rear], str);
    printf("Enqueued: %s\n", str);
}

// Dequeue a string from the queue
void dequeue(queue_t *q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %s\n", q->data[q->front]);
    
    // Free the memory allocated for the dequeued string
    free(q->data[q->front]);
    
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Queue is empty
    } else {
        q->front++;
    }
}

// Display the contents of the queue
void display(queue_t *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s\n", q->data[i]);
    }
}

// Free the dynamically allocated memory for the queue
void free_queue(queue_t *q) {
    for (int i = q->front; i <= q->rear; i++) {
        free(q->data[i]);
    }
    free(q->data);
    printf("\nMemory freed.\n");
}

