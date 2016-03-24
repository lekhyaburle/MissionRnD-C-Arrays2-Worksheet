/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i =1, j = 1,l=0,c=0;
	struct transaction * common = (struct transaction *)malloc(sizeof(struct transaction *));
	if (A==NULL||B==NULL)	
	return NULL;
	for (i = 1; i <= ALen;i++)
	{
			if (A[i].date==B[i].date)
			{
				common[j]=A[i];
				j++;
			}	
	}
	if (j==1)
		return NULL;
	else 
		return common;
}