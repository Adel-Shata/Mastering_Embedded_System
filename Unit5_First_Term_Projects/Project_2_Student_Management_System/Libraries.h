/*
 * Libraries.h
 *
 *  Created on: 21 Aug 2026
 *      Author: Adel Shata
 */

#ifndef LIBRARIES_H_
#define LIBRARIES_H_

/*Section: Include*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Section: Macro Functions*/

#define print(...)	printf(__VA_ARGS__);\
					fflush(stdin);\
					fflush(stdout);

#endif /* LIBRARIES_H_ */
