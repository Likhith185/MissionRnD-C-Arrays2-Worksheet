/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

int date_validation(int a, int b, int c)
{
	if (b == 0 || b > 12)
		return 0;

	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (b == 2 && isLeap(c))
		arr[1]++;
	if (a <= arr[b - 1])
		return 1;
	return 0;
}


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, dd1, dd2, mm1, mm2, yy1, yy2, check1, check2, count = 0;
	dd2 = date[0]  * 10 + date[1] - 11 * '0';
	mm2 = date[3]  * 10 + date[4] - 11 *'0';
	yy2 = date[6]  * 1000 + date[7]  * 100 + date[8]  * 10 + date[9] - 1111 * '0';
	for (i = 0; i < len; i++)
	{
		dd1 = Arr[i].date[0]  * 10 + Arr[i].date[1] - 11 * '0';
		mm1 = Arr[i].date[3]  * 10 + Arr[i].date[4] - 11 * '0';
		yy1 = Arr[i].date[6]  * 1000 + Arr[i].date[7]  * 100 + Arr[i].date[8]  * 10 + Arr[i].date[9] - 1111 * '0';
		check1 = date_validation(dd1, mm1, yy1);
		check2 = date_validation(dd2, mm2, yy2);
		if (check1 != -1 && check2 != -1)
		{
			if (yy1 > yy2 || yy1 == yy2&&mm1 > mm2 || yy1 == yy2&&mm1 == mm2&&dd1 > dd2)
			{
				count++;
			}

		}
		else
			return NULL;


	}
	return count;
}