#include <stdio.h>

void myFunction() {
    // Display file name, function name, and line number
    printf("File name: %s\n", __FILE__);
    printf("Function name: %s\n", __FUNCTION__);
    printf("Line number: %d\n", __LINE__);
}

int main() {
    // Display file name, function name, and line number
    printf("File name: %s\n", __FILE__);
    printf("Function name: %s\n", __FUNCTION__);
    printf("Line number: %d\n", __LINE__);

    // Call a function that also uses the predefined macros
    myFunction();
    
    return 0;
}

