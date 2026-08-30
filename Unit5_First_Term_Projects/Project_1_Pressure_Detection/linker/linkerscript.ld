/*linkerscript.ld
** Eng.Adel Shata
 */

MEMORY
{
    flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
    .text :
    {

        *(.vectors*)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _E_text = .;
    } > flash

    .data :
    {
        _S_data = .;
        *(.data*)
        . = ALIGN(4);
        _E_data = .;
    } > sram AT> flash

    .bss :
    {
        _S_bss = .;
        *(.bss*)
        . = ALIGN(4);
        _E_bss = .;
    } > sram

    _stack_top = . + 1000;
}