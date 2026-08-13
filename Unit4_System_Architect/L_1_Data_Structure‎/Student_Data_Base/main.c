/*
 * main.c
 *
 *  Created on: 13 Aug 2026
 *      Author: Adel Shata
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student_Data_Base.h"

student_t *gStudentDataBase = NULL;

int main()
{
    char tempText[40];

    while(1)
    {
    	print("\n===================");
    	print("\n\t Choose one of the following Options \n");
    	print("\n 1: AddStudent  ");
    	print("\n 2: Delete_Student  ");
    	print("\n 3: View_students  ");
    	print("\n 4: DeleteAll  ");
    	print("\n Enter Option Number: ");

        fgets(tempText, sizeof(tempText), stdin);
        tempText[strlen(tempText) - 1] = '\0';

        print("\n===================");
        switch(atoi(tempText))
        {
            case 1:
            	studentAdd( &gStudentDataBase );
                break;

            case 2:
            	studentDelete( &gStudentDataBase );
                break;

            case 3:
            	studentsDisplay( gStudentDataBase );
                break;

            case 4:
            	studentDeleteAll( &gStudentDataBase );
                break;

            default:
            	print("\n wrong option ");
                break;
        }
    }
    return 0 ;
}
