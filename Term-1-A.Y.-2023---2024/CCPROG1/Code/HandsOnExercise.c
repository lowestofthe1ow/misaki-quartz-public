#include <stdio.h>

int getPlace(int num) 
{
	int nPlace = 1;
	while (num > 0) {
		num /= 10;
		nPlace *= 10;
	}
	return nPlace / 10;
}

int getHighest(int nNum)
{
	int nHighest = 0, i;
	for (i = nNum; i > 0; i /= 10) {
		if (i % 10 > nHighest)
			nHighest = i % 10;
	}	
	return nHighest;
}

int main() {
	int nNum, nHighest, nPrevDigit, i, j;
	int nContinuous = 1;
	
	printf("Enter a number: ");
	scanf("%d", &nNum);

	printf(" [");
	for (i = nNum; i > 0; i /= 10) {
		printf("=");
	}
	printf("]\n");
	
	for (i = 1; i <= getHighest(nNum); i++) {
		printf("%d|", i);
		nPrevDigit = nNum / getPlace(nNum);
		
		for (j = nNum; j > 0; j %= getPlace(j)) {
			if (j / getPlace(j) == i)
				printf("*");
			else
				printf(" ");
			
			if (nPrevDigit - j / getPlace(j) > 1 || j / getPlace(j) - nPrevDigit > 1)
				nContinuous = 0;
				
			nPrevDigit = j / getPlace(j);
		}
		
		printf("|\n");
	}
	
	printf(" [");
	for (i = nNum; i > 0; i /= 10) {
		printf("=");
	}
	printf("]\n");
	
	if (nContinuous)
		printf("The line is continuous.");
	else
		printf("The line is not continuous.");
		
	return 0;
}
