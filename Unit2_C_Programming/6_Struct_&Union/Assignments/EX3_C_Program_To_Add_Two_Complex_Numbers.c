/*
 ============================================================================
 Name        : EX3_C_Program_To_Add_Two_Complex_Numbers.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EX3 C Program To Add Two Complex Numbers By Passing A Structure To A Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SComplexNum
{
	float real;
	float complex;
};

//Function to take the complex number
void takeNumber(struct SComplexNum number[], int length);
//Function to print the sum of the numbers
void printSumNumber(struct SComplexNum number[], int length);

int main(void) {

	struct SComplexNum number[2];
	//Calculate the length of the array
	int length = sizeof(number)/sizeof(number[0]);

	takeNumber(number, length);
	printSumNumber(number, length);
	return 0;
}

void takeNumber(struct SComplexNum number[], int length)
{
	int counter;
	for(counter = 0 ; counter < length ; counter++)
	{
		printf("Enter the %dst number\n",counter+1);
		printf("Enter the real part: ");
		fflush(stdout);
		scanf("%f", &number[counter].real);
		printf("Enter the complex part: ");
		fflush(stdout);
		scanf("%f", &number[counter].complex);
	}
}

void printSumNumber(struct SComplexNum number[], int length)
{
	int counter;
	float real = 0, complex = 0;

	for(counter = 0 ; counter < length ; counter++)
	{
		real += number[counter].real;
		complex += number[counter].complex;
	}

	// Displaying the result
	printf("Sum = %0.2f + %0.2fi\"", real, complex);
}

