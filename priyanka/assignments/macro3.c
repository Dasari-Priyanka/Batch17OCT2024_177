#include <stdio.h>
#include "macro3.h"  // Include the header file with macros

int main() {
    float radius = 5.0;
    float base = 10.0;
    float height = 8.0;

    // Calculate and display the area of a circle
    float circle_area = AREA_CIRCLE(radius);
    printf("Area of the circle with radius %.2f: %.2f\n", radius, circle_area);

    // Calculate and display the area of a triangle
    float triangle_area = AREA_TRIANGLE(base, height);
    printf("Area of the triangle with base %.2f and height %.2f: %.2f\n", base, height, triangle_area);

    return 0;
}

