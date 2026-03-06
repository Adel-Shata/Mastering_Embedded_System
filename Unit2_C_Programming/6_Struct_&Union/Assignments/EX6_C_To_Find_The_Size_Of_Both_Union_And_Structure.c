/*
 ============================================================================
 Name        : EX6_C_To_Find_The_Size_Of_Both_Union_And_Structure.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EX6 C To Find The Size Of Both Union And Structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

union UJob
{
	char name [32] ;
	float salary;
	int worker_no;

} U_union;

struct SJob
{
	char name [32];
	float salary;
	int worker_no;

} S_structure;


int main ()
{
	printf ("Size of the union is: %d", sizeof (U_union));
	printf ("\nSize of the structure is: %d", sizeof (S_structure));

	return 0;
}
