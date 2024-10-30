#include<stdio.h>
void tri(int a, int b, int c){
	if (a<1||a>10||b<1||b>10||c<1||c>10){
		printf("Value Out of bound");
		return;
	}
	if (a+b<=c||b+c<=a||a+c<=b){
		printf("Triangle cannot be formed!");
		return;
	}
	if (a==b&&b==c) {
		printf("Equilateral!");
		return;
	}
	if (a==b||b==c||a==c) {
		printf("isosceles!");
		return;
	}
	else 
		printf("Scalene!");
	return;
}

void manual() {
	int a,b,c;
	printf("Enter the 3 sides: ");
	scanf("%d%d%d",&a,&b,&c);
	tri(a,b,c);
}

void wn() {
	int a[4] = {3,5,2,10};
	int b[4] = {4,5,5,5};
	int c[4] = {5,5,5,5};
	printf("Weak Normal testing...\n");
	printf("tcid\ta b c\toutput\n");
	for(int i=0;i<4;i++){
		printf("WN%d\t%d %d %d\t",i+1,a[i],b[i],c[i]);
		tri(a[i],b[i],c[i]);
		printf("\n");
	}
}

void sn() {
	int testid=1;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {1,2,3,4,5,6,7,8,9,10};
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("Strong Normal testing...\n");
	printf("tcid\ta b c\toutput\n");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				printf("SN%d\t%d %d %d\t",testid++,a[i],b[j],c[k]);
				tri(a[i],b[j],c[k]);
				printf("\n");
			}
		}
		
	}
}

void wr() {
	int a[6] = {11,3,3,0,3,3};
	int b[6] = {3,11,2,3,0,2};
	int c[6] = {2,2,11,2,2,0};
	printf("Weak Robust testing...\n");
	printf("tcid\ta b c\toutput\n");
	for(int i=0;i<6;i++){
		printf("WR%d\t%d %d %d\t",i+1,a[i],b[i],c[i]);
		tri(a[i],b[i],c[i]);
		printf("\n");
	}
}


void sr() {
	int a[8] = {11,11,5,0,0,0,11,0};
	int b[8] = {11,5,11,0,5,0,11,0};
	int c[8] = {5,11,11,5,0,5,11,0};
	printf("Strong Robust testing...\n");
	printf("tcid\ta b c\toutput\n");
	for(int i=0;i<8;i++){
		printf("WN%d\t%d %d %d\t",i+1,a[i],b[i],c[i]);
		tri(a[i],b[i],c[i]);
		printf("\n");
	}
}

void main() {
	wn();
	sn();
	wr();
	sr();
	manual();
}
