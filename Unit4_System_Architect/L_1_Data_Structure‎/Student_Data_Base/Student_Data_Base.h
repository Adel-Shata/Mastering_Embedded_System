/*
 * Student_Data_Base.h
 *
 *  Created on: 12 Aug 2026
 *      Author: Adel Shata
 */

#ifndef STUDENT_DATA_BASE_H_
#define STUDENT_DATA_BASE_H_

#include "LINKED_LIST.h"
/*\
******** Initialized in LINKED_LIST_cfg.h ********
typedef struct{
	char           name[50];
	unsigned int   id;
	unsigned short hight;
}student_data_t;
*/

typedef struct NODE student_t;

//helping me to use printf() properly in Eclipse
#define print(...) 	printf(__VA_ARGS__);\
					fflush(stdin);\
					fflush(stdout);

// ِAdding new student in the student's data base
LIST_Status_t studentAdd( student_t **student );

// ِRemoving certain student from the student's data base
void studentDelete( student_t **student );

// Displaying all of student's data base
void studentsDisplay( student_t *student );

// Removing all of student's data base
void studentDeleteAll( student_t **student );



#endif /* STUDENT_DATA_BASE_H_ */
