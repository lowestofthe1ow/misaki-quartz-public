#include <stdio.h>
#include <math.h>

/*
	getSquare() : Calculate the square of two floats
	-returns a float
*/

float getSquare() {
	
}


/*
	getCoefficentB() : Calculate the coefficient of B 
	-returns a float
*/

/*
	getCoefficentC() : Calculate the coefficient of C
	-returns a float 
*/

/*
	getDiscriminant() : Calculates the discriminant
	-returns a float
*/

/* 
	getRoot1() : Calculates quadratic formula where the plus-minus is plus
	-returns a float
/*

/* 
	getRoot2() : Calculates quadratic formula where the plus-minus is minus
	-returns a float
/*

	getRoots() : Calculates the roots depending on the discriminant value
	-returns a float
	-this must call either getRoot1() or getRoot2() or both 
*/

/*
	getAnswer() : Checks the roots and gives the answer accordingly and returns the answer			
	-prints the answers 
	-this checks for an extraneous solution
*/



int main(){
	
	float fPhotoLength, fPhotoWidth, fCutOff, fSmaller, fCoefficientB, fCoefficientC;
	
	printf("---Function: Calculate Strip Width---\n");
	printf("Enter Photo Length: ");
	scanf("%f", &fPhotoLength);
	printf("Enter Photo Width: ");
	scanf("%f", &fPhotoWidth);
	printf("Area Cut Off: ");
	scanf("%f", &fCutOff);
	
	fSmaller = getSmaller(fPhotoLength, fPhotoWidth);
	fCoefficientB = getCoefficientB(fPhotoLength, fPhotoWidth);
	fCoefficientC = getCoefficientC(fPhotoLength, fPhotoWidth, fCutOff);
	
	if (/*Enter the controlling expression to eliminate wrong input*/)
		printf("Invalid Inputs");
	else{
	getRoots(fCoefficientB, fCoefficientC, fSmaller);
	return 0;
	
}
