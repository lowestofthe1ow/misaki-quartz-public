#include <stdio.h>

int main() {
	int nInput;
	
	printf("Enter a number (1-3): ");
	scanf("%d", &nInput);
	
	if (nInput == 1)
		printf("Red");
	else if (nInput == 2)
		printf("Yellow");
	else if (nInput == 3)
		printf("Green");
	else
		printf("Input not in range");
		
	return 0;
}
