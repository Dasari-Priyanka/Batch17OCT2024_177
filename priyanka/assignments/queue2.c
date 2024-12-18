#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 80  // Maximum length of the string data entered by the user

// Define the queue node structure
typedef struct node_q {
    char *data;         // String data read from user
    struct node_q *next; // Pointer to the next node in the queue
} node;

// Queue structure definition
typedef struct queue {
    node *front;
    node *rear;
} queue_t;

// Function prototypes
void init_queue(queue_t *q);
int is_empty(queue_t *q);
void enqueue(queue_t *q, const char *str);
void dequeue(queue_t *q);
void display(queue_t *q);
void free_queue(queue_t *q);

int main() {
    queue_t q;
    init_queue(&q);

    char input[MAX_STRING_LENGTH];

    // Example of user input for a few strings
    printf("Enter up to 5 strings to add to the queue (max length 80 characters each):\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the newline character
        
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
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int is_empty(queue_t *q) {
    return q->front == NULL;
}

// Enqueue a string to the queue
void enqueue(queue_t *q, const char *str) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Allocate memory for the string and copy it into the node
    new_node->data = (char *)malloc(strlen(str) + 1);
    if (new_node->data == NULL) {
        printf("Memory allocation failed for string\n");
        free(new_node);
        return;
    }
    strcpy(new_node->data, str);

    new_node->next = NULL;

    // If the queue is empty, set the front and rear to the new node
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        // Add the new node to the rear of the queue
        q->rear->next = new_node;
        q->rear = new_node;
    }
    printf("Enqueued: %s\n", str);
}

// Dequeue a string from the queue
void dequeue(queue_t *q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Remove the front node
    node *temp = q->front;
    q->front = q->front->next;

    // Print the dequeued string
    printf("Dequeued: %s\n", temp->data);

    // Free the dynamically allocated memory for the string
    free(temp->data);
    free(temp);

    // If the queue is empty, reset the rear pointer
    if (q->front == NULL) {
        q->rear = NULL;
    }
}

// Display the contents of the queue
void display(queue_t *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    node *current = q->front;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Free the dynamically allocated memory for the queue
void free_queue(queue_t *q) {
    while (!is_empty(q)) {
        dequeue(q);  // Dequeue and free the memory
    }
    printf("\nMemory freed.\n");
}

