/*
 ============================================================================
 Name        : EX4_C_Program_To_Calculate_The_Power_Of_A_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Calculate The Power Of A Number Using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float power(float baseNum, int powerNum); /*Function to calculate The Power Of A Number Using Recursion*/

int main(void) {
	float baseNum, result = 0;
	int powerNum;

	printf("Enter the base number: "); /* Asking the user to enter the base number */
	fflush(stdout);
	scanf("%f", &baseNum);

	printf("Enter the power number(positive integer): "); /* Asking the user to enter the power number */
	fflush(stdout);
	scanf("%d", &powerNum);

	result = power(baseNum, powerNum);

	printf("%0.2f^%d = %0.2f", baseNum, powerNum, result);
	return 0;
}

float power(float baseNum, int powerNum)
{
	float result = 1;
	if(powerNum > 0)
		result = baseNum * power(baseNum, powerNum-1);
	else if (powerNum < 0)
	{
		printf("Invalid power number");
	}
	else
	{/*NOTHING*/}

	return result;
}
