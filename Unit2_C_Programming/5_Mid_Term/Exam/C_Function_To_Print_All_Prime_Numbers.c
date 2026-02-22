/*
 ============================================================================
 Name        : C_Function_To_Print_All_Prime_Numbers.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Print All Prime Numbers Between Two Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printPrime(int min, int max);

int main(void) {
	int n1, n2;

	printf("Enter Number1: ");
	fflush(stdout);
	scanf("%d", &n1);

	printf("Enter Number2: ");
	fflush(stdout);
	scanf("%d", &n2);

	printPrime(n1, n2);

	return 0;
}

void printPrime(int min, int max)
{
	int primeCounter = 0, counter = 0;
	short primeFlag = 1;

	if(min > max)
	{
		min ^= max;
		max ^= min;
		min ^= max;
	}
	else{/*Nothing*/}
	for(; min < max ; min++)
	{
		if( 0 < min)
		{
			for(counter = 2; counter <= ((float)min/2.0) ; counter++)
			{
				if(0 == min % counter)
				{
					primeFlag = 0;
					break;
				}
				else
					primeFlag = 1;
			}
			if (1 == primeFlag)
			{
				printf("%d\t", min);
				primeCounter++;
			}
		}
		else{continue;}

	}
	if(0 == primeCounter)
		printf("NO primes between the two entered numbers");

}
