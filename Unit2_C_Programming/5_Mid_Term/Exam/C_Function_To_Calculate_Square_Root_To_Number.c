/*
 ============================================================================
 Name        : C_Function_To_Calculate_Square_Root_To_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Calculate Square Root To Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float squareRoot(int num);

int main(void) {
	int num;
	printf("Enter a number to find its square root: ");
	fflush(stdout);
	scanf(" %d", &num);
	printf("Result = %f", squareRoot(num));
	return 0;
}

float squareRoot(int num)
{
	return pow(num, 0.5);
}
