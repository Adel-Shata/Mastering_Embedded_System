/*
 ============================================================================
 Name        : EX1_C_Program_To_Show_Example_Of_Multidimensional_Array.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Show Example Of Multidimensional Array (Finding sum of tow matrix of order 2*2), Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float matrix1[2][2] ,matrix2[2][2] ; /* Declaring the two matrix */
	int counter1, counter2;
	printf("Enter the element of 1st matrix:\n"); /* Asking the user to enter the elements of first matrix*/
	/* Taking matrix1 from the user*/
	for( counter1 = 0 ; counter1 < 2 ; counter1++ )
		for( counter2 = 0 ; counter2 < 2 ; counter2++)
		{
			printf("Enter a[%d][%d]: " , (counter1 + 1), (counter2 + 1));
			fflush(stdout);
			scanf(" %f", &(matrix1[counter1][counter2]));
		}
	printf("Enter the element of 2st matrix:\n"); /* Asking the user to enter the elements of Second matrix*/
	/* Taking matrix2 from the user*/
	for( counter1 = 0 ; counter1 < 2 ; counter1++ )
		for( counter2 = 0 ; counter2 < 2 ; counter2++)
		{
			printf("Enter b[%d][%d]: " , (counter1 + 1), (counter2 + 1));
			fflush(stdout);
			scanf(" %f", &(matrix2[counter1][counter2]));
		}
	/* Printing the sum  */
	printf("Sum Of Matrix:\n");
	for( counter1 = 0 ; counter1 < 2 ; counter1++ )
	{
		for( counter2 = 0 ; counter2 < 2 ; counter2++)
		{
			printf("%0.1f\t", (matrix1[counter1][counter2] + matrix2[counter1][counter2]));
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
