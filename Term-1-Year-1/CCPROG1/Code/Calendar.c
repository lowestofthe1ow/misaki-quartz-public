#include <stdio.h>

int main() {
	int nDaysInMonth, nStartingDay;
	
	printf("Enter number of days in month: ");
	scanf("%d", &nDaysInMonth);
	
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &nStartingDay);
	
	for (int i = 1; i < nDaysInMonth + nStartingDay; i++) {
		if (i < nStartingDay) {
			printf("  ");
		}
		else {
			printf("%2d", i - nStartingDay + 1);
		}
		if (i % 7 == 0) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	};
	
	return 0;
}
