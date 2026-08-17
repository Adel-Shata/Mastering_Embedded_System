/*
 * DC_Motor.c
 *
 *  Created on: 17 Aug 2026
 *      Author: Adel Shata
 */

#include "DC_Motor.h"

unsigned int static speed = 0;

void dcMotorInit(){
	printf( "Initializing DC Motor \n" );
}

void dcMotorSetSpeed( unsigned int newSpeed ){
	speed = newSpeed;
	printf( "Speed = %d\n", speed );
}
