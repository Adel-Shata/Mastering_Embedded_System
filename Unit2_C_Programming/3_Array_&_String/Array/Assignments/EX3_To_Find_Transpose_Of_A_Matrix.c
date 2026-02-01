/*
 ============================================================================
 Name        : EX3_To_Find_Transpose_Of_A_Matrix.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r, c, counter1, counter2;
	int matrix[10][10], tMatrix[10][10]; /* Declaring the two matrix */
	printf("Enter the rows number: "); /* Asking the user about the numbers of rows*/
	fflush(stdout);
	scanf(" %d", &r);
	printf("Enter the column number: "); /* Asking the user about the numbers of columns*/
	fflush(stdout);
	scanf(" %d", &c);
	printf("Enter the element of 1st matrix:\n"); /* Asking the user to enter the elements of matrix*/
	/* Taking matrix from the user*/
	for( counter1 = 0 ; counter1 < r ; counter1++ )
		for( counter2 = 0 ; counter2 < c ; counter2++)
		{
			printf("Enter a[%d][%d]: " , (counter1 + 1), (counter2 + 1));
			fflush(stdout);
			scanf(" %d", &(matrix[counter1][counter2]));
			tMatrix[counter2][counter1] = matrix[counter1][counter2];
		}
	printf("Entered Matrix:\n");
	/*Printing entered matrix*/
	for( counter1 = 0 ; counter1 < r ; counter1++ )
	{
		for( counter2 = 0 ; counter2 < c ; counter2++)
		{
			printf("\t%d" , (matrix[counter1][counter2]));
		}
		printf("\n");
	}
	printf("Entered Matrix:\n");
	/*Printing Transposed matrix*/
	for( counter1 = 0 ; counter1 < c ; counter1++ )
	{
		for( counter2 = 0 ; counter2 < r ; counter2++)
		{
			printf("\t%d" , (tMatrix[counter1][counter2]));
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
