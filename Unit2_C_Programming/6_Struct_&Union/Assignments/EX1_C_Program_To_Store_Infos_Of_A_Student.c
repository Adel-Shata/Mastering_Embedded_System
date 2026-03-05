/*
 ============================================================================
 Name        : EX1_C_Program_To_Store_Infos_Of_A_Student.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : C Program To Store Information Of A Student Using Struct, Ansi-style
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

/*Function to enter students' information using a pointer of the struct*/
void takeInfos(struct SStudentInfos *student);

/*Function to print students' information*/
void printInfos(struct SStudentInfos student);

int main(void) {
	struct SStudentInfos st1;
	takeInfos(&st1);
	printInfos(st1);
	return 0;
}


void takeInfos(struct SStudentInfos *student)
{
	printf("Enter information of student: ");
	printf("Enter student's name: ");
	fflush(stdout);
	gets(student->name);
	printf("Enter student's roll number: ");
	fflush(stdout);
	scanf("%d", &student->rollNumber);
	printf("Enter student's marks: ");
	fflush(stdout);
	scanf("%f", &student->marks);
}
void printInfos(struct SStudentInfos student)
{
	printf("Display information of student: ");
	printf("Name: %s\nRoll Number: %d\nMarks: %0.3f\n", student.name, student.rollNumber, student.marks);
}
