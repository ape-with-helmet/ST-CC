# Triangle Type Determination Program

## Overview
This C program determines the type of triangle based on the lengths of its sides. It includes functions for manual testing, Boundary Value Analysis (BVA), and structured testing cases to validate triangle properties.

## Functions

### 1. `triangleType(int a, int b, int c)`
- **Purpose**: Determines if a triangle is possible with given sides and returns the type of triangle.
- **Parameters**:
  - `int a`: Length of the first side.
  - `int b`: Length of the second side.
  - `int c`: Length of the third side.
- **Returns**: A string indicating the type of triangle ("Equilateral", "Isosceles", "Scalene", "Not a triangle") or "Invalid" if input is out of limits.

### 2. `manual()`
- **Purpose**: Facilitates manual testing of the triangle type function.
- **Output**: Prompts the user to enter the lengths of the triangle sides and displays the resulting triangle type.

### 3. `OutputBVA()`
- **Purpose**: Executes a set of 31 test cases for Boundary Value Analysis (BVA).
- **Output**: Displays the test case inputs and corresponding outputs for triangle type determination.

### 4. `BVA()`
- **Purpose**: Tests the triangle type function using edge cases for Boundary Value Analysis (BVA).
- **Output**: Displays test case inputs and corresponding outputs for varying lengths of triangle sides.

### 5. `main()`
- **Purpose**: Main function to select the testing method (manual testing, Output BVA, or BVA).
- **Input**: User input to select the testing method.
- **Output**: Executes the corresponding testing function based on user selection.

## Usage
1. Compile the program using a C compiler:
   ```bash
   gcc triangle.c -o triangle
    ```
2. Run the executable:
    ```bash
    ./triangle
    ```
3. Select the testing method by entering:
*   `0` for manual testing.
*   `1` for executing the output BVA tests.
*   `2` for executing edge case BVA tests.

## Example outputs
* For manual testing, if the user enters 3, 4, 5 the output will be:
    ```bash
    The triangle type: Scalene
    ```
* For BVA tests, the output will display structured test cases:
    ```yaml
    Running OutputBVA...
    TC0: 1, 1, 1	Output: Equilateral
    TC1: 2, 2, 2	Output: Equilateral
    TC2: 3, 3, 3	Output: Equilateral
    TC3: 1, 1, 2	Output: Not a triangle
    TC4: 5, 5, 5	Output: Equilateral
    TC5: 9, 9, 9	Output: Equilateral
    TC6: 10, 10, 9	Output: Isosceles
    TC7: 10, 10, 10	Output: Equilateral
    TC8: 10, 9, 10	Output: Isosceles
    TC9: 11, 10, 10	Output: Invalid
    ```
* For BVA testing, you may see:
    ```yaml
    Running BVA test...
    TC0: 1, 5, 5	Output: Isosceles
    TC1: 2, 5, 5	Output: Isosceles
    TC2: 5, 5, 5	Output: Equilateral
    TC3: 9, 5, 5	Output: Not a triangle
    TC4: 10, 5, 5	Output: Not a triangle
    ```
## Limitations
* The side lengths must be between 1 and 10 inclusive.
* If any side length exceeds these limits, an "Invalid" message will be displayed, and the program will terminate.

## Conclusion
This program effectively categorizes triangles based on user-provided side lengths and includes various testing methods to ensure its reliability and accuracy in determining triangle types.
```typescript

Feel free to copy and save this content as a `.md` file, for example, `triangle_program.md`. Let me know if you need any further adjustments!
```