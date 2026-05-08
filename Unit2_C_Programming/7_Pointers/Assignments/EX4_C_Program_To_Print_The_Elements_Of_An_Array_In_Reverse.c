/*
 ============================================================================
 Name        : EX4_C_Program_To_Print_The_Elements_Of_An_Array_In_Reverse.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Print The Elements Of An Array In Reverse Order, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num[15] = {0};
	void *ptr = NULL;
	int i, n;

	ptr = num;

	/*Taking the number of elements to store in the array (max 15)*/
	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdout);
	scanf("%d",&n);

	/*Taking the elements using generic ptr by casting it to int*/
	for(i = 0; i < n; i++)
	{
		printf("element n.%d: ", i+1);
		fflush(stdout);
		scanf("%d", ((int *)ptr + i));
	}

	/*Printing the reversed string using generic ptr by casting it to int*/
	printf("\nReverse of the elements is: \n");
	for(n = n - 1; n >= 0; n--)
	{
		printf("element n.%d: %d\n",n+1 , *((int *)ptr + n));
	}

	return EXIT_SUCCESS;
}
