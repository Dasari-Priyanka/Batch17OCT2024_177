#include <stdio.h>

// Tail-recursive factorial function with an accumulator
int factorial_helper(int n, int accumulator) {
    if (n <= 1) {
        return accumulator;  // Base case returns the accumulated result
    } else {
        return factorial_helper(n - 1, n * accumulator);  // Tail-recursive call
    }
}

int factorial(int n) {
    return factorial_helper(n, 1);  // Start the recursion with an initial accumulator value
}

int main() {
    int n = 5;
    printf("Factorial of %d is: %d\n", n, factorial(n));
    return 0;
}

