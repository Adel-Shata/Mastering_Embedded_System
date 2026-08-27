/*
 * LIFO.c
 *
 *  Created on: 27 Aug 2026
 *      Author: Adel Shata
 */

#include "LIFO.h"


/*Primary functions ↓↓↓*/

stack_status_t stackStatus(stack_t *stack){
	stack_status_t returnFlag = STACK_NEITHER_FULL_NOR_EMPTY;
	if(NULL == stack){
		returnFlag = STACK_ERROR;
	}
	// The fist condition (stack->count == 0) will be true but I have added the remain conditions just for safety
	else if((stack->count == 0) ||(-1 == stack->top)){
		returnFlag = STACK_EMPTY;
	}
	else if(stack->size == stack->count){
		returnFlag = STACK_FULL;
	}
	else{/*NOTHING*/}

	return returnFlag;
}

func_status_t stackInit(stack_t *stack, stack_node *stackList , unsigned int size){

	func_status_t returnFlag = E_SUCCESS;

	// Checking if stack and stackList is valid or not
	if((NULL == stack) || (NULL == stackList) || (0 == size))
		returnFlag = E_FAILURE;
	else{
		stack->data  = stackList;
		stack->size  = size;
		stack->count = (unsigned int)STACK_EMPTY;
		stack->top   = -1;
	}

	return returnFlag;
}

func_status_t stackPush(stack_t *stack, stack_node insertedElem){

	func_status_t returnFlag = E_SUCCESS;

	// Checking if stack is valid or not
	if((NULL == stack))
		returnFlag = E_FAILURE;
	else{
		switch(stackStatus(stack)){
			case STACK_FULL:
			case STACK_ERROR:
				returnFlag = E_FAILURE;
				break;
			case STACK_EMPTY:
			case STACK_NEITHER_FULL_NOR_EMPTY:
				stack->top++;
				stack->data[stack->top] = insertedElem;
				stack->count++;
				break;
			default:
				returnFlag = E_FAILURE;
				break;
		}
	}

	return returnFlag;
}

func_status_t stackPop(stack_t *stack, stack_node  *poppedElem){

	func_status_t returnFlag = E_SUCCESS;

	// Checking if stack is valid or not
	if((NULL == stack) || (NULL == poppedElem))
		returnFlag = E_FAILURE;
	else{
		switch(stackStatus(stack)){
			case STACK_EMPTY:
			case STACK_ERROR:
				returnFlag = E_FAILURE;
				break;
			case STACK_FULL:
			case STACK_NEITHER_FULL_NOR_EMPTY:
				*poppedElem = stack->data[stack->top];
				stack->top --;
				stack->count--;
			break;
			default:
				returnFlag = E_FAILURE;
				break;

		}
	}
	return returnFlag;
}
