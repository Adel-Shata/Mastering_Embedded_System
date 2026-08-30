#include "driver/driver.h"
#include <stdint.h>
#include <stdio.h>

void delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}

void setAlarmActuator(int i){
	if (i == 0){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 1){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void gpioInit(){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
