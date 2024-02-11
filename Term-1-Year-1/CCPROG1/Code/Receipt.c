#include <stdio.h>

#define AMOUNT 90.00
#define TAX 0.12
#define TIP1 0.15
#define TIP2 0.18
#define TIP3 0.20

float computeTotal(int nOrders) {
	float fTotal;
	fTotal = nOrders * AMOUNT;	
	return fTotal;
}

float computeGross(int fPrice) {
	return fPrice / (1 + TAX);
}

float computeTax(int fGross) {
	return fGross * TAX;
}

void displayDivider() {
	printf("%s%s%s%s\n", "----------", "----------", "----------", "----------");
}

void displayCenterText() {
	printf("%24s\n", "MyKitchen");
}

int main() {
	int nDate;
	int nOrders;
	float fPrice;
	float fGross;
	float fTax;
	
	printf("Enter date: ");
	scanf("%d", &nDate);
	
	printf("Enter qty. of orders: ");
	scanf("%d", &nOrders);
	
	displayDivider();
	
	displayCenterText();
	displayDivider();
	
	fPrice = computeTotal(nOrders);
	fGross = computeGross(fPrice);
	fTax = computeTax(fGross);
	
	printf("Gross price = %.2f\n", fGross);
	printf("Tax price = %.2f\n", fTax);
	
	displayDivider();
	
	printf("Total price = %.2f\n", fPrice);
	
	return 0;                              
}