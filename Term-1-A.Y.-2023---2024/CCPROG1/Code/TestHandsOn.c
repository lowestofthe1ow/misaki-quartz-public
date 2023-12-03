#include <stdio.h>

void powOf10(int n, int *res)
{
	/* TODO fill your code. You are free
       to declare as many variables as you wish
	
       REQUIREMENT: Your solution should call the following function
   	                expInt() which returns the value of base raised to power.
     
            FUNCTION PROTOTYPE:  int expInt (int base, int power);
	
	   ex:
	   expInt(5, 2) returns 25
	   expInt(3, 3) returns 27
	*/
   	*res = expInt(10, n);
}

int main() {

	int output;
	powOf10(2, &output);
	printf("%d", output);
	
}
