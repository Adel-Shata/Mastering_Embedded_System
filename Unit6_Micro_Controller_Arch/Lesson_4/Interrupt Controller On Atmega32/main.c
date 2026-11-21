/*
 * main.c
 *
 *  Created on: 20 Nov 2026
 *      Author: Adel Shata
 */
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define PORTB *(volatile uint8_t *)(0x38)
#define DDRB  *(volatile uint8_t *)(0x37)
#define PINB  *(volatile uint8_t *)(0x36)
#define PORTD *(volatile uint8_t *)(0x32)
#define DDRD  *(volatile uint8_t *)(0x31)
#define PIND  *(volatile uint8_t *)(0x30)
#define MCUCR *(volatile uint8_t *)(0x55)
#define MCUCSR *(volatile uint8_t *)(0x54)
#define GICR  *(volatile uint8_t *)(0x5B)
#define GIFR  *(volatile uint8_t *)(0x5A)
#define SREG  *(volatile uint8_t *)(0x5F)


void gpioInit(){
	DDRD |= (1 << 0);
}
void interruptInit(){
	MCUCR  |= (0x7 << 0);
	MCUCSR &= ~(1 << 6);
	SREG   |= (1 << 7);
	GICR   |= (0x7 << 5);
}

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

void __vector_1(void)
{
    PORTD ^= (1 << 0);
}

void __vector_2(void)
{
    PORTD ^= (1 << 0);
}

void __vector_3(void)
{
    PORTD ^= (1 << 0);
}

int main(){
	gpioInit();
	interruptInit();

	while(1){

	}
	return 0;
}

