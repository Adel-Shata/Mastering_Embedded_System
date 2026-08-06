/*
 * LIFO.h
 *
 *  Created on: 6 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "BUF_Config.h"


typedef struct {
	int length;
	Element_DataType *top;
	Element_DataType *base;
	int count;
}LIFO_BUF_t;


typedef enum {
	succeeded,
	failed,
	empty,
	full,
	neither_full_nor_enmpty
}BUF_Status_t;

/*
 * Make macro function, named print, to give me the feature
 * to use printf() properly in Eclipse.
 */
#define print(...) 	printf(__VA_ARGS__);\
					fflush(stdin);\
					fflush(stdout);

// Primary functions ↓↓↓

// initializes your buffer
BUF_Status_t LIFO_Init(LIFO_BUF_t *urBuffer, Element_DataType *urArray, int arrayLength);

// Pushes an element to your buffer
BUF_Status_t LIFO_Push(LIFO_BUF_t *urBuffer, Element_DataType urItem);

// Pops an element from your buffer
BUF_Status_t LIFO_Pop(LIFO_BUF_t *urBuffer, Element_DataType *popedItem);

// Displays all of the buffer's elements
void LIFO_Display(LIFO_BUF_t *urBuffer);




#endif /* LIFO_H_ */
