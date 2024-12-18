#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 5 // Maximum length of ID string

// Node structure definition with added id and val members
typedef struct Node {
    char id[MAX_ID_LEN + 1]; // Extra character for null terminator
    int val;
    struct Node *next;
} Node;

// Function prototypes
void insert_end(Node **head, const char *id, int val);
void display(Node *head);
int search_update_name(Node **head, const char *search, const char *replace);
int sorted_insert_name(Node **head, const char *name, int val);
int sorted_insert_val(Node **head, const char *name, int val);

// Insert a new node at the end of the list
void insert_end(Node **head, const char *id, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }

    strncpy(new_node->id, id, MAX_ID_LEN);
    new_node->id[MAX_ID_LEN] = '\0'; // Ensure null termination
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Display the linked list
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("ID: %s, Val: %d\n", temp->id, temp->val);
        temp = temp->next;
    }
}

// Search and update a node based on the 'id' (name) field
int search_update_name(Node **head, const char *search, const char *replace) {
    Node *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->id, search) == 0) {
            strncpy(temp->id, replace, MAX_ID_LEN);
            temp->id[MAX_ID_LEN] = '\0'; // Ensure null termination
            return 1; // Found and updated
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Insert a node based on 'name' in ascending order
int sorted_insert_name(Node **head, const char *name, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return -1;
    }

    strncpy(new_node->id, name, MAX_ID_LEN);
    new_node->id[MAX_ID_LEN] = '\0'; // Ensure null termination
    new_node->val = val;
    new_node->next = NULL;

    // If the list is empty or the new node should be placed at the beginning
    if (*head == NULL || strcmp((*head)->id, name) > 0) {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }

    // Traverse the list to find the correct position
    Node *temp = *head;
    while (temp->next != NULL && strcmp(temp->next->id, name) < 0) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return 0;
}

// Insert a node based on 'val' in ascending order
int sorted_insert_val(Node **head, const char *name, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return -1;
    }

    strncpy(new_node->id, name, MAX_ID_LEN);
    new_node->id[MAX_ID_LEN] = '\0'; // Ensure null termination
    new_node->val = val;
    new_node->next = NULL;

    // If the list is empty or the new node should be placed at the beginning
    if (*head == NULL || (*head)->val > val) {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }

    // Traverse the list to find the correct position
    Node *temp = *head;
    while (temp->next != NULL && temp->next->val < val) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return 0;
}

// Main function
int main() {
    Node *head = NULL;

    // Inserting nodes at the end
    insert_end(&head, "abc", 10);
    insert_end(&head, "def", 20);
    insert_end(&head, "ghi", 30);
    insert_end(&head, "xyz", 15);

    // Display the list
    printf("Original List:\n");
    display(head);

    // Search and update a node's name
    if (search_update_name(&head, "def", "jkl")) {
        printf("\nUpdated List after search and replace:\n");
    } else {
        printf("\nID not found.\n");
    }

    display(head);

    // Insert nodes in sorted order by name
    sorted_insert_name(&head, "mno", 25);
    sorted_insert_name(&head, "abc", 5);
    printf("\nList after sorted insertion by name:\n");
    display(head);

    // Insert nodes in sorted order by value
    sorted_insert_val(&head, "pqr", 18);
    sorted_insert_val(&head, "uvw", 8);
    printf("\nList after sorted insertion by value:\n");
    display(head);

    return 0;
}

