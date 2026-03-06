/*
 ============================================================================
 Name        : EXP2_C_Program_To_Add_Two_Distances_In_Inch_Feet.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EXP2 C Program To Add Two Distances In (Inch-Feet) System Using Structures, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SDistance
{
	int feet;
	float inch;
};

//Function to take the distances
void takeDistance(struct SDistance distance[], int length);
//Function to print the distances
void printDistance(struct SDistance distance[], int length);

int main(void) {

	struct SDistance distance[2];
	//Calculate the length of the array
	int length = sizeof(distance)/sizeof(distance[0]);

	takeDistance(distance, length);
	printDistance(distance, length);
	return 0;
}

void takeDistance(struct SDistance distance[], int length)
{
	int counter;
	for(counter = 0 ; counter < length ; counter++)
	{
		printf("Information of %dst distance\n",counter+1);
		printf("Enter Feet: ");
		fflush(stdout);
		scanf("%d", &distance[counter].feet);
		printf("Enter Inch: ");
		fflush(stdout);
		scanf("%f", &distance[counter].inch);
	}
}

void printDistance(struct SDistance distance[], int length)
{
	int counter, feet = 0, temp;
	float inch = 0;

	for(counter = 0 ; counter < length ; counter++)
	{
		feet += distance[counter].feet;
		inch += distance[counter].inch;
	}

	// Logic: Convert inches to feet if greater than 12
	inch /= 12;
	temp = inch;
	feet += temp;
	inch = (inch-temp)*12;

	// Displaying the result
	printf("Sum of distances = %d'-%0.2f\"", feet, inch);
}
