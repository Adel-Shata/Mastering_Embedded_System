/*
 ============================================================================
 Name        : EX2_C_Program_To_Calculate_Factorial_Of_A_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Calculate Factorial Of A Number Using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int num);

int main(void) {
	int num, result;

	printf("Enter a positive integer: "); /* Asking the user to enter a number to find its factorial*/
	fflush(stdout);
	scanf("%d", &num);

	result = factorial(num);
	printf(" Factorial of %d = %d", num, result);


	return 0;
}

int factorial(int num) /* Calculating the factorial of a number using the function of factorial */
{
	int result = 1;
	if (num > 0)
		result = num * factorial(num-1);
	else if (num < 0)
	{
		printf("Invalid number");
		result = 0;
	}
	else
	{/*NOTHING*/}

	return result;
}
