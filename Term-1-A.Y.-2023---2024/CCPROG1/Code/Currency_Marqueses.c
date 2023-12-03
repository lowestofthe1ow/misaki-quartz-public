 #include <stdio.h>
/* Lorenz Bernard B. Marqueses */

int getDenom1000(int* nInput) {
	int nDenomNumber = *nInput / 1000;
	*nInput -= nDenomNumber * 1000;
	return nDenomNumber;
}

int getDenom500(int* nInput) {
	int nDenomNumber = *nInput / 500;
	*nInput -= nDenomNumber * 500;
	return nDenomNumber;
}

int getDenom200(int* nInput) {
	int nDenomNumber = *nInput / 200;
	*nInput -= nDenomNumber * 200;
	return nDenomNumber;
}

int getDenom100(int* nInput) {
	int nDenomNumber = *nInput / 100;
	*nInput -= nDenomNumber * 100;
	return nDenomNumber;
}

int getDenom50(int* nInput) {
	int nDenomNumber = *nInput / 50;
	*nInput -= nDenomNumber * 50;
	return nDenomNumber;
}

int getDenom20(int* nInput) {
	int nDenomNumber = *nInput / 20;
	*nInput -= nDenomNumber * 20;
	return nDenomNumber;
}

int getDenom10(int* nInput) {
	int nDenomNumber = *nInput / 10;
	*nInput -= nDenomNumber * 10;
	return nDenomNumber;
}

int getDenom5(int* nInput) {
	int nDenomNumber = *nInput / 5;
	*nInput -= nDenomNumber * 5;
	return nDenomNumber;
}

int getDenom1(int* nInput) {
	int nDenomNumber = *nInput;
	*nInput -= nDenomNumber;
	return nDenomNumber;
}

int main() {
	int nInput;
	
	printf("Amount P: ");
	scanf("%d", &nInput);
	
	printf("P1000: %d\n", getDenom1000(&nInput));
	printf("P500: %d\n", getDenom500(&nInput));
	printf("P200: %d\n", getDenom200(&nInput));
	printf("P100: %d\n", getDenom100(&nInput));
	printf("P50: %d\n", getDenom50(&nInput));
	printf("P20: %d\n", getDenom20(&nInput));
	printf("P10: %d\n", getDenom10(&nInput));
	printf("P5: %d\n", getDenom5(&nInput));
	printf("P1: %d\n", getDenom1(&nInput));
	
	return 0;
}
