/*
 * LIFO.h
 *
 *  Created on: 27 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LIFO_H_
#define LIFO_H_

/*Section: Includes*/
#include "Project_Config.h"
#include <stdio.h>
/*Section: Macros*/
/*Section: Macro Functions*/
/*Section: User Defined Data types*/

typedef enum {
	STACK_EMPTY = 0,
	STACK_FULL,
	STACK_NEITHER_FULL_NOR_EMPTY,
	STACK_ERROR
}stack_status_t;

// The type of the stack elements, so you can configure it as you wish
typedef struct{
	int x, y;
}stack_node;

typedef struct{
	stack_node *data;
	int top;
	unsigned int count;
	unsigned int size;
}stack_t;

/*Section: Function Declarations*/

// Getting the status of the stack, whether it is full or empty or neither of them.
stack_status_t stackStatus(stack_t *stack);

// Initializing the stack
func_status_t stackInit(stack_t *stack, stack_node *stackList , unsigned int size);

// Inserting new element in the stack
func_status_t stackPush(stack_t *stack, stack_node insertedElem);

// Getting an element from the stack
func_status_t stackPop(stack_t *stack, stack_node  *poppedElem);

#endif /* LIFO_H_ */
