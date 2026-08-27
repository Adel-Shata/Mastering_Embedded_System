/*
 * Student_Data_Base.c
 *
 *  Created on: 21 Aug 2026
 *      Author: Adel Shata
 */


#include "Student_Data_Base.h"

student_infos_t studentList[Max_Student_Num] = {0};

student_queue_t student = { 0, studentList, studentList, studentList };

int position = 0;

/*helper functions ↓↓↓*/

// Repositioning the pointer in the queue
static student_infos_t* repositionPointer(student_infos_t* ptr, int moveDir){
	switch(moveDir){
		case FORWARD:
			if(ptr == &studentList[Max_Student_Num - 1]){
				ptr = student.base;
			}
			else{
				(ptr)++;
			}
			break;
		case BACKWARD:
			if(ptr == student.base){
				ptr = &studentList[Max_Student_Num - 1];
			}
			else{
				(ptr)--;
			}
			break;
		default:
			break;
	}
	return ptr;
}

// check whether the list full or empty or even neither full nor empty
storage_status_t static storageStatus(){
	storage_status_t returnFlag = NEITHER_FULL_NOR_EMPTY;
	if(Max_Student_Num == student.count){
		returnFlag = FULL;
	}
	else if(0 == student.count){
		returnFlag = EMPTY;
	}
	return returnFlag;
};

// Checking whether the roll number of the student is valid or not
roll_status_t static rollStatus(int roll, student_infos_t** popedStudent){
	roll_status_t   returnFlag = ROLL_VALID;
	student_infos_t *tempTail = student.tail;
	for(position = 0; position < student.count; position++){
		if(roll == tempTail->roll){
			*popedStudent = tempTail;
			returnFlag = ROLL_REGISTERED;
			break;
		}
		else{
			tempTail = repositionPointer(tempTail, FORWARD);
		}

	}
	return returnFlag;
}

// Checking whether course id has been registered before or not
couse_status_t static courseStatus(course_id_t courseId, student_infos_t* tempStudent){
	couse_status_t returnFlag = COURSE_VALID;
	int counter;
	if((courseId > ENGLISH) || (courseId < MATH1)){
		returnFlag = COURSE_INVALID;
	}
	else{
		for(counter = 0; counter < tempStudent->courseCount; counter++){
			if(courseId == tempStudent->cId[counter]){
				returnFlag = COURSE_REGISTERED;
				break;
			}
			else{/*NOTHING*/}
		}
	}
	return returnFlag;
}

// Adding the first/last Names or any string
static void studentGetString(char *name, int nameLength){
	fgets(name, nameLength, stdin);
	name[strcspn(name, "\n")] = '\0';
}

// Adding student's GPA
static void studentAddGpa(student_infos_t* tempStudent){

	do{
		print("Enter student's GPA: ")
	    scanf(" %f", &tempStudent->gpa);
		getchar();
		if((tempStudent->gpa) > 4 || (tempStudent->gpa) < 0){
			print("Invalid GPA, Please insert it from 0 → 4\n")
		}
	}while((tempStudent->gpa) > 4 || (tempStudent->gpa) < 0);
}

// Adding student's courses
static void studentAddCourses(student_infos_t* tempStudent){
	char choice = 'y';
	int courseId;
	couse_status_t courseState = COURSE_VALID;
	while((MAX_COURSES_PER_STUDENT > tempStudent->courseCount) && (('y' == choice) || ('Y' == choice))){
		print("1: MATH1\n"
				"2: MATH2\n"
				"3: MATH3\n"
				"4: MATH4\n"
				"5: MATH5\n"
				"6: OPRERATING_SYSTEMS\n"
				"7: CONTROL1\n"
				"8: CONTROL2\n"
				"9: CONTROL3\n"
				"10: ELECTRONICS1\n"
				"11: ELECTRONICS2\n"
				"12: CIRCUIT1\n"
				"13: CIRCUIT2\n"
				"14: CIRCUIT3\n"
				"15: DEUTSCH\n"
				"16: ENGLISH\n"
				"Enter course's ID: ")
		scanf(" %i", &courseId);
		getchar();
		courseState = courseStatus((course_id_t)courseId, tempStudent);
		if(COURSE_INVALID == courseState){
			print("Invalid course ID, please try again\n")
		}
		else if(COURSE_REGISTERED == courseState){
			print("This course has already been registered \n")
		}
		else{
			tempStudent->cId[(tempStudent->courseCount)++] = (course_id_t)courseId;
			print("The course with ID= %d has been added properly\n", courseId);
			print("Enter Y if you want to add another course, and other char if no: ")
			scanf(" %c", &choice);
			getchar();
		}
	}

	if(MAX_COURSES_PER_STUDENT <= tempStudent->courseCount){
		print("You have reached the max course number, you can't add more\n")
	}
	else{/*NOTHING*/}
}

