/*
 ============================================================================
 Name        : EX5_C_Program_To_Check_If_A_Character_Is_Alphabet.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Check If A Character Is Alphabet, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alphabet;
	printf("Enter an character: "); /* Asking the user to enter an alphabet */
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &alphabet); /*Taking an alphabet from the user*/

	/*Checking If A Character Is Alphabet*/
	if ( alphabet <= 90 || alphabet >= 65 )
		printf("The Character is an uppercase alphabet");
	else if( alphabet <= 122 || alphabet >= 97 )
		printf("The Character is an lowercase alphabet");
	else
		printf(" The Character is not an alphabet ");

	return 0 ;
}
