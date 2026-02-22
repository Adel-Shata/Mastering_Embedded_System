/*
 ============================================================================
 Name        : C_Function_To_Return_Unique_Number_In_Array.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Return Unique Number In Array Without Loops, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int findUnique(int arr[], int arrSize);

int main(void) {
	int result1, result2;
	int test1[7] = {4,2,5,2,5,7,4};
	int test2[3] = {4,2,4};
	result1 = findUnique(test1, 7);
	result2 = findUnique(test2, 3);

	printf("The unique of case1 = %d\nThe unique of case2 = %d", result1, result2);
	return 0;
}

int findUnique(int arr[], int arrSize)
{
	int result = 0;

	if (arrSize == 0)
		return 0;

	result = findUnique(arr, arrSize-1) ^ arr[arrSize-1];

	return result;
}
