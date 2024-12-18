#include <stdio.h>

#define MIN(arr, n) ({ \
    int min = arr[0]; \
    for(int i = 1; i < n; i++) { \
        if(arr[i] < min) { \
            min = arr[i]; \
        } \
    } \
    min; \
})

int main() {
    int arr[] = {10, 2, 33, 44, -5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = MIN(arr, n);
    printf("The smallest number in the array is: %d\n", smallest);

    return 0;
}