// Fill student Infos
static void studentFillInfos(int roll, student_infos_t* tempStudent){
	tempStudent->roll = roll;
	print("Enter the first name of the student: ")
	studentGetString(tempStudent->fName, sizeof(tempStudent->fName));
	print("Enter the last name of the student: ")
	studentGetString(tempStudent->lName, sizeof(tempStudent->lName));

	studentAddGpa(tempStudent);
	tempStudent->courseCount = 0;
	studentAddCourses(tempStudent);
	student.count++;
}

// Displaying the course name according to its ID
static void studentDisplayCourses(course_id_t courseId){
	switch(courseId){
		case MATH1:
			print("MATH1\n")
			break;
		case MATH2:
			print("MATH2\n")
			break;
		case MATH3:
			print("MATH3\n")
			break;
		case MATH4:
			print("MATH4\n")
			break;
		case MATH5:
			print("MATH5\n")
			break;
		case OPERATING_SYSTEMS:
			print("OPERATING SYSTEMS\n")
			break;
		case CONTROL1:
			print("CONTROL1\n")
			break;
		case CONTROL2:
			print("CONTROL2\n")
			break;
		case CONTROL3:
			print("CONTROL3\n")
			break;
		case ELECTRONICS1:
			print("ELECTRONICS1\n")
			break;
		case ELECTRONICS2:
			print("ELECTRONICS2\n")
			break;
		case CIRCUIT1:
			print("CIRCUIT1\n")
			break;
		case CIRCUIT2:
			print("CIRCUIT2\n")
			break;
		case CIRCUIT3:
			print("CIRCUIT3\n")
			break;
		case DEUTSCH:
			print("DEUTSCH\n")
			break;
		case ENGLISH:
			print("ENGLISH\n")
			break;
		default:
			print("WRONG ID COURSE")
	}
}

// Displaying student Infos
static void studentDisplayInfos(student_infos_t *student){
	int counter;
	print("Student Roll     : %i\n"
			"Student first Name: %s\n"
			"student Last Name: %s\n",
			student->roll,
			student->fName,
			student->lName)
	print("[Registered Courses]\n")
	for(counter = 0; counter < student->courseCount; counter++ ){
		print("%i. →ID: %i\t→", (counter + 1), student->cId[counter])
		studentDisplayCourses(student->cId[counter]);
	}
}

// primary functions ↓↓↓

// Getting the number of registered students and remaining places
void studentFindNum(){
	printf("Registered student = %i\n"
			"Remaining places   = %i\n", student.count, (Max_Student_Num - student.count));
}


