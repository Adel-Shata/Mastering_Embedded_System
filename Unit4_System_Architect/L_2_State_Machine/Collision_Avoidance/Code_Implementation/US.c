/*
 * US.c
 *
 *  Created on: 17 Aug 2026
 *      Author: Adel Shata
 */

#include "US.h"

unsigned int static distance = 0;

int static generateRandom( int  mini, int max, int count ){
	unsigned int i;
	int randomNum;
	for( i = 0; i < count; i++ ){
		randomNum = ( rand() % ( max - mini + 1 ) ) + mini;
	}

	return randomNum;
}

void usInit(){
	printf( "Initializing Ultrasonic\n" );
}

unsigned int usGetDistance(){
	distance =  generateRandom( 45, 55, 1 );
	printf( "Distance = %d\n", distance );
	return distance;
};
