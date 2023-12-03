#include <stdio.h>

int getTime(float nWeight) {
	return nWeight / 7;
}

float getPrice(float nWeight) {
	
}

int main() {
	float fLength, fWidth, fHeight;
	int time;
	
	printf("Enter dimensions (LxWxH): ");
	scanf("%fx%fx%f", &fLength, &fWidth, &fHeight);
	
	float nWeight = fLength * fWidth * fHeight;
	
	if(nWeight >= 103.5 && nWeight <= 1030.5) {
		time = getTime(nWeight);
	} else {
		printf("Dimensional weight must be lower than 103.5 or higher than 1030.5. (Weight: %.2f)\n", nWeight);
	}
	
	printf("Are you a returning member (y/n)");
	
	char
	
	return 0;
}
