/*
 ============================================================================
 Name        : EX5_C_Program_To_Show_A_Pointer_To_An_Array_Which_Contents_Are_Pointer_To_structure.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Show A Pointer To An Array Which Contents Are Pointer To structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SEmployee
{
	char name[50];
	int id;
};

int main(void) {
	int i;

	struct SEmployee employees [3] = {{"Adel", 100},
			{"Hassan", 101},
			{"Mohamed", 102}};

	struct SEmployee *ptrEmployees [3] = {&employees [0],
			&employees [1],
			&employees [2]};

	struct SEmployee *(*ptr)[3] = &ptrEmployees;
	struct SEmployee **ptr1 = ptrEmployees;

	printf("Using struct SEmployee *(*ptr)[3] \n");
	for(i = 0; i < 3; i++)
		printf("Employee n.%d:\nName: %s\nId: %d\n", i+1, (*(*ptr + i))->name, (*(*ptr + i))->id);

	printf("\n=================================\n"
		   "\nUsing struct SEmployee **ptr1\n");
	for(i = 0; i < 3; i++)
		printf("Employee n.%d:\nName: %s\nId: %d\n", i+1, (*(ptr1 + i))->name, (*(ptr1 + i))->id);

	return EXIT_SUCCESS;
}
