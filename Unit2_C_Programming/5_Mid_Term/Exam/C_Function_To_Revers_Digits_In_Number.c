/*
 ============================================================================
 Name        : C_Function_To_Reverse_Digits_In_Number.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Reverse Digits In Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reversDigits(char num[]);

int main(void) {
	char numAsChar[20];
	int num;
	printf("Enter A Number: ");
	fflush(stdout);
	gets(numAsChar);

	num = reversDigits(numAsChar);

	printf("Reversed number = %d", num);
	return 0;
}

int reversDigits(char num[])
{
	strrev(num);
	return atoi(num);
}
