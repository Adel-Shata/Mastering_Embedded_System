/*
 * LINKED_LIST.c
 *
 *  Created on: 9 Aug 2026
 *      Author: Adel Shata
 */

#include <stdio.h>
#include <stdlib.h>
#include "LINKED_LIST.h"

/*
 * Primary Functions ↓↓↓
 */

//Finding the length of the list iteratively
unsigned int LIST_Length(struct NODE *List){
    unsigned int NodeCount = 0;

    while(List != NULL){
        NodeCount++;
        List = List->NodeNext;
    }

    return NodeCount;
}

//Finding the length of the list recursively
unsigned int LIST_Length_Recursive(struct NODE *List){

	if( List )
		return ( 1 + LIST_Length_Recursive( (List)->NodeNext ) );
	else
		return 0;
}

// Insert new Item in the list
LIST_Status_t LIST_Insert(struct NODE **List, Element_DataType Item){
	LIST_Status_t returnFlag    = succeeded;
	struct NODE *CurrentNode    = NULL;
	struct NODE *TempNode       = NULL; //Node to be inserted
	TempNode 					= (struct NODE *)calloc(1, sizeof(struct NODE));

	// Checking if the calloc function has worked properly
	if( TempNode ){
		TempNode->NodeData = Item;
		TempNode->NodeNext = NULL;

		// checking if the List is not empty
		if( (*List) ){
			CurrentNode = *List;
			//Getting the last valid node
			while( NULL != CurrentNode->NodeNext )
				CurrentNode = CurrentNode->NodeNext;
			CurrentNode->NodeNext = TempNode;
		}
		else
			*List = TempNode;
	}
	else
		returnFlag = failed;

	return returnFlag;
}

// Deleting a certain element
LIST_Status_t LIST_CDelete(struct NODE **List, unsigned int ItemIndex){
	LIST_Status_t returnFlag    = succeeded;
	struct NODE *CurrentNode    = NULL;
	struct NODE *TempNode       = NULL; //Node to be deleted
	unsigned int counter		= 0;
	unsigned int ListLength     = LIST_Length(*List);

	//Checking if the list element is not empty, and the Index is valid
	if( (*List) && (ListLength > ItemIndex) ){
		CurrentNode = *List;

		//ٌReaching the previous Item of the desired one
		for( counter = 0 ; (signed int)counter < ( (signed int)ItemIndex - 1) ; counter++ )
			CurrentNode = CurrentNode->NodeNext;

		// Checking that the element is not Zero
		if (ItemIndex){
			TempNode = CurrentNode->NodeNext;
			CurrentNode->NodeNext = CurrentNode->NodeNext->NodeNext;
			free(TempNode);
			TempNode = NULL;
		}
		else{
			*List = (*List)->NodeNext;
			free(CurrentNode);
			CurrentNode = NULL;
		}
	}
	else
		returnFlag = failed;

	return returnFlag;
}


// Deleting All the List's items
LIST_Status_t LIST_DeleteAll(struct NODE **List){
	LIST_Status_t returnFlag    = succeeded;
	struct NODE *TempNode       = NULL; //Node to be deleted

	//Checking that this list is not empty
	if( *List ){

		//Looping to check that the Current Node valid
		while( (*List) ){
			TempNode    = *List;
			*List = (*List)->NodeNext;
			free(TempNode);
			TempNode = NULL;
		}
	}
	else
		returnFlag = failed;

	return returnFlag;
}

//Getting the item's data in the list of the desired index
LIST_Status_t LIST_GetNth(struct NODE *CurrentNode, Element_DataType *Item, unsigned int  ItemIndex){
	LIST_Status_t returnFlag    = succeeded;
	unsigned int ListLength     = LIST_Length(CurrentNode);
	unsigned int counter		= 0;

	//Checking if the list element is not empty, and the Index is valid
	if( (CurrentNode) && (Item) && (ListLength > ItemIndex) ){
		//ٌReaching the desired Item
		for( counter = 0 ; counter <  ItemIndex ; counter++ )
			CurrentNode = CurrentNode->NodeNext;
		*Item = CurrentNode->NodeData;
	}
	else{
		returnFlag    = failed;
		*Item = 0;
	}

	return returnFlag;
}

//Getting the item's data in the list of the desired index from end of the List.
LIST_Status_t LIST_GetNth_FromEnd(struct NODE *CurrentNode, Element_DataType *Item, unsigned int  ItemIndex){
	unsigned int ListLength     = LIST_Length(CurrentNode);
	return LIST_GetNth( CurrentNode , Item , (ListLength - ItemIndex - 1) );
}

//Getting the middle item's data in the list
LIST_Status_t LIST_GetMth(struct NODE *CurrentNode, Element_DataType *Item){
	unsigned int MiddleIndex     = (unsigned int)(LIST_Length(CurrentNode)/2);
	return LIST_GetNth( CurrentNode , Item , MiddleIndex );
}

//Getting the middle item's data in the list using two pointers: slow pointer and fast(Reference) pointer
LIST_Status_t LIST_GetMth_Ref(struct NODE *CurrentNode, Element_DataType *Item){
	LIST_Status_t returnFlag    = succeeded;
	struct NODE *RefNode        = NULL;
	if( CurrentNode && Item ){

		RefNode = CurrentNode;
		//Iterating to reach the middle node in (CurrentNode)
		while( RefNode && RefNode->NodeNext ){
			RefNode     = RefNode->NodeNext->NodeNext;
			CurrentNode = CurrentNode->NodeNext;
		}
		*Item = CurrentNode->NodeData;
	}
	else{
		returnFlag = failed;
	}

	return returnFlag;
}

//Reversing the list
LIST_Status_t LIST_Reverse(struct NODE **Head){
	LIST_Status_t returnFlag    = succeeded;
	struct NODE *PreviousNode   = NULL;
	struct NODE *NextNode       = NULL;
	struct NODE *CurrentNode    = NULL;
	if( (*Head) ){
		CurrentNode = (*Head);
		NextNode    = (*Head)->NodeNext;

		//Reversing the node
		while( NULL != CurrentNode ){
			NextNode    = CurrentNode->NodeNext;
			CurrentNode->NodeNext = PreviousNode;
			PreviousNode          = CurrentNode;
			CurrentNode           = NextNode;
		}
		*Head = PreviousNode;
	}
	else{
		returnFlag = failed;
	}
	return returnFlag;
}
