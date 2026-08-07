/*
 * LIFO.c
 *  Created on: 6 Aug 2026
 *  Author: Adel Shata
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

// Helper functions ↓↓↓

// Tells the status of the buffer's storage
BUF_Status_t static Storage_Status(LIFO_BUF_t *urBuffer){
	BUF_Status_t returnFlag = neither_full_nor_empty;

	//Checking the status
	if(0 == urBuffer->count)
		returnFlag = empty;
	else if(urBuffer->count == urBuffer->length)
		returnFlag = full;
	else{/*do nothing*/}

	return returnFlag;
}

// Primary functions ↓↓↓

// initializing your buffer
BUF_Status_t LIFO_Init(LIFO_BUF_t *urBuffer, Element_DataType *urArray, int arrayLength){
	BUF_Status_t returnFlag = succeeded;

	// Checking if the passed buffer, array is existed, additionally if array's length is not 0 , so we can initialize the buffer.
	if((NULL == urBuffer) || (NULL == urArray) || (0 == arrayLength))
		returnFlag = failed;
	else{
		// Initializing the buffer
		urBuffer->count  = 0;
		urBuffer->length = arrayLength;
		urBuffer->base   = urArray;
		urBuffer->top    = urArray;
	}
	return returnFlag;
}

// Pushes an element to your buffer
BUF_Status_t LIFO_Push(LIFO_BUF_t *urBuffer, Element_DataType urItem){
	BUF_Status_t returnFlag = succeeded;

	// Checking if the passed buffer is existed, so we can push properly the passed element in.
	if(NULL == urBuffer)
		returnFlag = failed;

	// Checking if the passed buffer is not full, so we can push properly the passed element in.
	else if(full == Storage_Status((LIFO_BUF_t *)urBuffer))
		returnFlag = full;

	else{
			if(empty == Storage_Status((LIFO_BUF_t *)urBuffer))
				*(urBuffer->top) = urItem;
			else
				*++(urBuffer->top) = urItem;
			(urBuffer->count)++;
	}
	return returnFlag;
}

// Pops an element from your buffer
BUF_Status_t LIFO_Pop(LIFO_BUF_t *urBuffer, Element_DataType *popedItem){
	BUF_Status_t returnFlag = succeeded;

	// Checking if the passed buffer and popedItem address is existed, so we can push properly the passed element in.
	if(NULL == urBuffer || NULL == popedItem)
		returnFlag = failed;

	// Checking if the passed buffer is not empty, so we can pop properly the desired element.
	else if(empty == Storage_Status((LIFO_BUF_t *)urBuffer))
		returnFlag = empty;

	else{
		*popedItem = *((urBuffer->top)--);
		(urBuffer->count)--;
	}
	return returnFlag;
}

// Clearing all of the elements within the buffer
BUF_Status_t LIFO_Clear(LIFO_BUF_t *urBuffer){
	BUF_Status_t returnFlag = succeeded;

	// Checking if the passed buffer is existed.
	if(NULL == urBuffer)
		returnFlag = failed;

	// Checking if the passed buffer is not empty, so we can clear the buffer properly.
	else if(empty == Storage_Status((LIFO_BUF_t *)urBuffer))
		returnFlag = empty;
	else{
		urBuffer->top = urBuffer->base;
		urBuffer->count  = 0;
	}
	return returnFlag;
}

// Displays all of the buffer's elements
void LIFO_Display(LIFO_BUF_t *urBuffer){
	int counter = 0;
	Element_DataType *tempBase = urBuffer->base;
	// Checking if the passed buffer is existed, so we can push properly the passed element in.
	if(NULL == urBuffer){
		print("***************\nYou have entered nonexistent argument\n***************\n")
	}

	// Checking if the passed buffer is not empty, so we can display the buffer properly.
	else if(empty == Storage_Status((LIFO_BUF_t *)urBuffer)){
		print("***************\nThe buffer is empty\n***************\n");
	}
	else{
		print("=====================\n")
		for(counter = 0; counter < (urBuffer->count); counter++){
			print("%dSt Element = %d\n", counter+1, *tempBase++)
		}
		print("=====================\n")
	}
}
