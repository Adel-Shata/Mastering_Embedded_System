/*
 ============================================================================
 Name        : C_Function_To_Take_A_Number_And_Sum_All_Digits.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Take A Number And Sum All Digits, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumDigits(int num);

int main(void) {
	int num, result;
	printf("Enter a number to find the sum of its digits: ");
	fflush(stdout);
	scanf(" %d", &num);
	result = sumDigits(num);
	printf("Result = %d", result);
	return 0;
}

int sumDigits(int num)
{
	short digit;
	int result = 0;
	while(0 != num)
	{
		digit = num % 10;
		num /= 10;
		result += digit;
	}
	return result;
}
