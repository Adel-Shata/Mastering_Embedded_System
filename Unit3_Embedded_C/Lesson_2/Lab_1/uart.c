/*
 ============================================================================
 Name        : uart.c
 Author      : Adel Shata
 Description : Uart source file
 ============================================================================
 */

#include "Platform_Types.h"

#define UART0DR *(vuint32_t* const)((void*)0x101f1000) // we are defining Uart 0 in VersatilePB board

void Uart_Send_String(uint8* P_tx_string){
    while(*P_tx_string != '\0') // we are sending the string byte by byte
        UART0DR = (uint32)(*P_tx_string++) ;
}