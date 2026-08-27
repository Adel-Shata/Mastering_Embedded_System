/*
 * FIFO.h
 *
 *  Created on: 7 Aug 2026
 *      Author: Adel Shata
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "BUF_Config.h"


typedef struct {
	int length;
	Element_DataType *top;
	Element_DataType *base;
	Element_DataType *tail;
	int count;
}FIFO_BUF_t;


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
BUF_Status_t FIFO_Init(FIFO_BUF_t *urBuffer, Element_DataType *urArray, int arrayLength);

// Pushes an element to your buffer
BUF_Status_t FIFO_Enqueue(FIFO_BUF_t *urBuffer, Element_DataType urItem);

// Pops an element from your buffer
BUF_Status_t FIFO_Dequeue(FIFO_BUF_t *urBuffer, Element_DataType *popedItem);

// Clearing all of the elements within the buffer
BUF_Status_t FIFO_Clear(FIFO_BUF_t *urBuffer);

// Displays all of the buffer's elements
void FIFO_Display(FIFO_BUF_t *urBuffer);



#endif /* FIFO_H_ */
