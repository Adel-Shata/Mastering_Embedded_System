/*
 ============================================================================
 Name        : EX3_C_Program_To_Find_The_Largest_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1, num2, num3, largestNum;
	printf("Enter three numbers: "); /* Asking the user to enter three numbers */
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d %d", &num1, &num2, &num3); /* Taking three numbers for the user */
	largestNum = (num1 > num2)?((num1>num3)?num1:num3):((num2>num3)?num2:num3); /* Assign the largest number into the var */
	printf("Largest Number = %d", largestNum);
	return EXIT_SUCCESS;
}
