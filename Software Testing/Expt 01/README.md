
# Commission Calculation Program (com.c)

This C program, `com.c`, calculates the commission based on sales of three types of items: locks, stocks, and barrels. It also performs testing using manual inputs, Boundary Value Analysis (BVA), and Output Boundary Value Analysis (OutputBVA).

## Features
- **Commission Calculation**: The program calculates commission based on the number of locks, stocks, and barrels sold.
- **Input Validation**: Ensures input values for the number of locks, stocks, and barrels are within their allowed ranges. If the input exceeds the valid range, the program will terminate.
- **Manual Testing**: The user can manually input the number of locks, stocks, and barrels to calculate the commission.
- **Boundary Value Analysis (BVA)**: The program runs test cases for boundary values of the inputs (locks, stocks, barrels).
- **Output Boundary Value Analysis (OutputBVA)**: It also runs a set of predefined test cases to verify the program's output for boundary values.

## How It Works
The program calculates the commission based on the total sales value of the locks, stocks, and barrels using the following conditions:
- If total sales are above $1800, the commission is $220 plus 20% of the sales exceeding $1800.
- If total sales are above $1000 but less than or equal to $1800, the commission is $100 plus 15% of the sales exceeding $1000.
- If total sales are less than or equal to $1000, the commission is 10% of the total sales.

## File Structure
### 1. `commission(int locks, int stocks, int barrels)`
This function takes the number of locks, stocks, and barrels and calculates the total sales and commission based on the conditions outlined above.

### 2. `manual()`
The `manual()` function prompts the user to enter the number of locks, stocks, and barrels. The commission is calculated based on the inputs, and the result is printed.

### 3. `OutputBVA()`
This function runs a set of 31 test cases using boundary values for locks, stocks, and barrels to verify the correctness of the commission calculation.

### 4. `BVA()`
The `BVA()` function runs test cases for boundary value analysis, testing different combinations of boundary values for locks, stocks, and barrels.

### 5. `main()`
The main function allows the user to choose between manual testing, OutputBVA, or BVA. Based on the user's selection, the corresponding function is executed.

## How to Run

### 1. Compile the program
```bash
gcc com.c -o com
```

### 2. Run the program
```bash
./com
```

### 3. Select a test method
When prompted, you can select the desired testing method:
- **Manual test**: Enter 0 to manually input sales data.
- **OutputBVA test**: Enter 1 to run boundary value analysis tests.
- **BVA test**: Enter 2 to run boundary value tests on inputs.

### Example Interaction
```bash
Manual test(0)
OutputBVA(1)
BVA(2): 0
Enter the sales numbers of locks, stocks, barrels: 30 40 50
Sales: 2900   The commission for the entered sales: 340.00
```

## Improvements
- **Dynamic Testing**: Adding more sophisticated test cases or dynamically generating test inputs.
- **Input Validation**: Adding more comprehensive input validation and error handling.
  
## Dependencies
No external dependencies are required. The program runs using standard C libraries.

