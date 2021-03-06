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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isLeap1(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

int date_validate(int a, int b, int c)
{
	if (b == 0 || b > 12)
		return 0;

	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (b == 2 && isLeap1(c))
		arr[1]++;
	if (a <= arr[b - 1])
		return 1;
	return 0;
}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen <= 0 || A == NULL || BLen <= 0 || B == NULL)
		return NULL;
	else if (A == B)
		return A;
	else{
		int i, j, dd1, dd2, mm1, mm2, yy1, yy2, check1, check2, count = 0;
		struct transaction *result = (struct transaction*)malloc((1)*sizeof(struct transaction));
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				dd1 = A[i].date[0] * 10 + A[i].date[1] - 11 * '0';
				dd2 = B[j].date[0] * 10 + B[j].date[1] - 11 * '0';
				mm1 = A[i].date[3] * 10 + A[i].date[4] - 11 * '0';
				mm2 = B[j].date[3] * 10 + B[j].date[4] - 11 * '0';
				yy1 = A[i].date[6] * 1000 + A[i].date[7]  * 100 + A[i].date[8] * 10 + A[i].date[9] - 1111 * '0';
				yy2 = B[j].date[6] * 1000 + B[j].date[7]  * 100 + B[j].date[8] * 10 + B[j].date[9] - 1111 * '0';
				check1 = date_validate(dd1, mm1, yy1);
				check2 = date_validate(dd2, mm2, yy2);
				if (check1 != -1 && check2 != -1)
				{
					if (yy1 == yy2&&mm1 == mm2&&dd1 == dd2)
					{
						count++;
						result = &A[i];

					}
				}
				else
					return NULL;

			}
		}
		if (count == 0)
			return NULL;
		else
			return result;
	}
}