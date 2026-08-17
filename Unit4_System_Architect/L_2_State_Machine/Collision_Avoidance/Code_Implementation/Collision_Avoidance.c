/*
 ============================================================================
 Name        : Collision_Avoidance.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "CA.h"

void setup ();

int main(void) {

	int delay = 0;
	setup ();

	while( 1 ){
		collisionAvoidance();
		for( delay = 0; delay < 100000; delay++ );
	}

	return EXIT_SUCCESS;
}

void setup (){
	collisionAvoidanceSetup();
}
