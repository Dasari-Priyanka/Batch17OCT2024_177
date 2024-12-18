// main.c

#include "list.h"

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