func_status_t studentAddFromFile()
{
	FILE *file;
	func_status_t returnFlag = E_SUCCESS;
	couse_status_t courseState;
	student_infos_t *tempStudent = NULL;
	char line[200];
	char *token;

	file = fopen("students.txt", "r");

	if(NULL == file)
	{
		print("Failed to open the file\n")
		return E_FAILED;
	}

	while(NULL != fgets(line, sizeof(line), file))
	{
		/* Check if database is full */
		if(FULL == storageStatus())
		{
			print("The database is full, no more students can be added\n")
			returnFlag = E_FAILED;
			break;
		}

		/* Roll */
		token = strtok(line, " \n");

		if(NULL == token)
		{
			continue;
		}
		else{
			if(ROLL_VALID == rollStatus(atoi(token), &tempStudent)){
				/* Get pointer to the next available student */
				if(EMPTY == storageStatus())
				{
					tempStudent = student.top;
				}
				else
				{
					student.top = repositionPointer(student.top, FORWARD);
					tempStudent = student.top;
				}

				tempStudent->roll = atoi(token);
			}
			else{
				print("We can not add the written student in the file with roll = %d\n"
						"because the written roll is registered before with another student\n", atoi(token))
				continue;
			}
		}

		/* First name */
		token = strtok(NULL, " \n");

		if(NULL == token)
		{
			print("There is no first name in the file for roll: %d"
					", so you have to enter it manually\n", tempStudent->roll)
			print("Enter the first name of the student: ")
			studentGetString(tempStudent->fName, sizeof(tempStudent->fName));

		}
		else{
			strcpy(tempStudent->fName, token);
		}


		/* Last name */
		token = strtok(NULL, " \n");

		if(NULL == token)
		{
			print("There is no last name in the file for roll: %d"
					", so you have to enter it manually\n", tempStudent->roll)
			print("Enter the first name of the student: ")
			studentGetString(tempStudent->lName, sizeof(tempStudent->lName));
		}
		else{
			strcpy(tempStudent->lName, token);
		}


		/* GPA */
		token = strtok(NULL, " \n");

		if(NULL == token)
		{
			do{
				print("There is no GPA inserted in the file for the student with roll: %d\n"
						"Please insert student's GPA manually: ", tempStudent->roll)
			    scanf(" %f", &tempStudent->gpa);
				getchar();
			}while((tempStudent->gpa) > 4 || (tempStudent->gpa) < 0);
		}
		else{
			if((atof(token)) > 4 || (atof(token)) < 0){
				do{
					print("Invalid GPA\n"
							"Please insert student's GPA manually: ")
				    scanf(" %f", &tempStudent->gpa);
					getchar();
				}while((tempStudent->gpa) > 4 || (tempStudent->gpa) < 0);
			}
			else{
				tempStudent->gpa = atof(token);
			}
		}


		/* Courses */
		tempStudent->courseCount = 0;
		token = strtok(NULL, " \n");
		if(NULL == token){
			print("There are no courses in the file for the student with roll: %d\n"
					"It must be at least one course assigned to the student\n"
					"so you have to enter it manually\n", tempStudent->roll)
			studentAddCourses(tempStudent);
		}
		else{
			do{
				if(tempStudent->courseCount >= MAX_COURSES_PER_STUDENT)
				{
					print("You have reached maximum course number can be registered to the student with roll: %d\n", tempStudent->roll)
					break;
				}
				courseState = courseStatus((course_id_t)atoi(token), tempStudent);
				if(COURSE_INVALID == courseState || COURSE_REGISTERED == courseState ){
					print("The course in the file with id = %d for the student with roll: %d\n"
							"is invalid or already registered before\n", atoi(token), tempStudent->roll)
					continue;
				}

					tempStudent->cId[tempStudent->courseCount++] = (course_id_t)atoi(token);
			}while(NULL != (token = strtok(NULL, " \n")));

			if(0 == tempStudent->courseCount){
				print("There are no valid courses in the file for the student with roll: %d\n"
						"It must be at least one course assigned to the student\n"
						"so you have to enter it manually\n", tempStudent->roll)
				studentAddCourses(tempStudent);
			}
		}

		student.count++;

		print("Student with roll: %i has been added successfully\n",
				tempStudent->roll)
	}

	fclose(file);

	print("\nStudents from file have been processed.\n")
	studentFindNum();

	return returnFlag;
}


func_status_t studentAddManually(){
	func_status_t    returnFlag   = E_SUCCESS;
	roll_status_t 	 rollState    = ROLL_VALID;
	int              tempRoll;
	student_infos_t* tempStudent  = NULL;
	storage_status_t storageState = storageStatus();
	switch(storageState){
		case FULL:
			returnFlag = E_FAILED;
			break;
		case EMPTY:
			print("----------\nAdd student details\n----------\n")
			print("Enter the roll number: ")
			scanf(" %i", &tempRoll);
			getchar();
			rollState = rollStatus(tempRoll, &tempStudent);
			if(ROLL_REGISTERED == rollState){
				returnFlag = E_FAILED;
				print("[This roll is already registered with another student]")
			}
			else{
				studentFillInfos(tempRoll, student.top);
				printf("Student has been added properly.\n");
				studentFindNum();
			}
			break;
		case NEITHER_FULL_NOR_EMPTY:
		default:
			print("----------\nAdd student details\n----------\n")
			print("Enter the roll number: ")
			scanf(" %i", &tempRoll);
			getchar();
			rollState = rollStatus(tempRoll, &tempStudent);

			if(ROLL_REGISTERED == rollState){
				returnFlag = E_FAILED;
				print("[This roll is already registered with another student]")
			}
			else{
				student.top = repositionPointer(student.top, FORWARD);
				studentFillInfos(tempRoll, student.top);
				printf("Student has been added properly.\n");
				studentFindNum();
			}
			break;

	}
	return returnFlag;
}

func_status_t studentFindByRoll(){
	func_status_t    returnFlag   = E_SUCCESS;
	storage_status_t storageState = storageStatus();
	student_infos_t  *tempStudent;
	roll_status_t rollState = ROLL_REGISTERED;
	int roll;

	switch(storageState){
		case EMPTY:
			print("The list is already empty")
			returnFlag   = E_FAILED;
			break;
		case FULL:
		case NEITHER_FULL_NOR_EMPTY:
		default:
			print("Enter the roll number: ")
			scanf(" %i", &roll);
			getchar();
			rollState = rollStatus(roll, &tempStudent);
			print("[Student Infos]\n")
			if(ROLL_REGISTERED == rollState){
				studentDisplayInfos(tempStudent);
			}
			else{
				print("The input roll doesn't match any student stored in the list\n")
				returnFlag = E_FAILED;
			}
	}

	return returnFlag;
}

