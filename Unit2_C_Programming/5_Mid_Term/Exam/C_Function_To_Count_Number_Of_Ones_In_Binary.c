/*
 ============================================================================
 Name        : C_Function_To_Count_Number_Of_Ones_In_Binary.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Count Number Of Ones In Binary, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void calculateBinaryOnes(int num);

int main(void) {

	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &num);

	calculateBinaryOnes(num);

	return 0;
}

void calculateBinaryOnes(int num)
{
	int ones = 0, i = 0, counter, temp = num;
	char binary[20];
	while ( num > 0 )
	{
		binary[i] = num % 2;
		if(1 == binary[i])
			ones ++;
		i++;
		num /= 2;
	}

	printf("The binary of %d = ",temp);

	for(counter = (i-1); counter >= 0 ; counter--)
		printf("%d",binary[counter]);

	printf(", So has %d One's", ones);
}
