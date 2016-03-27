/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

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

int into_num(char str[]){
	int dd = str[0] * 10 + str[1] - 11 * '0';
	int mm = str[3] * 10 + str[4] - 11 * '0';
	int yy = str[6] * 1000 + str[7] * 100 + str[8] * 10 + str[9] -1111 * '0';
	return dd + mm * 30 + yy * 365;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL && B != NULL)
	{
		int i = 0, j = 0, k = 0;
		struct transaction *result;
		result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
		while (i < ALen&&j < BLen){
			if (into_num(A[i].date) < into_num(B[j].date)){
				result[k] = A[i];
				i++;
				k++;
			}
			else {
				result[k] = B[j];
				j++;
				k++;
			}
		}
		while (i < ALen)
		{
			result[k] = A[i];
			i++;
			k++;
		}
		while (j < BLen)
		{
			result[k] = B[j];
			j++;
			k++;
		}
		return result;
	}
	return NULL;
}