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

#define RCC_BASE		 0x40021000
#define GPIOA_BASE		 0x40010800

#define RCC_APB2ENR	 *(vuint32 *)(RCC_BASE + 0x18)
#define GPIOA_CHR	 *(vuint32 *)(GPIOA_BASE + 0x04)

// bit field

typedef union
{
	vuint32 all_fields;
	struct
	{
		vuint32	reserved: 13;
		vuint32	P13: 1;
	} pin;

} R_ODR_t;

#define R_ODR ((volatile R_ODR_t *)(GPIOA_BASE + 0x0C))

uint8 g_vars[3] = {1, 2, 3};
uint8 const g_const_vars[3] = {4, 5, 6};


int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CHR &= 0xff0fffff;
	GPIOA_CHR |= 0x00200000;

    /* Loop forever */
	while(1)
	{
		R_ODR->pin.P13= 1;
		for(uint16 i = 0; i < 10000; i++); // arbitrary delay
		R_ODR->pin.P13= 0;
		for(uint16 i = 0; i < 10000; i++); // arbitrary delay
	}
	return 0;
}