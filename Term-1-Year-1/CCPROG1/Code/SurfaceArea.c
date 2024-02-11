#include <stdio.h>

int main() {
	float fSP, fSL, fBA;
	printf("Enter the square perimeter, slant length, and base area:\n");
	scanf("%f %f %f", &fSP, &fSL, &fBA);
	printf("The surface area is: %.2f.\n", 0.5 * fSP * fSL + fBA);
	
	return 0;
}


