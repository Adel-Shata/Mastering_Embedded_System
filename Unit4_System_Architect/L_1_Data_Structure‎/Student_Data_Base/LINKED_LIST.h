/*
 * LINKED_LIST.h
 *
 *  Created on: 9 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "LINKED_LIST_cfg.h"

struct NODE{
	Element_DataType NodeData;
	struct NODE *NodeNext;
};


typedef enum {
	succeeded,
	failed
}LIST_Status_t;

//Primary Functions ↓↓↓

//Finding the length of the list iteratively
unsigned int LIST_Length(struct NODE *List);

//Insert new Item in the list
LIST_Status_t LIST_Insert(struct NODE **List);

//Deleting a certain element
LIST_Status_t LIST_CDelete(struct NODE **List, unsigned int ItemIndex);

//Deleting all the list's Items
LIST_Status_t LIST_DeleteAll(struct NODE **List);

//Finding the length of the list iteratively
unsigned int LIST_Length(struct NODE *List);

#endif /* LINKED_LIST_H_ */
