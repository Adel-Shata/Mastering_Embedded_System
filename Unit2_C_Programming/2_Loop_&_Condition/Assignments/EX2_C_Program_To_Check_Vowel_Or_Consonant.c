/*
 ============================================================================
 Name        : EX2_C_Program_To_Check_Vowel_Or_Consonant.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Check Vowel Or Consonant, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alphabet;
	printf("Enter an alphabet: "); /* Asking the user to enter an alphabet */
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &alphabet); /*Taking an alphabet from the user*/
	switch(alphabet)
	{
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'U':
	case 'u':
	case 'O':
	case 'o':
	case 'I':
	case 'i':
		printf("%c is a vowel", alphabet); /*Prints if the alphabet is vowel*/
		break;
	default:
		printf("%c is consonant", alphabet); /*Prints if the alphabet is consonant*/
		break;
	}
	return 0;
}
