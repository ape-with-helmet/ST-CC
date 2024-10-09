
# README: Next Date Program with Boundary Value Analysis (BVA) Testing

## Objective

This program is designed to calculate the next date from a given day, month, and year, considering the nuances of leap years and varying month lengths. Additionally, the program supports **Boundary Value Analysis (BVA)**, a software testing technique that checks edge cases. The BVA testing ensures the program's reliability under different boundary conditions (such as edge cases for dates, months, and years).

The program offers three main functionalities:
1. **Manual Test**: Users can manually input any valid date and receive the next date.
2. **Output-Based BVA**: The program calculates the next date for a predefined set of test cases.
3. **BVA Testing**: The program tests boundary values for days, months, and years to ensure the next date calculations are robust.

The full code is [here](./nextDate.c)
---

## Algorithm

The program follows a straightforward approach to calculate the next date based on the following rules:

1. **Input Validation**:
   - The day must be between `1` and `31`.
   - The month must be between `1` and `12`.
   - The year must be between `1812` and `2012`.

2. **Leap Year Calculation**:
   - A year is a leap year if:
     - It is divisible by `4` and not divisible by `100`, **or**
     - It is divisible by `400`.

3. **Next Date Calculation**:
   - Depending on the month, the program adjusts the day and month appropriately:
     - **February**: Consider leap years for the number of days.
     - **Months with 31 Days**: Reset to `1` and increment month if the day is `31`.
     - **Months with 30 Days**: Reset to `1` and increment month if the day is `30`.

## Code Snippets

The main functions of the program are outlined below:

### Leap Year Function

```c
bool isLeap(int y) {
    if (y % 100 == 0 && y % 400 == 0) return true;
    else if (y % 4 == 0 && y % 100 != 0) return true;
    else return false;
}
```

### Next Date Function

```c
void nextDate(int *d, int *m, int *y) {
    // Input validation
    if (*d < 1 || *d > 31 || *m < 1 || *m > 12 || *y < 1812 || *y > 2012) {
        printf("Limits exceeded... Terminating program!
");
        return;
    }

    // Logic for calculating the next date based on month and day
}
```

### Manual Input Function

```c
void manual() {
    int d, m, y;
    printf("Enter Date, Month, and Year (yyyy-mm-dd): ");
    scanf("%d %d %d", &d, &m, &y);
    nextDate(&d, &m, &y);
    // Output the next date
}
```

### BVA Testing Function

```c
void BVA() {
    // Test boundary values for days, months, and years
}
```

## Outputs

The program outputs the next date based on the user's input or predefined test cases. For example:
- Input: `28 2 2000` (February 28, 2000, a leap year)
- Output: `Next date: 29/2/2000`

## Test Report

The test cases included in the BVA function test various edge cases to ensure the program behaves as expected:

- **Valid Inputs**: Test cases with expected outputs for normal dates, leap years, and boundary values.
- **Edge Cases**: Specific attention to transitions between months and years.

### Sample Test Cases

| Day | Month | Year | Expected Next Date |
|-----|-------|------|---------------------|
| 28  | 2     | 2000 | 29/2/2000           |
| 29  | 2     | 2000 | 1/3/2000            |
| 31  | 12    | 2012 | 1/1/2013            |
| 30  | 4     | 2012 | 1/5/2012            |
| 31  | 1     | 1812 | 1/2/1812            |

---

## Conclusion

This program effectively calculates the next date while ensuring reliability through boundary value analysis. The implementation and tests demonstrate its robustness across a range of scenarios.

For further information, please refer to the code comments and structure.
