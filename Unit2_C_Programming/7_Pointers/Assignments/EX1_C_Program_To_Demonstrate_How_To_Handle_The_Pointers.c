/*
 ============================================================================
 Name        : EX1_C_Program_To_Demonstrate_How_To_Handle_The_Pointers.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EX1 C Program To Demonstrate How To Handle The Pointers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m = 9;
	void *ab = NULL;
	printf("Address of m : 0X%X\nValue of m : %d\n\n", (unsigned int)&m, m);

	ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address that ab point at : 0X%X\nValue of the address that ab point at : %d\n\n"
			,(unsigned int)ab, *(int*)ab);

	m = 34;
	printf("Now the value of m = %d\n", m);
	printf("Address that ab point at : 0X%X\nValue of the address that ab point at : %d\n\n"
			,(unsigned int)ab, *(int*)ab);

	*(int *)ab = 7;
	printf("Now the pointer variable ab is assigned with %d\n", m);
	printf("Address that ab point at : 0X%X\nValue of the address that ab point at : %d\n"
			,(unsigned int)ab, *(int*)ab);
}
