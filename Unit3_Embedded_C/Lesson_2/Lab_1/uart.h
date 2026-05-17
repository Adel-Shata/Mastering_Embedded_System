/*
 ============================================================================
 Name        : uart.h
 Author      : Adel Shata
 Description : Uart header file
 ============================================================================
 */
#ifndef _UART_H_
#define _UART_H_

#include "Platform_Types.h"

void Uart_Send_String(uint8* P_tx_string); // Function to write at Uart 0 in VersatilePB board

#endif