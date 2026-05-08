/*
 ============================================================================
 Name        : EX3_C_Program_To_Print_A_String_In_Reverse_Using_A_Pointer.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Print A String In Reverse Using A Pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char string[50] = {0};
	void *ptr = NULL;
	int i;

	ptr = string;

	/*Taking the string using generic ptr by casting it to char*/
	printf("Enter a string: ");
	fflush(stdout);
	gets((char *)ptr);

	/*Printing the reversed string using generic ptr by casting it to char*/
	printf("Reverse of the string is: ");
	for(i = (strlen((char *)ptr) - 1); i >= 0; i--)
		printf("%c", *((char *)ptr + i));

	return EXIT_SUCCESS;
}
