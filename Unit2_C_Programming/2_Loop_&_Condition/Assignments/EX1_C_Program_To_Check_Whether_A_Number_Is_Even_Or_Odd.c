/*
 ============================================================================
 Name        : EX1_C_Program_To_Check_Whether_A_Number_Is_Even_Or_Odd.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Check Whether A Number Is Even Or Odd, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	printf("Enter the Number: "); /* Asking the user to enter the number */
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);
	if(num % 2 == 0) /* Checking id the number is even*/
		printf("%d is even", num);
	else
		printf("%d is odd", num);
	return 0;
}
