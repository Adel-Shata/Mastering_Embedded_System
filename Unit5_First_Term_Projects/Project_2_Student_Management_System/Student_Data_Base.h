/*
 * Student_Data_Base.h
 *
 *  Created on: 21 Aug 2026
 *      Author: Adel Shata
 */

#ifndef STUDENT_DATA_BASE_H_
#define STUDENT_DATA_BASE_H_

/*Section: Include*/
#include "Libraries.h"

/*Section: Macros*/
#define Max_Student_Num 50
#define MAX_COURSES_PER_STUDENT 10
#define FORWARD   1
#define BACKWARD -1


/*Section: Macro Functions*/

/*Section: User Defined Data types*/

typedef enum{
	MATH1 = 1,
	MATH2,
	MATH3,
	MATH4,
	MATH5,
	OPERATING_SYSTEMS,
	CONTROL1,
	CONTROL2,
	CONTROL3,
	ELECTRONICS1,
	ELECTRONICS2,
	CIRCUIT1,
	CIRCUIT2,
	CIRCUIT3,
	DEUTSCH,
	ENGLISH
}course_id_t;

typedef struct{
	char 		  fName[50];
	char  		  lName[50];
	course_id_t   cId[MAX_COURSES_PER_STUDENT];
	float 		  gpa;
	int   		  courseCount;
	int   		  roll;
}student_infos_t;

typedef struct{
	unsigned int    count;
	student_infos_t *top;
	student_infos_t *tail;
	student_infos_t *base;
}student_queue_t;

// Tells the state of the database
typedef enum{
	EMPTY,
	FULL,
	NEITHER_FULL_NOR_EMPTY
}storage_status_t;

// Tells the state of the roll whether valid or not
typedef enum{
	ROLL_VALID,
	ROLL_REGISTERED
}roll_status_t;

// Tells if the function succeeded or failed
typedef enum{
	E_SUCCESS,
	E_FAILED
}func_status_t;

typedef enum{
	COURSE_VALID,
	COURSE_INVALID,
	COURSE_REGISTERED
}course_status_t;

/*Section: Function Declarations*/

/**
 * @brief 
 * 	This function is used to find the number of students in the database.
 * @return void
 */
void studentFindNum();


/**
 * @brief 
 *  This function is used to add students from a file.
 * 	It reads student information from a specified file and adds them to the student database.
 * @return func_status_t 
 */
func_status_t studentAddFromFile();

/**
 * @brief 
 *  This function is used to add a student manually.
 * @return func_status_t
 */
func_status_t studentAddManually();

/**
 * @brief 
 *  This function is used to find a student by their roll number.
 * @return func_status_t
 */
func_status_t studentFindByRoll();

/**
 * @brief 
 *  This function is used to find a student by their first name.
 * @return func_status_t
 */
func_status_t studentFindByFName();

/**
 * @brief 
 *  This function is used to find students registered in a specific course.
 * @return func_status_t
 */
func_status_t studentFindCourses();

/**
 * @brief 
 *  This function is used to delete a student from the database.
 * @return func_status_t
 */
func_status_t studentDelete();

/**
 * @brief 
 *  This function is used to update a student's information.
 * @return func_status_t
 */
func_status_t studentUpdate();

#endif /* STUDENT_DATA_BASE_H_ */
