/*
 * Student_Data_Base.h
 *
 *  Created on: 12 Aug 2026
 *      Author: Adel Shata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student_Data_Base.h"



// Helper functions ↓↓↓

// Checking whether the new student's id is valid or not
LIST_Status_t static studentIsValidId( student_t *student, unsigned int id ){
	LIST_Status_t returnFlag = succeeded;
	if( NULL == student ){
		returnFlag = failed;
	}
	else{
		while( NULL != student ){
			if( id == student->NodeData.id ){
				returnFlag = failed;
				break;
			}
			else{/*NOTHING*/}
			student = student->NodeNext;
		}
	}
	return returnFlag;
}

// Filling the infos of the new student
LIST_Status_t static studentFillRecord( student_t *studentList ,student_t *newStudent ){
	LIST_Status_t returnFlag = succeeded;
	char tempText[40] = {0};
	if( NULL == newStudent || NULL == studentList )
		returnFlag = failed;
	else{
		print( "\n===============\n" )

		print( "\nEnter student's ID: " )
		fgets( tempText, sizeof( tempText ), stdin );
		tempText[strlen(tempText) - 1] = '\0';

		if( failed == studentIsValidId( studentList, atoi( tempText ) ) ){
			print("Invalid ID")
			return failed;
		}
		else{
			( newStudent->NodeData.id ) = atoi( tempText );
		}

		print( "\nEnter student's name: " )
		fgets( newStudent->NodeData.name, sizeof( newStudent->NodeData.name ), stdin );
		newStudent->NodeData.name[strlen(newStudent->NodeData.name) - 1] = '\0';

		print( "\nEnter student's height: " )
		fgets( tempText, sizeof( tempText ), stdin );
		tempText[strlen(tempText) - 1] = '\0';
		( newStudent->NodeData.height ) = atoi( tempText );

		print( "\n\n===============\n" )

	}
	return returnFlag;
}


// Primary functions ↓↓↓

// ِAdding new student in the student's data base
LIST_Status_t studentAdd( student_t **student ){
	student_t *tempStudent   = NULL;
	LIST_Status_t returnFlag = LIST_Insert( student );

	if( succeeded == returnFlag ){
		tempStudent = *student;
		while( NULL != tempStudent->NodeNext )
			tempStudent = tempStudent->NodeNext;

		returnFlag = studentFillRecord( *student ,tempStudent );

		if( failed == returnFlag ){
			returnFlag = LIST_CDelete( student, (LIST_Length(*student) - 1) );
		}
		else{/*NOTHING*/}
	}
	else{/*NOTHING*/}



	return returnFlag;
}

// ِRemoving certain student from the student's data base
void studentDelete( student_t **student){
	LIST_Status_t returnFlag = succeeded;
	student_t *tempStudent   = NULL;
	signed int index       = 0;
	char studentId[40]       = {0};

	if( NULL == *student ){
		print( "\nEMPTY\n" )
	}
	else{
		tempStudent = *student;
		print( "\n===============\n" )
		print( "\nEnter student's ID: " )
        fgets(studentId, sizeof(studentId), stdin);
		studentId[strlen(studentId) - 1] = '\0';

		while( NULL != tempStudent && tempStudent->NodeData.id != atoi( studentId ) ){
			tempStudent = tempStudent->NodeNext;
			index++;
		}

		if( NULL == tempStudent ){
			print( "\nID is invalid\n" )
			returnFlag = failed;
		}
		else{
			returnFlag = LIST_CDelete( student, index );
		}

		if(succeeded == returnFlag){
			print( "\nStudent has been deleted properly\n" )
		}
		else{
			print( "\nError has happened\n" )
		}
	}

}

// Displaying all of student's data base
void studentsDisplay( student_t *student ){

	if( NULL == student ){
		print( "\nEMPTY\n" )
	}
	else{
		print( "\n===============\n" )
		while( NULL != student ){
			print( "\nStudent's ID  : %d\n", student->NodeData.id )
			print( "Student's name  : %s\n", student->NodeData.name )
			print( "Student's height: %d\n", student->NodeData.height )

			student = student->NodeNext;
		}
		print( "\n===============\n" )
	}

}

// Removing all of student's data base
void studentDeleteAll( student_t **student ){
	if( failed == LIST_DeleteAll( student ) ){
		print( "\nEMPTY\n" )
	}
	else{/*NOTHING*/}

}

