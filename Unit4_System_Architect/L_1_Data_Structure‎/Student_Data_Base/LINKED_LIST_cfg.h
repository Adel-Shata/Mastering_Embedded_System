/*
 * LINKED_LIST_cfg.h
 *
 *  Created on: 9 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LINKED_LIST_CFG_H_
#define LINKED_LIST_CFG_H_

/*
 * choose the data type of the buffer whether (unsigned/signed int)
 * , (unsigned/signed float), (unsigned/signed short) or (unsigned/signed char) ...etc.
 */

typedef struct{
	char           name[50];
	unsigned int   id;
	unsigned short height;
}student_data_t;

#define Element_DataType student_data_t


#endif /* LINKED_LIST_CFG_H_ */
