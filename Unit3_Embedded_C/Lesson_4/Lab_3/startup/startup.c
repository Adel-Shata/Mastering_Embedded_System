#include "Platform_Types.h"

extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

extern int main(void);

static vuint32 stack [256] = {0};

#define Reserved (uint32)0

void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void MemoryManagement_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Reset_Handler")));
void ExternalInterruptsHandler(void) __attribute__((weak, alias("Reset_Handler")));

// initialize the vector table in flash memory
void (* (vectors[]) ) () __attribute__((section(".vectors")))  = {
    (void(*)())((uint32)stack + sizeof(stack)),
    &Reset_Handler,
    &NMI_Handler,
    &HardFault_Handler,
    &MemoryManagement_Handler,
    &BusFault_Handler,
    &UsageFault_Handler,
    (void(*)()) Reserved,
    (void(*)()) Reserved,
    (void(*)()) Reserved,
    (void(*)()) Reserved,
    &SVC_Handler,
    (void(*)()) Reserved,
    (void(*)()) Reserved,
    &PendSV_Handler,
    &SysTick_Handler,
    &ExternalInterruptsHandler
};


void Reset_Handler(void)
{
    void *src = NULL;
    void *dst = NULL;

    // Reallocate the .data section from flash to SRAM
    dst = (uint32 *)(&_S_data);
    src = (uint32 *)(&_E_text);
    uint32 _data_size = (uint32 *)(&_E_data) - (uint32 *)(&_S_data);
    for (uint32 i = 0; i < _data_size; i++){
        *((uint32 *)dst++) = *((uint32 *)src++);
    }

    // allocate the .data section in SRAM
    dst = (uint32 *)(&_S_bss);
    uint32 _bss_size = (uint32 *)(&_E_bss) - (uint32 *)(&_S_bss);
    for (uint32 i = 0; i < _bss_size; i++){
        *((uint32 *)dst++) = Reserved;
    }

    // branch to main function
    main();
}