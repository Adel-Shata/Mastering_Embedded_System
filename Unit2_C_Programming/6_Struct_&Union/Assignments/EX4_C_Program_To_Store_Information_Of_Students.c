/*
 ============================================================================
 Name        : EX4_C_Program_To_Store_Information_Of_Students.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EX4 C Program To Store Information Of Students Using Structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SStudentInfos
{
	char name[50];
	int rollNumber;
	float marks;
};

//Function take the students informations
void takeStudentInfo(struct SStudentInfos student[], int length);
//Function to print students' informations
void printStudentInfo(struct SStudentInfos student[], int length);

int main(void) {

	struct SStudentInfos students[2];
	//Calculate the length of the array
	int length = sizeof(students)/sizeof(students[0]);

	takeStudentInfo(students, length);
	printStudentInfo(students, length);
	return 0;
}

void takeStudentInfo(struct SStudentInfos student[], int length)
{
	int counter;
	printf("Enter information of students\n");
	for(counter = 0 ; counter < length ; counter++)
	{
		printf("For roll number: ");
		fflush(stdout);
		scanf("%d", &student[counter].rollNumber);
		fflush(stdout);fflush(stdin);
		printf("Enter name: ");
		fflush(stdout);
		gets(student[counter].name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f", &student[counter].marks);
	}
}

void printStudentInfo(struct SStudentInfos student[], int length)
{
	int counter;

	// Displaying students' informations
	printf("Display information of the students\n");
	for(counter = 0 ; counter < length ; counter++)
	{
		printf("Information for roll number %d\nName: %s\nMarks: %0.2f\n", student[counter].rollNumber, student[counter].name, student[counter].marks);
	}

}

