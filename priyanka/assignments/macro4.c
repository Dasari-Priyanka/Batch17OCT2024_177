#include <stdio.h>

// Uncomment the line below to enable CUST_PRINT
//#define CUST_PRINT

#ifdef CUST_PRINT
    #define MYPRINT(x) printf(x)  // MYPRINT will only be defined if CUST_PRINT is defined
#else
    #define MYPRINT(x)  // If CUST_PRINT is not defined, MYPRINT does nothing
#endif

int main() {
    // MYPRINT will be executed only if CUST_PRINT is defined
    MYPRINT("Hello World\n");

    // This printf will always be executed
    printf("Test\n");

    return 0;
}

