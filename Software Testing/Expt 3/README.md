# Design
## Algorithm
- Step 1: Input Date in format DD.MM.YYYY	
- Step 2: if MM is 01, 03, 05, 07, 08, 10 do Step 3 else Step 6
- Step 3: if DD less than 31 then do Step 4 else id DD = 31 do Step 5 else output(invalidDate);
- Step 4: tomorrowDay = DD+1 goto Step 18
- Step 5: tomorrowDay = 1; tomorrowMonth+=1 goto Step 18
- Step 6: if MM is 04, 06, 09, 11 do Step 7
- Step 7: if DD less than 30 then do step 4 else if DD=30 do step 5 else output(invalidDate);
- Step 8: if MM is 12
- Step 9: if DD less than 31 th



- Step 12: if DD less than 28 do Step 4 else do Step 13
- Step 13: if DD = 28 & YYYY is leap, do Step 14 else do Step 15
- Step 14: tomorrowDay = 29 goto Step 18
- Step 15: tomorrowDay = 1, tomorrowMonth = 3, goto Step 18
- Step 16: if DD = 29 then do





### Program Code
```c
	#include<stdio.h>
	int check(int day, int month) {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) return 1;
		else return 0;
	}
	int isLeap(int y) {
		if (((y%4==0)&&(y%100!=0))) return 0;
	}
```
