/*
 ============================================================================
 Name        : EX6_C_Program_To_Calculate_Sum_Of_Natural_Numbers.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Calculate Sum Of Natural Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, sum = 0, counter;
	printf("Enter N: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &n);
	if( n > 0)
	{
		for( counter = 1 ; counter <= n ; counter++)
			sum += counter;
		printf("Sum = %d", sum);
	}
	else
		printf("You have entered an invalid N");

}
