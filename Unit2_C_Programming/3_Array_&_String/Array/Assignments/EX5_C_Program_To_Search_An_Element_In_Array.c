/*
 ============================================================================
 Name        : EX5_C_Program_To_Search_An_Element_In_Array.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C_Program_To_Search_An_Element
 In Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, counter, num, flag=0;
	int data[30];

	printf("Enter the numbers or Elements: "); /* Asking the user about the Element of the array*/
	fflush(stdout);
	scanf(" %d", &n);

	/* Taking Array from the user*/
	for( counter = 0 ; counter < n ; counter++)
	{
		scanf(" %d", &(data[counter]));
	}

	printf("Enter the element to be searched: "); /* Asking the user about the element to be searched*/
	fflush(stdout);
	scanf(" %d", &num);

	/* searching the element using for loop and conditions*/
	for( counter = 0 ; counter < n ; counter++)
	{
		if(num == data[counter])
		{
			if(flag == 0)
			{
				printf("Number found at a location = %d\n", (counter + 1));
				flag++;
			}
			else
				printf("Number found again at a location = %d\n", (counter + 1));
		}
		else if((counter == (n - 1)) && (flag == 0))
			printf("We could not find the element\n");
		else
			continue;
	}
	return EXIT_SUCCESS;
}
