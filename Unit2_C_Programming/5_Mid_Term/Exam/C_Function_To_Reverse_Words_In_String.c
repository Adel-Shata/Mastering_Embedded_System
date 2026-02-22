/*
 ============================================================================
 Name        : C_Function_To_Reverse_Words_In_String.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Function To Reverse Words In String, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapNames(char name[]);

int main(void) {
	char name[] = "Adel Hassan";
	printf("Name before = %s\n", name);
	swapNames(name);
	printf("Name after = %s\n", name);
	return 0;
}

void swapNames(char name[])
{
	int counter, spacePos = 0, len = strlen(name);
	char tempName[20] = {0};
	for(counter = 0 ; name[counter] != ' ' ; counter++)
	{
		tempName[counter] = name[counter];
		spacePos++;
	}
	strcpy(name, name+spacePos+1);
	name[len-spacePos-1] = ' ';
	strcpy(name+len-spacePos, tempName);
}
