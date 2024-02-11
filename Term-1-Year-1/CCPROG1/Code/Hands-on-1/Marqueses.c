/********************************
RENAME THIS FILE INTO <YOUR LASTNAME.c>
ex: Yazawa.c

MARQUESES, Lorenz Bernard
ID 12307637
S13B

Using arrays and loops will result in 0 points
credited for that function
********************************/

#include "NicoNicoNii.c" // DO NOT MODIFY


/*
   powOf10 - Function used to compute for the value
   			of 10 raised to an integer value n
   @param: n - signifies the power of 10 to compute for.
   @param: res - Refers to a memory address that will contain the value obtained
   				from computing for 10 raised to n
   
   ex: 
    p = address of an integer
    
   		powOf10(5,p) results to 100000 being stored in the address contained in p
   	    powOf10(1,p) results to 10 being stored in the address contained in p
   	    powOf10(0,p) results to 1 being stored in the address contained in p
   	   
   	Assume: n >= 0 and n <= 9
*/
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


/*
   extractDigit - Returns the mth digit from nNum starting from
   				  the rightmost digit. Returns 0 if it's not
   				  possible to obtain the m'th digit
   				  
   @param: nNum - Integer value to obtain the mth digit from
   @param: m - Integer representing the digit no. to extract
   
   ex:
   extractDigit(534, 1) returns 4
        - 4 is the 1st digit starting from the right.
   extractDigit(6498, 4)  returns 6
        - 6 is the 4th digit starting from the right.
   extractDigit(25, 6) returns 0
        - 25 does not have a 6th digit starting from the right.
   
   Assume: m >= 1 and m <= 9. 
*/
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

/*
   inTheGroup - Returns 1 if a corresponding idol is currently in the lineup. 
                Returns 0 otherwise
   				  
   @param: nGroup - Integer value representing the idol group's current lineup
   @param: nIdol - Integer representing the idol member.
   
   ex:
   inTheGroup(534, 1) returns 0
        - 1 is not in 534
   inTheGroup(6239, 2) returns 1
        - 2 is in 6239
   
   Assume: nIdol >= 1 and nIdol <= 9. 
*/

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

/*
	isSuccessfulTrio - Function used to check if 3 members (represented as 
                       integers) are present in a group's performance (represented
                       as an integer with at most 9 digits)
					
	@param: nGroup - Integer representation of the group currently performing
	@param: nMem1 - Integer equivalent of the 1st member
	@param: nMem2 - Integer equivalent of the 2nd member
	@param: nMem3 - Integer equivalent of the 3rd member
	
	See specifications regarding integer equivalent of members
	
*/
int isSuccessfulTrio(int nGroup, int nMem1, int nMem2, int nMem3)
{
	/* DEBUGGING PROBLEM! Fix the condition & The Parameters */
	
   if (inTheGroup(nGroup, nMem1) && inTheGroup(nGroup, nMem2) && inTheGroup(nGroup, nMem3))
		return 1;
	else
		return 0;
}

/*
	isSuccessfulGroup - Function used to check if all 9 members are currently 
                        performing as presented in the integer representation
                        of the Idol group
					
	@param: nGroup - Integer representation of the idol group currently 
                     performing
	
	See specifications regarding integer equivalent of members
	
*/
int isSuccessfulGroup(int nGroup)
{
	/* TODO fill your code. You are free
	   to declare as many variables as you wish */
	
	/* Requirements: This function should call isSuccessfulTrio() that you debugged
                     in the previous number */
    if (isSuccessfulTrio(nGroup, 1, 2, 3) && isSuccessfulTrio(nGroup, 4, 5, 6) && isSuccessfulTrio(nGroup, 7, 8, 9))
		return 1;
	else
		return 0;
}
