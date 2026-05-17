/*Author : Eng. Adel Shata*/
ENTRY(reset)

MEMORY
{
    Mem(rwx) :ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{
    . = 0x00010000 ;
    .startup . :
    {
        startup.o(.text)
    }> Mem

    .text :
    {
        *(.text)
        *(.rodata)
    }> Mem

    .data :
    {
        *(.data)
    }> Mem

    .bss :
    {
        *(.bss)
        *(.COMMON)
    }> Mem

    . = . + 0x00001000 ;
    stack_top = . ;
}