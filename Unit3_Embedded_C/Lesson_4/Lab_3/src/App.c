/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Adel Shata
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include "Platform_Types.h"

// register address
#define SYSCTL_RCGC2_R    0X400FE108
#define GPIO_PORTF_BASE   0X40025000



int main(void)
{
	// Enable the GPIO port
	*((vuint32 *)(SYSCTL_RCGC2_R))           = 0X20  ;
	
	// Set (PF3) the direction as output
	*((vuint32 *)(GPIO_PORTF_BASE + 0X3FC)) |= (1<<3);

	// Enable the GPIO pin
	*((vuint32 *)(GPIO_PORTF_BASE + 0X400)) |= (1<<3);
	
	// Toggling the led
	for(uint32 counter = 0 ; counter < 20000 ; counter++);
	*((vuint32 *)(GPIO_PORTF_BASE + 0X400)) ^= (1<<3);
	for(uint32 counter = 0 ; counter < 20000 ; counter++);
	*((vuint32 *)(GPIO_PORTF_BASE + 0X400)) ^= (1<<3);


	return 0;
}