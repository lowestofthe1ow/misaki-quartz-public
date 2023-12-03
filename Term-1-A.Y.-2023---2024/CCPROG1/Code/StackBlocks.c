#include <stdio.h>

int main() {
	int nRows = 0;
	int nBlocks;
	int nBlocksInRow = 1;
	
	printf("Enter number of blocks: ");
	scanf("%d", &nBlocks);
	printf("\n");
	
	while (nBlocks >= nBlocksInRow) {
		nRows++;
		nBlocks -= nBlocksInRow;
		for (int i = 0; i < nBlocksInRow; i++) {
			printf("[]");
		}
		printf("\n");
		nBlocksInRow++;
	}
	if (nBlocks > 0) {
		for (int i = 0; i < nBlocks; i++) {
			printf("[]");
		}
		printf("\n\nLast row is incomplete with %d blocks out of %d.", nBlocks, nBlocksInRow);
	}
	
	printf("\n%d complete row(s).", nRows);
	
	return 0;
}
