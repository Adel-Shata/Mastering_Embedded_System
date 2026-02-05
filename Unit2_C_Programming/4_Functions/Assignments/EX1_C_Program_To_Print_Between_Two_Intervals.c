/*
 ============================================================================
 Name        : EX1_C_Program_To_Print_Prime_Numbers_Between_Two_Intervals.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Print Prime Numbers Between Two Intervals Using A Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printPrintPrimeNumbers(int min, int max);
int checkPrime(int NumToCh);

int main(void)
{
	int num1, num2;

	printf("Enter two numbers(Intervals): "); /* Asking the user to enter two intervals*/
	fflush(stdout);
	scanf("%d %d", &num1, &num2);

	printPrintPrimeNumbers(10, 30); /* Printing the prime numbers between two intervals using a the function of printPrintPrimeNumbers */
	return 0;
}


void printPrintPrimeNumbers(int min, int max) /* Function to print prime numbers */
{
	int flag;
	if(min > max) /* Swap if the min variable is bigger than the max one */
	{
		min ^= max;
		max ^= min;
		min ^= max;
	}
	else
	{/*NOTHING*/}

	printf("Prime numbers between %d and %d are: ", min, max);

	for( ; min <= max ; min++)
	{
		flag = checkPrime(min);
		if( 0 == flag)
			printf("%d ", min);
		else
		{/*NOTHING*/}
	}
}

int checkPrime(int NumToCh) /* Function to check if the number is prime or not */
{
	int i, flag = 0;
	for(i = 2; i <= NumToCh/2 ; i++)
		if(NumToCh % i == 0)
		{
			flag = 1;
			break;
		}
	return flag;
}
