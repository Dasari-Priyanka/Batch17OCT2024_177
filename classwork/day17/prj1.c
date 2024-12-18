#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store Employee details
struct Employee {
    int id;
    char name[100];
    float salary;
};

// Node structure for Linked List (used for Stack)
struct Node {
    struct Employee emp;    // Employee data
    struct Node* next;      // Pointer to next node in the stack
};

// Function to push a new employee onto the stack
void push(struct Node** top, int id, const char* name, float salary) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize employee data
    newNode->emp.id = id;
    strcpy(newNode->emp.name, name);
    newNode->emp.salary = salary;

    // Link the new node to the top of the stack
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an employee from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty, no employee to pop.\n");
        return;
    }

    struct Node* temp = *top;
    *top = (*top)->next; // Move the top pointer to the next node

    printf("Popped employee: ID=%d, Name=%s, Salary=%.2f\n",
           temp->emp.id, temp->emp.name, temp->emp.salary);
    free(temp); // Free the memory of the popped node
}

// Function to display all employee details in the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("Employee ID: %d, Name: %s, Salary: %.2f\n",
               temp->emp.id, temp->emp.name, temp->emp.salary);
        temp = temp->next;
    }
}

// Main function to test the stack with employee details
int main() {
    struct Node* stackTop = NULL; // Initialize an empty stack
    
    int choice, id;
    char name[100];
    float salary;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push Employee\n");
        printf("2. Pop Employee\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Push employee details onto the stack
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                getchar();  // To clear the buffer
                printf("Enter Employee Name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0; // Remove the trailing newline character
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                
                push(&stackTop, id, name, salary);
                break;
                
            case 2:
                // Pop the top employee from the stack
                pop(&stackTop);
                break;
                
            case 3:
                // Display all employees in the stack
                displayStack(stackTop);
                break;
                
            case 4:
                // Exit the program
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
