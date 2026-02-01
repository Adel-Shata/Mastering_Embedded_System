/*
 ============================================================================
 Name        : EX4_C_Program_To_Insert_An_Element_In_Array.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Insert An Element In Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, counter, num, location;
	int data[30];

	printf("Enter the numbers or Elements: "); /* Asking the user about the Element of the array*/
	fflush(stdout);
	scanf(" %d", &n);

	/* Taking array from the user*/
	for( counter = 0 ; counter < n ; counter++)
	{
		scanf(" %d", &(data[counter]));
	}

	printf("Enter the number to be inserted: "); /* Asking the user about the number to be inserted*/
	fflush(stdout);
	scanf(" %d", &num);

	printf("Enter the location from 1 to %d: ", n); /* Asking the user about the number to be inserted*/
	fflush(stdout);
	scanf(" %d", &location);

	/*shifting the elements of the array to empty a place for the new element without loss in data */
	for(counter = n ; counter >= location ; counter--)
		data[counter] = data[counter-1];

	n++;/* increasing the number of array elements by 1 after adding it*/

	data[location] = num ; /*adding the number in the emptied place we make*/

	/*printing the new array*/
	for( counter = 0 ; counter < n ; counter++)
	{
		printf("%d\n", (data[counter]));
	}



	return EXIT_SUCCESS;
}
