#include<stdio.h>

float commission(int locks, int stocks, int barrels) {
	/*
	Function takes calculates the commission of items for sale
	Input: Takes 3 integer values
	Output: 1 Floating point value
	*/
	float commission, lockprice = 45.0, stockprice = 30.0, barrelprice = 25.0, total = 0.0;
	if (locks>70 || locks<1 || stocks>80 || stocks<1 || barrels>90 || barrels<1){
		printf("Limits exceeded...\nTerminating program!\n");
		return 0;
	}
	total += lockprice*locks;
	total += stockprice*stocks;
	total += barrelprice*barrels;
	printf("Sales: %.0f\t", total);
	if (total > 1800) return 220+((total-1800)*0.2);
	else if (total > 1000) return 100+((total-1000)*0.15);
	else return total*0.1;
}
	
void manual() {
	/*
	Function allows user to input 3 integer values
	Input: no input
	Output: no return value
	*/
	printf("Running Manual testing...\n");
	int locks, stocks, barrels;
	printf("Enter the sales numbers of locks, stocks, barrels: ");
	scanf("%d", &locks);
	if (locks == -1) {
		locks = 70;
		stocks = 80;
		barrels = 90;
	}
	else scanf("%d%d", &stocks, &barrels);
	float comm = commission(locks,stocks,barrels);
	if (comm == 0) return;
	printf("The commission for the entered sales: %.2f\n", comm);
}

void OutputBVA() {
	/*
	Function runs a set of 31 tests for BVA values
	Input: no input
	Output: no return value
	*/
	printf("Running OutputBVA...\n");
	int locks[] = {1,2,1,1,5,9,10,10,10,11,10,10,12,10,10,14,17,18,18,18,19,18,18,20,18,18,48,69,70,70,70};
	int stocks[] = {1,1,2,1,5,10,9,10,10,10,11,10,10,12,10,14,18,17,18,18,18,19,18,18,20,18,48,80,79,80,80};
	int barrels[] = {1,1,1,2,5,10,10,9,10,10,10,11,10,10,12,14,18,18,17,18,18,18,19,18,18,20,48,90,90,89,90};
	for (int i=0; i<31; i++){
		printf("TC%d: %d,%d,%d\t", i, locks[i], stocks[i], barrels[i]);
		float com = commission(locks[i],stocks[i],barrels[i]);
		printf("Output: %.2f\n", com);
	}
}

void BVA() {
	/*
	Function runs test cases for Boundary Value Analysis
	Input: No inputs
	Output: No outputs
	*/
	print("Running BVA test...\n");
	int locks[] = {1,2,35,69,70};
	int stocks[] = {1,2,40,79,80};
	int barrels[] = {1,2,45,89,90}, count = 0;
	for (int i=0; i<5; i++) {
		printf("TC%d: %d,%d,%d\t", count, locks[i], stocks[2], barrels[2]);
		float com = commission(locks[i],stocks[2],barrels[2]);
		printf("Output: %.2f\n", com);
		count++;
	}
	for (int i=0; i<5; i++) {
		printf("TC%d: %d,%d,%d\t", count, locks[2], stocks[i], barrels[2]);
		float com = commission(locks[2],stocks[i],barrels[2]);
		printf("Output: %.2f\n", com);
		count++;
	}
	for (int i=0; i<5; i++) {
		printf("TC%d: %d,%d,%d\t", count, locks[2], stocks[2], barrels[i]);
		float com = commission(locks[2],stocks[2],barrels[i]);
		printf("Output: %.2f\n", com);
		count++;
	}
}

void main() {
	/*
	Main function which allows user to choose what testing to use
	Input: no input
	Output: no return value
	*/
	int sel;
	printf("Manual test(0)\nOutputBVA(1)\nBVA(2): ");
	scanf("%d",&sel);
	if (sel==0) manual();
	else if (sel==1) OutputBVA();
	else if (sel==2) BVA();
	else printf("invalid input");
}
