/*
 ============================================================================
 Name        : EX3_C_Program_To_Reverse_A_Sentence.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Reverse A Sentence Using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseString(char string[], int counter);

int main(void) {
	char string[100];

	printf("Enter a sentence: "); /* Asking the user to enter a string*/
	fflush(stdout);
	gets(string);
	reverseString(string,0); /* Reverses the string */

	printf("Reversed string: %s", &string);

	return 0;
}

void reverseString(char string[], int counter) /* Function to reversing the string with the help of temporary character */
{
	int length = strlen(string);/* Getting the length of the string */
	char tempChar;
	if (counter <= (float)((length/2)-1))
	{
		/* Reversing the string with the help of temporary character */
		tempChar = string[counter];
		string[counter] = string[length - counter - 1];
		string[length - counter - 1] = tempChar;
		reverseString(string, ++counter);
	}
	else
	{/*NOTHING*/}

}
