/*
 ============================================================================
 Name        : EX4_C_Program_To_Check_Whether_A_Number_Is_Positive_Negative.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Check Whether A Number Is Positive Negative, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num;
	printf("Enter the number: "); /* Asking the user to enter a number */
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &num); /*Taking the number from the user*/

	/*Checking the number*/
	if(num > 0)
		printf("The number is positive");
	else if( num == 0)
		printf("The number = 0");
	else
		printf("The number is negative");
	return 0;
}
