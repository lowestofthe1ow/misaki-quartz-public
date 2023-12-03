#include <stdio.h>

float toUSD(float input) {
	return input * 0.02;
}

float toJPY(float input) {
	return input * 2.61;
}

float toHKD(float input) {
	return input * 0.14;
}

int main() {
	float input;
	
	printf("Enter value in PHP: ");
	scanf("%f", &input);
	
	printf("%.2f PHP =\n\n%.2f USD\n%.2f JPY\n%.2f HKD", input, toUSD(input), toJPY(input), toHKD(input));
	
	return 0;
}
