#include <stdio.h>

int main () {
	int x, y = 0, i, j, k, l;
	int z = 1;
	printf("Enter a number: ");
	scanf("%d", &x);
	
	for (i = x / 2 + 1; i > 0; i -= 2) {
		for (j = y; j > 0; j--) {
			printf("%d", z);
			z++;
		}
			
		for (k = i; k > 0; k--)
			printf("X");
		for (l = y; l > 0; l--) {
			printf("%d", z);
			z++;
		}
		
		printf("\n");
		y++;
	}
	y = 0;
	for (i = 0; i < x / 2; i += 2) {
		for (j = y; j > 0; j--) {
			printf("%d", z);
			z++;
		}
			
		for (k = i; k > 0; k--)
			printf("X");
		for (l = y; l > 0; l--) {
			printf("%d", z);
			z++;
		}
		
		printf("\n");
		y++;
	}
}
