/*
 ============================================================================
 Name        : C_Function_To_Calculate_The_Max_Numbers_Of_Ones.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Calculate The Max Numbers Of Ones Between Two Zeros, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcMaxOnes(char num[]);

int main(void) {
	char num[50] = "0101101110111110110", max;
	max = calcMaxOnes(num);
	printf("The Max Numbers Of Ones = %d", max);
	return 0;
}

int calcMaxOnes(char num[])
{
	int temp = 0, max = 0, counter, len = strlen(num);

	for (counter = 0;counter < len;counter++)
	{
		if(num[counter] == '0')
		{
			if(max < temp)
				max = temp;
			temp = 0;
		}
		else
		{
			temp++;
		}
	}
	return max;
}
