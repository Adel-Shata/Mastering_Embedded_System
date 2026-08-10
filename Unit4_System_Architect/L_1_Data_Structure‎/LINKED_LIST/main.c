/*
 ============================================================================
 Name        : main.c
 Author      : Adel Shata
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LINKED_LIST.h"

#define print(...) 	printf(__VA_ARGS__);\
					fflush(stdin);\
					fflush(stdout);


	void PrintList(struct NODE const *List)
	{
	    struct NODE const *TempNode = List;

	    print("List: ")
	    if(TempNode){
		    while (TempNode)
		    {
		        print("%d", TempNode->NodeData)

		        if (NULL != TempNode->NodeNext){
		        	print(" -> ")
		        }

		        TempNode = TempNode->NodeNext;
		    }
	    }
	    else{
	    	print("Empty")
	    }

	    print("\n")
	}

	int main(void)
	{
	    struct NODE *List = NULL;
	    Element_DataType Item;
	    unsigned int length;

	    /* Insert 5 elements */
	    LIST_Insert(&List, 10);
	    LIST_Insert(&List, 20);
	    LIST_Insert(&List, 30);
	    LIST_Insert(&List, 40);
	    LIST_Insert(&List, 50);

	    PrintList(List);

	    /*Reversing the node*/
	    LIST_Reverse( &List );
	    PrintList(List);

	    /* Getting the middle element */
	    LIST_GetMth( List, &Item );
	    print("\nThe middle elements = %d\n", Item)

	    /* Getting the middle element using reference pointer */
	    LIST_GetMth_Ref( List, &Item );
	    print("\nThe middle elements (REF) = %d\n", Item)

	    /*Getting the Length of the list recursively*/
	    length = LIST_Length_Recursive(List);
		print("\nLength(recursively) = %d\n", length)

	    /* Delete first element */
	    print("\nDeleting first element...\n")

	    LIST_CDelete(&List, 0);

	    PrintList(List);

	    /* Delete last element */
	    print("\nDeleting last element...\n")

	    LIST_CDelete(&List, 3);

	    PrintList(List);

	    /* Delete middle element */
	    print("\nDeleting middle element...\n")

	    LIST_CDelete(&List, 1);

	    PrintList(List);

	    /*Getting the Length of the list iteratively*/
	    length = LIST_Length(List);
		print("\nLength = %d\n", length)

	    /* Insert 2 more elements */
	    print("\nInserting middle element...\n")

	    LIST_Insert(&List, 60);
	    LIST_Insert(&List, 70);

	    PrintList(List);

	    /* Getting the middle element */
	    LIST_GetMth( List, &Item );
	    print("\nThe middle elements = %d\n", Item)

	    /* Getting the middle element using reference pointer */
	    LIST_GetMth_Ref( List, &Item );
	    print("\nThe middle elements (REF) = %d\n", Item)

	    /* the length of the list iteratively */
	    LIST_GetNth( List, &Item , 0 );
	    print("\nElement with index 0 = %d\n", Item)

	    /* Getting the Item with index inversely = 0 more elements */
	    LIST_GetNth_FromEnd( List, &Item , 0 );
	    print("\nElement with index (inversely) 0 = %d\n", Item)

	    /* Getting the Item with index = 4  more elements */
	    LIST_GetNth( List, &Item , 3 );
	    print("\nElement with index 4 = %d\n", Item)

	    /* Getting the Item with index inversely = 4 more elements */
	    LIST_GetNth_FromEnd( List, &Item , 4 );
	    print("\nElement with index (inversely) 4 = %d\n", Item)

	    /* Getting the Item with index = 1 more elements */
	    LIST_GetNth( List, &Item , 1 );
	    print("\nElement with index 1 = %d\n", Item)

	    /* Getting the Item with index inversely = 1 more elements */
	    LIST_GetNth_FromEnd( List, &Item , 1 );
	    print("\nElement with index (inversely) 1 = %d\n", Item)

	    /* Delete all of the elements */
	    print("\nDelete all of the elements...\n")

	    LIST_DeleteAll(&List);

	    PrintList(List);

	    return EXIT_SUCCESS;
	}
