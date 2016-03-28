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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 1, j = 1,k=0;	
	if (A==NULL||B==NULL)
	return NULL;
	for (i = 1; i <= ALen; i++)
	{
		for (j = 1; j < BLen; j++)
		{
			if ((A[i].date) > (B[j].date))
			{

				ALen++;
				k = ALen;
				do
				{
					A[k] = A[k - 1];
					k--;
				} while (k != i);
				A[i] = B[j];
				i++;
				break;
			}
		}
	}
	return A;
}