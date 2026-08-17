/*
 * CA.c
 *
 *  Created on: 17 Aug 2026
 *      Author: Adel Shata
 */

#include "CA.h"

unsigned int static speed    = 0;
unsigned int static distance = 0;

void collisionAvoidanceSetup(){
	usInit();
	dcMotorInit();
}

void collisionAvoidance(){
	distance = usGetDistance();

	if( 50 > distance )
		speed = 30;
	else
		speed = 0;

	dcMotorSetSpeed( speed );
}
