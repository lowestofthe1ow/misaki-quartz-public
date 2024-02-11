#include <stdio.h>

int main() {
	float fItemPrice;
	float fTaxRate;
	
	printf("Item price: ");
	scanf("%f", &fItemPrice);
	printf("Tax rate (in percent): ");
	scanf("%f", &fTaxRate);
	
	float fTaxVal = fItemPrice / (1 + 0.01 * fTaxRate);
	
	printf("\nBefore Tax: %.2f\n", fTaxVal);
	printf("Tax (%.2f): %.2f\n", fTaxRate, fTaxVal);
	
	return 0;
}
