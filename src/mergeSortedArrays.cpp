/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  {30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

*/

#include <iostream>
#include<malloc.h>
#include<string.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0,CLen=ALen+BLen;
	struct transaction * C = (struct transaction *)malloc(sizeof(struct transaction )*(20));
	while (i<ALen||j<BLen)
	{
		if (i == ALen)
		{
			C[k] = B[j]; j++; k++;
		}
		else if (j == BLen)
		{
			C[k] = A[i];
			k++; i++;
		}
		else if ((A[i].amount) < (B[j].amount))
			{                                                                                            
				C[k] = A[i];
				k++; i++;
			}
		else if (B[j].amount<A[i].amount)
			{
				C[k] = B[j];
				k++; j++;
				
			}
			
		else
			{
				C[k] = A[i];
				k++;
				C[k] = B[j];
				k++; i++; j++;
			}		
	}
	return C;
}
