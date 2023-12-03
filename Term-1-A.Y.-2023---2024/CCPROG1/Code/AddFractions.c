#include <stdio.h>

int findGCD(int nNum1, int nNum2) {
    if (nNum1 == 0) {
    	return nNum2;
	}
    return findGCD(nNum2 % nNum1, nNum1);
}

int main() {
	int nNum1, nDen1, nNum2, nDen2;
	
	printf("Enter 1st fraction (x/y): ");
	scanf("%d/%d", &nNum1, &nDen1);
	
	printf("Enter 2nd fraction (x/y): ");
	scanf("%d/%d", &nNum2, &nDen2);
	
	int nNum3 = nNum1 * nDen2 + nNum2 * nDen1;
	int nDen3 = nDen1 * nDen2;
	
	printf("Sum: %d/%d\n", nNum3, nDen3);
	
	int nGCD = findGCD(nNum3, nDen3);
	
	printf("GCD: %d\n", nGCD);
	printf("Lowest terms: %d/%d", nNum3 / nGCD, nDen3 / nGCD);
	
	return 0;
}
