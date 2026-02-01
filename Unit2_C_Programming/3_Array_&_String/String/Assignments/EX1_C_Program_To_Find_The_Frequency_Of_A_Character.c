/*
 ============================================================================
 Name        : EX1_C_Program_To_Find_The_Frequency_Of_A_Character.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Find The Frequency Of A Character In An Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char string[100], requiredChar;
	int i, counter;
	counter = i = 0;

	printf("Enter a string: "); /* Asking the user to enter a string */
	fflush(stdout);
	gets(string);

	printf("Enter a Char to find a frequency: ");/* Asking the user to enter the required character */
	fflush(stdout);
	scanf(" %c", &requiredChar);

	/* Calculating the frequency of the char*/
	while(0 != string[i])
	{
		if(requiredChar == string[i++])
			counter ++;
		else
			continue;
	}

	printf("frequency of %c = %d\n", requiredChar, counter);

	return EXIT_SUCCESS;
}
