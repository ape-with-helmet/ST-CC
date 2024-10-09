#include <stdio.h>
#include <stdbool.h>

// Function to check if the year is a leap year
bool isLeap(int y) {
    // A leap year is divisible by 400 or divisible by 4 but not by 100
    if (y % 100 == 0 && y % 400 == 0) return true;  // Divisible by both 100 and 400
    else if (y % 4 == 0 && y % 100 != 0) return true;  // Divisible by 4 but not 100
    else return false;  // Otherwise, not a leap year
}

// Function to calculate the next date based on the current day, month, and year
void nextDate(int *d, int *m, int *y) {
    // Validate the input limits for day, month, and year
    if (*d < 1 || *d > 31 || *m < 1 || *m > 12 || *y < 1812 || *y > 2012) {
        printf("Limits exceeded... Terminating program!\n");
        return;
    }

    // Special case for February (month 2)
    if (*m == 2) {
        // Check if the year is a leap year
        if (isLeap(*y)) {
            // Leap year: February has 29 days
            if (*d < 29) (*d)++;  // Increment the day if it's less than 29
            else if (*d == 29) {  // If it's the 29th, reset to the 1st of March
                *d = 1;
                (*m)++;
            }
        } else {
            // Non-leap year: February has 28 days
            if (*d < 28) (*d)++;  // Increment the day if it's less than 28
            else if (*d == 28) {  // If it's the 28th, reset to the 1st of March
                *d = 1;
                (*m)++;
            }
        }
    }
    // Months with 31 days: January, March, May, July, August, October, December
    else if (*m == 1 || *m == 3 || *m == 5 || *m == 7 || *m == 8 || *m == 10 || *m == 12) {
        if (*d == 31) {
            *d = 1;  // If it's the 31st, reset to the 1st of the next month
            (*m)++;
            if (*m > 12) {  // If month exceeds 12, reset to January of the next year
                *m = 1;
                (*y)++;
            }
        } else {
            (*d)++;  // Increment the day if it's less than 31
        }
    }
    // Months with 30 days: April, June, September, November
    else if (*m == 4 || *m == 6 || *m == 9 || *m == 11) {
        if (*d == 30) {
            *d = 1;  // If it's the 30th, reset to the 1st of the next month
            (*m)++;
        } else {
            (*d)++;  // Increment the day if it's less than 30
        }
    }
}

// Function to manually input a date and calculate the next date
void manual() {
    int d, m, y;
    // Prompt the user to input day, month, and year
    printf("Enter Date, Month, and Year (yyyy-mm-dd): ");
    scanf("%d %d %d", &d, &m, &y);

    // Call the nextDate function to calculate the next date
    nextDate(&d, &m, &y);
    // Display the result if the input values are valid
    if (d > 0 && m > 0 && y > 0) {
        printf("Next date: %d/%d/%d\n", d, m, y);
    }
}

// Function to run Boundary Value Analysis (BVA) with predefined test cases
void OutputBVA() {
    // Arrays of test days, months, and years for BVA
    int d[] = {1, 28, 29, 30, 31, 1, 2, 15, 30, 31, 1, 5, 10, 29, 31, 15, 1, 10, 15, 30, 31, 28, 29, 30, 31, 1, 31, 2, 1, 30, 31};
    int m[] = {1, 2, 2, 4, 6, 12, 2, 5, 6, 7, 8, 9, 10, 12, 11, 1, 4, 7, 8, 9, 10, 3, 4, 5, 11, 6, 7, 8, 9, 10, 12};
    int y[] = {1813, 1900, 2000, 2012, 1812, 1820, 1850, 1880, 1901, 1910, 1930, 1950, 1970, 2000, 2012, 2020, 1813, 1812, 2000, 1813, 2001, 1900, 2010, 2005, 1912, 1990, 2012, 2009, 2008, 2011, 2012};
    
    // Loop through the first 5 test cases and print the results
    for (int i = 0; i < 5; i++) {
        printf("Test Case %d: %d/%d/%d\t", i + 1, d[i], m[i], y[i]);
        nextDate(&d[i], &m[i], &y[i]);  // Calculate the next date for each test case
        printf("Next date: %d/%d/%d\n", d[i], m[i], y[i]);
    }
}

// Function to perform BVA testing by checking edge cases for day, month, and year
void BVA() {
    // Arrays for testing edge cases for days, months, and years
    int d[] = {1, 15, 31};  // Boundary Values for days
    int m[] = {1, 6, 12};   // Boundary Values for months
    int y[] = {1813, 1900, 2012};  // Boundary Values for years
    int count = 0;  // Counter for test case numbering

    // BVA for the day
    for (int i = 0; i < 3; i++) {
        printf("TC%d: %d, %d, %d\t", count++, d[i], 5, 2000);  // Test with different days
        nextDate(&d[i], &(int){5}, &(int){2000});  // Call nextDate with constant month and year
    }

    // BVA for the month
    for (int i = 0; i < 3; i++) {
        printf("TC%d: %d, %d, %d\t", count++, 15, m[i], 2000);  // Test with different months
        nextDate(&(int){15}, &m[i], &(int){2000});  // Call nextDate with constant day and year
    }

    // BVA for the year
    for (int i = 0; i < 3; i++) {
        printf("TC%d: %d, %d, %d\t", count++, 15, 5, y[i]);  // Test with different years
        nextDate(&(int){15}, &(int){5}, &y[i]);  // Call nextDate with constant day and month
    }
}

int main() {
    int sel;
    // Display menu for user input
    printf("Manual test(0)\nOutputBVA(1)\nBVA(2): ");
    scanf("%d", &sel);  // Get user's choice

    // Execute the corresponding function based on user's selection
    if (sel == 0) {
        manual();  // Run manual input test
    } else if (sel == 1) {
        OutputBVA();  // Run output-based BVA
    } else if (sel == 2) {
        BVA();  // Run BVA with predefined edge cases
    } else {
        printf("Invalid input\n");  // Handle invalid menu options
    }

    return 0;
}
