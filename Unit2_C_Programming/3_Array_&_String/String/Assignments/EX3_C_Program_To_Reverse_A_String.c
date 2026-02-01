/*
 ============================================================================
 Name        : EX3_C_Program_To_Reverse_A_String.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Reverse A String Without Using The Library Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char string[100], tempChar;
	int counter, length;

	printf("Enter a string: "); /* Asking the user to enter a string */
	fflush(stdout);
	gets(string);

	length = strlen(string);/* Getting the length of the string */


	/* Reversing the string with the help of temporary character */
	for(counter = 0 ; counter <= (float)((length/2)-1) ; counter ++)
	{
		tempChar = string[counter];
		string[counter] = string[length - counter - 1];
		string[length - counter - 1] = tempChar;
	}

	printf("Reversed string: %s", &string);

	return EXIT_SUCCESS;
}
