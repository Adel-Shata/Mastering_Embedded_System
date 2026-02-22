/*
 ============================================================================
 Name        : C_Function_To_Sum_Numbers_From_1_To_100.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Sum Numbers From 1 To 100 Without Loops, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumNumbers(int min, int max);

int main(void) {
	printf("The result of the sum = %d ", sumNumbers(1, 100));
	return 0;
}

int sumNumbers(int min, int max)
{
	int result = 0;
	if (max == min)
		return min;
	else if (min > max)
	{
		max ^= min;
		min ^= max;
		max ^= min;
	}
	result = sumNumbers(min, max-1) + max;
	return result;

}
