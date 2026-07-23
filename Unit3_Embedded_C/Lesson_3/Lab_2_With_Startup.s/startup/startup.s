/*startup_CortexM3.s
** Eng.Adel Shata
 */


.section .vectors
    .word 0x20001000          /* Stacktop address */
    .word _reset              /* 1. Reset */
    .word _vector_handler     /* 2. NMI */
    .word _vector_handler     /* 3. Hard Fault */
    .word _vector_handler     /* 4. Memory Management Fault */
    .word _vector_handler     /* 5. Bus Fault */
    .word _vector_handler     /* 6. Usage Fault */
    .word 0x00                /* 7. Reserved */
    .word 0x00                /* 8. Reserved */
    .word 0x00                /* 9. Reserved */
    .word 0x00                /* 10. Reserved */
    .word _vector_handler     /* 11. SVCall */
    .word 0x00                /* 12. Debug Reserved */
    .word 0x00                /* 13. Reserved */
    .word _vector_handler     /* 14. PendSV */
    .word _vector_handler     /* 15. SysTick */
    .word _vector_handler     /* 16. External Interrupts 0 */
    .word _vector_handler     /* 17. External Interrupts 1 */
    .word _vector_handler     /* 18. External Interrupts 2 */
    .word _vector_handler     /* 19. ... */

.section .text
_reset:
    bl main
    b .

.thumb_func

_vector_handler:
    bl _reset