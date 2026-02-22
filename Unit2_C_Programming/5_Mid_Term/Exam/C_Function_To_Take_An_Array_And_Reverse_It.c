/*
 ============================================================================
 Name        : C_Function_To_Take_An_Array_And_Reverse_It.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Take An Array And Reverse Its Elements, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseArr(int arr[], int length);

int main(void) {
	int counter = 0;
	int arr [] = {1,2,3,4,5};

	printf("Normal Array:\n");
	for(counter = 0 ; counter < 5 ; counter++)
		printf("%d\t", arr[counter]);
	printf("\n");

	reverseArr(arr, 5);
	return 0;
}

void reverseArr(int arr[], int length)
{
	int counter;

	for(counter = 0; counter < length/2 ; counter++)
	{
		arr[counter] ^= arr[length-counter-1];
		arr[length-counter-1] ^= arr[counter];
		arr[counter] ^= arr[length-counter-1];
	}
	printf("Reversed Array:\n");
	for(counter = 0 ; counter < length ; counter++)
		printf("%d\t", arr[counter]);
	printf("\n");
}
