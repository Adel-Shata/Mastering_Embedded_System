/*
 ============================================================================
 Name        : app.c
 Author      : Adel Shata
 Description : app source file
 ============================================================================
 */
#include "Platform_Types.h"
#include "uart.h"

uint8 string[100] = "Adel is the best embedded engineer";
/***Tseting***
uint32 Put4BytesInBss;                      // put 4 bytes in .bss
uint32 const MakeRodataSection = 0;         // Add the .rodata section
//*/
void WeStartHere_NotFromMain(){
    Uart_Send_String(string);
}