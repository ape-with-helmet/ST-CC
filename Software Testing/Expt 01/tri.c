#include <stdio.h>

const char* triangleType(int a, int b, int c) {
    /*
    Function to determine if the triangle is possible and, if so, return the type of triangle.
    Input: 3 integer values representing sides of the triangle
    Output: A string indicating the type of triangle or an error message
    */
    if (a < 1 || b < 1 || c < 1 || a > 10 || b > 10 || c > 10) {
        printf("Limits exceeded...\nTerminating program!\n");
        return "Invalid";
    }
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c)
            return "Equilateral";
        else if (a == b || b == c || a == c)
            return "Isosceles";
        else
            return "Scalene";
    } else {
        return "Not a triangle";
    }
}

void manual() {
    /*
    Function for manual testing of the triangle type program
    Input: no input
    Output: no return value
    */
    printf("Running Manual testing...\n");
    int a, b, c;
    printf("Enter the sides of the triangle (1-10): ");
    scanf("%d %d %d", &a, &b, &c);
    const char* result = triangleType(a, b, c);
    if (result != "Invalid") {
        printf("The triangle type: %s\n", result);
    }
}

void OutputBVA() {
    /*
    Function to test Boundary Value Analysis (BVA) output with a set of 31 test cases
    Input: no input
    Output: no return value
    */
    printf("Running OutputBVA...\n");
    int a[] = {1, 2, 3, 1, 5, 9, 10, 10, 10, 11, 10, 10, 12, 10, 10, 4, 7, 8, 8, 8, 9, 8, 8, 10, 8, 8, 4, 6, 6, 6, 6};
    int b[] = {1, 2, 3, 1, 5, 9, 9, 10, 10, 10, 11, 9, 10, 11, 9, 5, 7, 7, 8, 8, 9, 9, 9, 10, 8, 8, 9, 9, 9, 9, 10};
    int c[] = {1, 2, 1, 2, 5, 9, 9, 9, 10, 10, 10, 11, 9, 9, 12, 3, 7, 7, 7, 8, 8, 9, 9, 10, 10, 10, 6, 6, 6, 6, 6};
    for (int i = 0; i < 31; i++) {
        printf("TC%d: %d, %d, %d\t", i, a[i], b[i], c[i]);
        const char* result = triangleType(a[i], b[i], c[i]);
        printf("Output: %s\n", result);
    }
}

void BVA() {
    /*
    Function to test Boundary Value Analysis (BVA) using edge cases for triangle type.
    Input: no input
    Output: no return value
    */
    printf("Running BVA test...\n");
    int a[] = {1, 2, 5, 9, 10};
    int b[] = {1, 2, 5, 9, 10};
    int c[] = {1, 2, 5, 9, 10}, count = 0;
    
    // BVA for the first side
    for (int i = 0; i < 5; i++) {
        printf("TC%d: %d, %d, %d\t", count, a[i], 5, 5);
        const char* result = triangleType(a[i], 5, 5);
        printf("Output: %s\n", result);
        count++;
    }
    
    // BVA for the second side
    for (int i = 0; i < 5; i++) {
        printf("TC%d: %d, %d, %d\t", count, 5, b[i], 5);
        const char* result = triangleType(5, b[i], 5);
        printf("Output: %s\n", result);
        count++;
    }
    
    // BVA for the third side
    for (int i = 0; i < 5; i++) {
        printf("TC%d: %d, %d, %d\t", count, 5, 5, c[i]);
        const char* result = triangleType(5, 5, c[i]);
        printf("Output: %s\n", result);
        count++;
    }
}

void main() {
    /*
    Main function to select the testing method.
    Input: no input
    Output: no return value
    */
    int sel;
    printf("Manual test(0)\nOutputBVA(1)\nBVA(2): ");
    scanf("%d", &sel);
    if (sel == 0) manual();
    else if (sel == 1) OutputBVA();
    else if (sel == 2) BVA();
    else printf("Invalid input\n");
}
