/*
 * LINKED_LIST.h
 *
 *  Created on: 9 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "LINKED_LIST_cfg.h"
#include "LINKED_LIST.h"

struct NODE{
	Element_DataType NodeData;
	struct NODE *NodeNext;
};


typedef enum {
	succeeded,
	failed
}LIST_Status_t;

//Primary Functions ↓↓↓

//Insert new Item in the list
LIST_Status_t LIST_Insert(struct NODE **List, Element_DataType Item);

//Deleting a certain element
LIST_Status_t LIST_CDelete(struct NODE **List, unsigned int ItemIndex);

//Deleting all the list's Items
LIST_Status_t LIST_DeleteAll(struct NODE **List);

//Getting the item's data in the list of the desired index
LIST_Status_t LIST_GetNth(struct NODE *CurrentNode, Element_DataType *Item, unsigned int  ItemIndex);

//Getting the item's data in the list of the desired index from end of the List.
LIST_Status_t LIST_GetNth_FromEnd(struct NODE *CurrentNode, Element_DataType *Item, unsigned int  ItemIndex);

//Finding the length of the list iteratively
unsigned int LIST_Length(struct NODE *List);

//Finding the length of the list recursively
unsigned int LIST_Length_Recursive(struct NODE *List);

//Getting the middle item's data in the list
LIST_Status_t LIST_GetMth(struct NODE *CurrentNode, Element_DataType *Item);

//Getting the middle item's data in the list using Reference pointer
LIST_Status_t LIST_GetMth_Ref(struct NODE *CurrentNode, Element_DataType *Item);

//Reversing the list
LIST_Status_t LIST_Reverse(struct NODE **Head);
#endif /* LINKED_LIST_H_ */
