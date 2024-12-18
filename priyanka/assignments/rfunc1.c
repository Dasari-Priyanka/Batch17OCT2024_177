#include <stdio.h>

// Global variable to store the maximum recursion depth
int max_depth = 0;

// Function to calculate factorial with tracking of recursion depth
int factorial(int n, int depth) {
    // Update the maximum depth if current depth is greater
    if (depth > max_depth) {
        max_depth = depth;
    }
    
    // Base case for recursion to stop
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1, depth + 1);
    }
}

int main() {
    int n = 5;  // You can change this value to test with different inputs
    // Start the factorial calculation with an initial depth of 0
    factorial(n, 0);

    // Output the maximum recursion depth
    printf("The maximum stack depth for factorial(%d) is: %d\n", n, max_depth);

    return 0;
}

