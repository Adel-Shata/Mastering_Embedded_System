/*
 ============================================================================
 Name        : LIFO.c
 Author      : Adel Shata
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"


int main(void) {
    int choice;
    BUF_Status_t returnFlag;
    LIFO_BUF_t myBuffer;
    Element_DataType myArr[5], urNewElement;

    //initializing the buffer
    returnFlag = LIFO_Init(&myBuffer, myArr, 5);
    if (succeeded == returnFlag){
    	print("Initializing the buffer has succeeded properly\n"
    		  "=====================\n")
    }
    else{
    	return EXIT_FAILURE;
    }
    do{
        print("=====================\n"
        	  "1. Display the buffer\n2. Push new element\n"
        	  "3. Pop and display an element\n"
        	  "Any_other_number. exit\n"
        	  "=====================\n"
        	  "Please enter your choice: ")
        scanf("%d", &choice);

        print("\n=====================\n")

    	switch(choice){
    		//case 1: Display
    		case 1 :
    			LIFO_Display(&myBuffer);
    			break;
    		//case 2: Enqueue
    		case 2 :
    			print("enter your desired element to be added: ")
				scanf("%d", &urNewElement);

    			// taking and checking the return flag
    			returnFlag = LIFO_Push(&myBuffer, urNewElement);
    			if(failed == returnFlag){
    				print("You have entered nonexistent or invalid arguments\n")
    			}
    			else if(full == returnFlag){
    				print("The buffer is full, it can't endure more elements\n")
    			}
    			else{
    				print("The element equal %d has been added properly\n", urNewElement)
    			}
    			break;
    		//case 2: Dequeue
    		case 3 :
    			// taking and checking the return flag
    			returnFlag = LIFO_Pop(&myBuffer, &urNewElement);
    			if(failed == returnFlag){
    				print("You have entered nonexistent or invalid arguments\n")
    			}
    			else if(empty == returnFlag){
    				print("The buffer is empty, it contains nothing to be popped\n")
    			}
    			else{
    				print("The element equal %d has been popped properly\n", urNewElement)
    			}
    		default :
    			/*It will exit the loop*/
    			break;
    	}
    }while(!(choice < 1 || choice > 3));

	return EXIT_SUCCESS;
}
