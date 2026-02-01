/*
 ============================================================================
 Name        : EX2_C_Program_To_Calculate_Average.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Calculate Average Using An Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, counter;
	float data[30] , sum = 0;
	printf("Enter the numbers or data: "); /* Asking the user about the numbers of data*/
	fflush(stdout);
	scanf(" %d", &n);
	/* Taking matrix1 from the user*/
	for( counter = 0 ; counter < n ; counter++)
	{
		printf("Enter Number %d: " , (counter + 1));
		fflush(stdout);
		scanf(" %f", &(data[counter]));
		sum += data[counter]; /* Calculating the sum of data elements*/
	}
	printf("Average = %0.2f",(sum / n)); /* Prints the Average of the data elements*/
	return EXIT_SUCCESS;
}
