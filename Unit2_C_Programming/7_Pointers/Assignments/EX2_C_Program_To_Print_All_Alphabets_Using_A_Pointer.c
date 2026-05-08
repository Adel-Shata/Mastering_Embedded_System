/*
 ============================================================================
 Name        : EX2_C_Program_To_Print_All_Alphabets_Using_A_Pointer.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Print All Alphabets Using A Pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alphabets[26] = {0};
	void *ptr = NULL;
	ptr = alphabets;
	int i;

	/*Assigning the alphabets in alphabets[26] using generic ptr by casting it to char*/
	for(i = 0; i < 26; i++)
		*(char *)(ptr + i) = i + 'A';

	/*Printing the alphabets in alphabets[26] using generic ptr by casting it to char*/
	printf("The Alphabets are:\n");
	for(i = 0; i < 26; i++)
		printf("%c", *(char *)(ptr + i));

	return EXIT_SUCCESS;
}
