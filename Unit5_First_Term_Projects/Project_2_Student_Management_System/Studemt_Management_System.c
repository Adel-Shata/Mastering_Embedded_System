/*
 ============================================================================
 Name        : Studemt_Management_System.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Student_Data_Base.h"

int main(void)
{
	int choice;

	while(1)
	{
		print("\n========================================\n"
				"        STUDENT DATA BASE SYSTEM\n"
				"========================================\n"
				"1. Add student manually\n"
				"2. Add students from file\n"
				"3. Find number of students\n"
				"4. Find student by roll number\n"
				"5. Find student by first name\n"
				"6. Find students by course\n"
				"7. Delete student\n"
				"8. Update student\n"
				"9. Exit\n"
				"========================================\n"
				"Enter your choice: ")

		scanf(" %i", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				print("\n---------- Add Student Manually ----------\n")
				studentAddManually();
				break;

			case 2:
				print("\n---------- Add Students From File ----------\n")
				studentAddFromFile();
				break;

			case 3:
				print("\n---------- Students Number ----------\n")
				studentFindNum();
				break;

			case 4:
				print("\n---------- Find Student By Roll ----------\n")
				studentFindByRoll();
				break;

			case 5:
				print("\n---------- Find Student By First Name ----------\n")
				studentFindByFName();
				break;

			case 6:
				print("\n---------- Find Students By Course ----------\n")
				studentFindCourses();
				break;

			case 7:
				print("\n---------- Delete Student ----------\n")
				studentDelete();
				break;

			case 8:
				print("\n---------- Update Student ----------\n")
				studentUpdate();
				break;

			case 9:
				print("\nExiting the program...\n")
				return 0;

			default:
				print("\nInvalid choice, please try again.\n")
				break;
		}

		print("\nPress Enter to continue...")
		getchar();
	}

	return 0;
}
