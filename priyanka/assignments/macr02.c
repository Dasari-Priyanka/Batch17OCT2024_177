#include <stdio.h>

#define MYPROD(x) ((x) * (x))  // Corrected macro

int main() {
    int result1, result2;

    // Invoking the macro with different inputs
    result1 = MYPROD(2+1);  // This should now give 9
    result2 = MYPROD(6+1);  // This should now give 49

    // Displaying the results
    printf("Result of MYPROD(2+1): %d\n", result1);  // Expected 9
    printf("Result of MYPROD(6+1): %d\n", result2);  // Expected 49

    return 0;
}

