#include <stdio.h>

int factorial(int nN) {
	int nResult = nN;
	if (nN == 0) {
		nResult = 1;
	} else {
		for (int i = 1; i < nN; i++) {
	        nResult *= i;
	    }
	}
	return nResult;
}

int main() {
	int nN;
	float result;
	
	printf("Enter a positive integer n: ");
	scanf("%d", &nN);
	
	for (int i = 0; i <= nN; i++) {
		result += 1.0 / factorial(i);
	}
	
	printf("e is approx. %f", result);
	
	return 0;
}