func_status_t studentFindByFName(){
	func_status_t returnFlag = E_FAILED;
	storage_status_t storageState = storageStatus();
	student_infos_t  *tempStudent;
	char fName[50];
	int studentCount = 0;
	int counter;

	switch(storageState){
		case EMPTY:
			print("The list is already empty")
			break;
		case FULL:
		case NEITHER_FULL_NOR_EMPTY:
		default:
			tempStudent = student.tail;
			print("Enter student's Name: ")
			studentGetString(fName, sizeof(fName));
			print("[Students Infos]\n")
			for(counter = 0; counter < student.count; counter++){
				if(!strcasecmp(tempStudent->fName, fName)){
					studentCount++;
					print("%ist Student:\n", studentCount)
					studentDisplayInfos(tempStudent);
					returnFlag    = E_SUCCESS;

				}
				else{/*NOTHING*/}

				tempStudent = repositionPointer(tempStudent, FORWARD);
			}
	}

	if(E_FAILED == returnFlag){
		print("The input name doesn't match any student stored in the list\n")
	}
	else{/*NOTHING*/}

	return returnFlag;
}

func_status_t studentFindCourses(){
	func_status_t returnFlag = E_FAILED;
	int courseId;
	storage_status_t storageState = storageStatus();
	student_infos_t  *tempStudent;

	int counter1, counter2, studentCount = 0;

	switch(storageState){
		case EMPTY:
			print("The list is already empty")
			break;
		case FULL:
		case NEITHER_FULL_NOR_EMPTY:
		default:
			tempStudent = student.tail;
			do{
				print("1: MATH1\n"
						"2: MATH2\n"
						"3: MATH3\n"
						"4: MATH4\n"
						"5: MATH5\n"
						"6: OPRERATING_SYSTEMS\n"
						"7: CONTROL1\n"
						"8: CONTROL2\n"
						"9: CONTROL3\n"
						"10: ELECTRONICS1\n"
						"11: ELECTRONICS2\n"
						"12: CIRCUIT1\n"
						"13: CIRCUIT2\n"
						"14: CIRCUIT3\n"
						"15: DEUTSCH\n"
						"16: ENGLISH\n")
				print("Enter the course ID needed to find the students registered in: ")
				scanf(" %i", &courseId);
				getchar();
				if(((course_id_t)courseId > ENGLISH) || ((course_id_t)courseId < MATH1)){
					print("Invalid course ID, please try again\n")
				}
				else{/*NOTHING*/}
			}while(((course_id_t)courseId > ENGLISH) || ((course_id_t)courseId < MATH1));

			print("[Course Info]\n"
					"Course Name: ")
			studentDisplayCourses((course_id_t)courseId);
			for(counter1 = 0; counter1 < student.count; counter1++){
				for(counter2 = 0; counter2 < tempStudent->courseCount; counter2++){
					if((course_id_t)courseId == tempStudent->cId[counter2]){
						studentCount++;
						print("%ist Student:\n", studentCount)
						studentDisplayInfos(tempStudent);
						returnFlag = E_SUCCESS;
					}
				}
				tempStudent = repositionPointer(tempStudent, FORWARD);
			}
	}

	if(E_FAILED == returnFlag){
		print("No one is registered in this course\n")
	}
	else{/*NOTHING*/}
	return returnFlag;
}

func_status_t studentDelete(){
	func_status_t returnFlag = E_SUCCESS;
	roll_status_t rollState  = ROLL_REGISTERED;
	int roll, counter = 0;
	storage_status_t storageState = storageStatus();
	student_infos_t* tempStudent = NULL;
	switch(storageState){
		case EMPTY:
			print("The list is already empty")
			returnFlag = E_SUCCESS;
			break;
		case FULL:
		case NEITHER_FULL_NOR_EMPTY:
		default:
			tempStudent = student.tail;
			print("Enter roll number for student to be deleted: ")
			scanf(" %i", &roll);
			getchar();
			rollState = rollStatus(roll, &tempStudent);
			if(ROLL_REGISTERED == rollState){
				if(student.count == 1){
					student.top  = student.base;
					student.tail = student.base;
				}
				else{
					if(position == (student.count-1))
						student.top = repositionPointer(student.top, BACKWARD);
					else if(position == 0)
						student.tail = repositionPointer(student.tail, FORWARD);
					else if((float)position > ((float)student.count/2)){
						for(counter = 0; counter < (student.count - position - 1); counter++){
							*tempStudent = *repositionPointer(tempStudent, FORWARD);
							tempStudent  = repositionPointer(tempStudent, FORWARD);
						}
						student.top = repositionPointer(student.top, BACKWARD);
					}
					else{
						for(counter = 0; counter < position; counter++){
							*tempStudent = *repositionPointer(tempStudent, BACKWARD);
							tempStudent  = repositionPointer(tempStudent, BACKWARD);
						}
						student.tail = repositionPointer(student.tail, FORWARD);
					}
				}
				printf("Student has been deleted properly.\n");
				student.count--;
				studentFindNum();
			}
			else{
				print("Entered roll is invalid, no one to be deleted\n")
				returnFlag = E_FAILED;
			}
	}


	return returnFlag;
}


