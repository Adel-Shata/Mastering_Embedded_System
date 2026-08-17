/*
 * CA.h
 *
 *  Created on: 17 Aug 2026
 *      Author: Adel Shata
 */

#ifndef CA_H_
#define CA_H_

#include "US.h"
#include "DC_Motor.h"

#define DISTANCE_THRESHOLD 50

void collisionAvoidanceSetup();
void collisionAvoidance();

#endif /* CA_H_ */
