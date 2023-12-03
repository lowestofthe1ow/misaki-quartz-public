#include <stdio.h>

int getPlace(int num) 
{
	int nPlace = 1;
	while (num > 0) {
		num /= 10;
		nPlace *= 10;
	}
	return nPlace / 10;
}

int rotateRight(int num, int nTimes) 
{
	int i;
	int nPlace = getPlace(num);
	for (i = 0; i < nTimes; i++) {
		num = num / 10 + num % 10 * nPlace;
	}
	return num;
}

int rotateLeft(int num, int nTimes) 
{
	int i;
	int nPlace = getPlace(num);
	for (i = 0; i < nTimes; i++) {
		num = num % nPlace * 10 + num / nPlace;
	}
	return num;
}
void histogram(int num)
{
	int i, j, ctr = 0;
	int placeV;
	int temp = num;
	//int newNum = 0;
	placeV = getPlace(num);
	    
	int sub = num;
	while (sub > 0) {  
		if (sub % 10 > ctr)
			ctr = sub % 10;
		sub /= 10;
	}
	
	printf("Counter: %d\n", ctr);
	    
	for (j = 1; j <= ctr; j++){
	    
	    for (i = placeV; i > 0; i /= 10){
	
	        sub = temp / i % 10;  
	        //sub %= 10;    
	        //newNum += placeV * (sub-1);
	  
	        if (sub >= j)
	        printf("*");
	        else 
	        printf(" ");
	
	    }
	    //temp = newNum;
	    //newNum = 0;
	    
	    printf("\n");
 	}
 }

int main() 
{
	int x = 5;
printf("%d", ++x); // Prints 6

int y = 5;
printf("%d", y++); // Prints 5
printf("%d", y); // Prints 6
}