func_status_t studentUpdate(){
	func_status_t returnFlag = E_SUCCESS;
	storage_status_t storageState = storageStatus();
	student_infos_t* tempStudent = NULL;
	roll_status_t rollState = ROLL_REGISTERED;
	int roll, counter = 0;
	int choice;

	switch(storageState){
		case EMPTY:
			print("The list is already empty")
			returnFlag   = E_FAILED;
			break;
		case FULL:
		case NEITHER_FULL_NOR_EMPTY:
		default:
			do{
				print("Enter student' roll number, to be updated: ")
				scanf(" %i", &roll);
				getchar();
				rollState = rollStatus(roll, &tempStudent);

				if(ROLL_REGISTERED == rollState){
					print("Please enter your choice:-\n"
							"1. Update student's roll\n"
							"2. Update student's first name\n"
							"3. Update student's last name\n"
							"4. Update student's GPA\n"
							"5. Update student's courses\n")
					print("Enter your choice: ")
					scanf(" %i", &choice);
					getchar();

					switch(choice){
						case 1:
							print("Enter the new roll number: ")
							scanf(" %i", &roll);
							getchar();
							rollState = rollStatus(roll, &tempStudent);
							if(ROLL_REGISTERED == rollState){
								returnFlag = E_FAILED;
								print("[This roll is already registered with another student]")
							}
							else{
								tempStudent->roll = roll;
								printf("Student's roll has been updated properly.\n");
							}
							break;
						case 2:
							print("Enter the new first name")
							studentGetString(tempStudent->fName, sizeof(tempStudent->fName));
							break;
						case 3:
							print("Enter the new last name")
							studentGetString(tempStudent->lName, sizeof(tempStudent->lName));
							break;
						case 4:
							print("Enter the new GPA")
							studentAddGpa(tempStudent);
							break;
						case 5:
							print("Please enter your choice:-\n"
									"1. Add new course\n"
									"2. Delete a course\n")
							print("Enter your choice: ")
							scanf(" %i", &choice);
							switch(choice){
								case 1:
									studentAddCourses(tempStudent);
									break;
								case 2:
									if(1 == tempStudent->courseCount){
										print("There is only one registered course and"
												"it must be at least one registered course,\n"
												"so you can't delete it.\n")
									}
									else{
										print("[Student registered Courses]\n")
										for(counter = 0; counter < tempStudent->courseCount; counter++ ){
											print("%i.\t→ID: %i\t", (counter + 1), tempStudent->cId[counter])
											studentDisplayCourses(tempStudent->cId[counter]);
										}
										print("Enter the course to be deleted: ")
										scanf(" %i", &choice);
										getchar();
										if((choice > 0) && (choice <= tempStudent->courseCount)){
											while(choice < tempStudent->courseCount){
												tempStudent->cId[(int)(choice - 1)] = tempStudent->cId[(int)choice];
												choice++;
											}
											tempStudent->courseCount--;
											print("The course has been deleted properly\n"
													"[Current student registered Courses]\n")
											for(counter = 0; counter < tempStudent->courseCount; counter++ ){
												print("%i.\t→ID: %i\t", (counter + 1), tempStudent->cId[counter])
												studentDisplayCourses(tempStudent->cId[counter]);
											}
										}
										else{
											print("Invalid choice")
										}
									}
									break;
								default:
									print("Invalid choice")
									break;
							}
							break;
						default:
							print("Invalid choice")
							break;
					}
				}
				else{
					print("Entered roll number is wrong")
					returnFlag   = E_FAILED;
				}
				print("Enter Y if you want to perform another update, and other char if no: ")
				scanf(" %c", (char *)&choice);
				getchar();
			}while(('y' == (char)choice) || ('Y' == (char)choice));

	}
	return returnFlag;
}
