/*
 ============================================================================
 Name        : EX2_C_Program_To_Find_The_Length_Of_A_String.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Find The Length Of A String, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char string[100];
	int counter= 0;

	printf("Enter a string: "); /* Asking the user to enter a string */
	fflush(stdout);
	gets(string);

	/* Calculating the length of a string*/
	while(0 != string[counter++]);

	printf("Length of the string = %d", --counter);
	return EXIT_SUCCESS;
}
