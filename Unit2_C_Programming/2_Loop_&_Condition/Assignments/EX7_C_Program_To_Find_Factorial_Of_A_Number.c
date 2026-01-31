/*
 ============================================================================
 Name        : EX7_C_Program_To_Find_Factorial_Of_A_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Find Factorial Of A Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int factorialNum, counter, result = 1;
	printf("Enter a number you need its factorial: "); /* Asking the user to enter a number you need its factorial*/
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &factorialNum);

	/*Checking if the number is valid or not*/
	if(factorialNum <= 0)
		printf("Invalid Number");
	else
	{
		for(counter = 1 ; counter <= factorialNum ; counter++)
			result *= counter;
		printf("The factorial of %d = %d", factorialNum, result);
	}
}

