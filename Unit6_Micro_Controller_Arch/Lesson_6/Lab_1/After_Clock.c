/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Adel Shata
 * @brief          : Main program body
 ******************************************************************************
 **/

#include <stdint.h>

#define GPIOA_BASE 0x40010800
#define GPIOA_CRH  *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR  *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE      0x40021000
#define RCC_APB2ENR   *(volatile uint32_t *)(RCC_BASE + 0x18)

int main(void)
{
	/*Enable IO Port A Clock*/
	RCC_APB2ENR |= (1 << 2);
    /*Setting the direction of the pin to be output*/
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= (0x2 << 20);
	/* Loop forever */
	for(;;){
		GPIOA_ODR ^= (1 << 13);
		for (int i = 0; i < 5000; i++);
		GPIOA_ODR ^= (1 << 13);
		for (int i = 0; i < 5000; i++);
	}
}
