#include <stdio.h>

int main() {
	int nRows, nColumns;
	
	printf("Enter the number of rows: ");
	scanf("%d", &nRows);
	
	printf("Enter the number of columns: ");
	scanf("%d", &nColumns);
	
	for (int i = 0; i < nRows; i++) {
		for (int i = 0; i < nColumns; i++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
