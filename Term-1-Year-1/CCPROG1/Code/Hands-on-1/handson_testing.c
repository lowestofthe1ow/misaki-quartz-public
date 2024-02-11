#include <stdio.h>
#include "NicoNicoNii.c"

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

int extractDigit(int nNum, int m)
{
	/* TODO fill your code. You are free
	   to declare as many variables as you wish */
	
	/* Requirements: This function should call powOf10() that you declared
       in the previous number */
    
    int nPow10;
    powOf10(m - 1, &nPow10);
	return nNum / nPow10 % 10;
}

int inTheGroup(int nGroup, int nIdol)
{
	/* DEBUGGING & FILL IN THE BLANK
     
       Requirements: Your solution should call the function findValue()
        FUNCTION PROTOTYPE: void findValue(int nNum, int n, int* res);
   
       @param nNum (int) = Refers to an integer nNum
       @param n (int) = Refers to a digit to search for in nNum
       @param res (int *) = Refers to a memory address that will contain n's
                            corresponding value in nNum
   
       ex:
       let p = pointer variable containing an address of an integer
        
       findValue(526, 2, p) leads to 20 being stored in the address contained in p
       findValue(5198, 1, p) leads to 100 being stored in the address contianed
                             in p
       findValue(6287, 3, p) leads to 0 being stored inthe address contained in p
	*/
	
	int nResult = 0;
	
	/*TODO: Change the parameters */
	findValue(nGroup, nIdol, &nResult); // The parameters are currently WRONG
	
	/* TODO: Change YOUR_COND_HERE to the correct logical expression */
	if (nResult != 0)
		return 1;
	else
		return 0;
}

int isSuccessfulTrio(int nGroup, int nMem1, int nMem2, int nMem3)
{
	/* DEBUGGING PROBLEM! Fix the condition & The Parameters */
	
   if (inTheGroup(nGroup, nMem1) && inTheGroup(nGroup, nMem2)
       && inTheGroup(nGroup, nMem3))
		return 1;
	else
		return 0;
}

int isSuccessfulGroup(int nGroup)
{
	/* TODO fill your code. You are free
	   to declare as many variables as you wish */
	
	/* Requirements: This function should call isSuccessfulTrio() that you debugged
                     in the previous number */
    if (isSuccessfulTrio(nGroup, 1, 2, 3) && isSuccessfulTrio(nGroup, 4, 5, 6)
       && isSuccessfulTrio(nGroup, 7, 8, 9))
		return 1;
	else
		return 0;
}

int main() {
	printf("%d", extractDigit(9, 1));
	return 0;
}
